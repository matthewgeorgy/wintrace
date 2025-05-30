/*
    Version History

        0.3.1	Cleanups
        0.3.0   All output printing is now done with pipes, ONLY
        0.2.6   Made printing in core & dll a bit nicer
        0.2.5   Explicit /B option for blocking functions to trace
        0.2.4   Naming Opts, Pipe, and Fence with the target PID
        0.2.3   Added a switch /P to use named pipes to print debug output through the EXE instead of the DLL (WIP)
        0.2.2   /? now shows the core and dll version
        0.2.1   Changed help/usage display to look nicer and to accommodate
                wintrace being able to receive program args
        0.2.0   Fixed more CRLF's + added some TODO's
        0.1.9   Added cmdline argument parsing for the target EXE
        0.1.8   Cleanups
        0.1.7   Misc cleanups/fixes + added some comments/documentation
        0.1.6   Added specific tracing
        0.1.5   Cleaned up warnings
        0.1.4   Added custom output file parsing
        0.1.3   Tidied up option parsing and usage printing
        0.1.2   Added plumbing for option/switch parsing
        0.1.1   Added VirtualFreeEx in the remote thread to free DllPath
        0.1.0   Initial creation
*/

// TODO: New features:
/*
    Error / Injection synopsis:

    wintrace /e:HeapCreate ...          Fail ALL HeapCreate calls
    wintrace /e:HeapCreate:4 ...        Fail the 4th HeapCreate call
    wintrace /i:GetFileSize:25 ...      ALL GetFileSize calls return 25
    wintrace /i:GetFileSize:25:3 ...    GetFileSize call #3 returns 25

    wintrace {/i|/e}:HeapAlloc,HeapFree ... Chain multiple funcs??
*/

/*
    Organize nested calls:

    GetMessage(0x0000000000BCF698, 0x00000000000A06A8, 0, 0) = 1
    TranslateMessageA(0x0000000000BCF698) = 1
    DispatchMessageA(0x0000000000BCF698) = 0
      DestroyWindow(0x00000000000A06A8) = 1
        PostQuitMessage(0) = VOID

    __global DWORD CallLvl determines how many indents to print
    CallLvl++ when entering function, CallLvl-- when leaving
    Need a way to organize the string to print so it can be done in correct order (not a stack)

    We can make it so that by default, DestroyWindow + PostQuitMessage are not printed,
    but then specifying option /n WILL print them. No /n specified is easy: just
    check that CallLvl == 1 before printing any output.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <string.h>

#define CRLF "\r\n"

// Version
#define WINTRACE_CORE_VERSION "0.3.1"

// Extra options here that aren't used by the DLL (ProgramName and CmdArgs)
// Might rename this to T_WintraceOptsEx or something to specify this, or
// might just update the DLL struct.
// dunno yet, not currently important :/
typedef struct _tag_WintraceOpts
{
    BOOL        ShowThreadID;
    BOOL        ShowProcessID;
    BOOL        ShowFuncCount;
    CHAR        OutputFilename[64];
    CHAR        TraceList[32][32];
    CHAR        BlockList[32][32];
    CHAR        *ProgramName,
                CmdArgs[128];
} T_WintraceOpts;

// Show full list of options/switches
void            PrintUsage(void);

// Read cmdline arguments
T_WintraceOpts  ParseOpts(int argc, char **argv);

// Pipe stuff
HANDLE      g_Pipe;
DWORD __stdcall InitializePipe(LPVOID Param);

// Function pointer signature for querying DLL version
typedef LPSTR (__stdcall *MYPROC)(void);

// Names
CHAR        OptsName[32],
            PipeName[32],
            FenceName[32];

int
main(int argc,
     char **argv)
{
    LPCSTR                      DllPath = "wintrace.dll";
    STARTUPINFO                 StartupInfo = {0};
    PROCESS_INFORMATION         ProcessInfo = {0};
    LPVOID                      pDllPath;
    HANDLE                      LoadThread;
    SIZE_T                      Len = strlen(DllPath) + 1;
    BOOL                        Status;
    LPTHREAD_START_ROUTINE      lpfnLoadLibA;
    LPTHREAD_START_ROUTINE      lpfnFreeLib;
    T_WintraceOpts              Opts;
    LPVOID                      pOpts;
    HANDLE                      FileMap,
                                PipeThread;
    HANDLE                      Fence;


    // Parse opts
    Opts = ParseOpts(argc, argv);

    // Create process
    StartupInfo.cb = sizeof(STARTUPINFO);
    Status = CreateProcess(Opts.ProgramName, Opts.CmdArgs, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &StartupInfo, &ProcessInfo);
    if (!Status)
    {
        fprintf(stderr, "[CORE] Failed to create process...! (Error: %u)" CRLF, GetLastError());
        return -1;
    }

    // Construct names
    sprintf(OptsName, "WintraceOpts_%u", ProcessInfo.dwProcessId);
    sprintf(PipeName, "\\\\.\\pipe\\WintracePipe_%u", ProcessInfo.dwProcessId);
    sprintf(FenceName, "WintraceFence_%u", ProcessInfo.dwProcessId);

    fprintf(stderr,
            "[CORE] Initialized successfully:" CRLF
            "  PID: %u" CRLF
            "  Opts: %s" CRLF
            "  Pipe: %s" CRLF
            "  Fence: %s" CRLF,
            ProcessInfo.dwProcessId, OptsName, PipeName, FenceName);

    // Map shared memory
    FileMap = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, sizeof(T_WintraceOpts), OptsName);
    if (!FileMap)
    {
        fprintf(stderr, "[CORE] Could not create file map...! (Error: %u)" CRLF, GetLastError());
        return -1;
    }
    pOpts = (T_WintraceOpts *)MapViewOfFile(FileMap, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(T_WintraceOpts));
    if (!pOpts)
    {
        fprintf(stderr, "[CORE] Could not create map view...! (Error: %u)" CRLF, GetLastError());
        CloseHandle(FileMap);
        return -1;
    }
    CopyMemory((LPVOID)pOpts, &Opts, sizeof(T_WintraceOpts));

    // Inject DLL
    lpfnLoadLibA = (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle("Kernel32.dll"), "LoadLibraryA");
    if (!lpfnLoadLibA)
    {
        fprintf(stderr, "[CORE] Could no locate LoadLibraryA...! (Error: %u)" CRLF, GetLastError());
        return -1;
    }

    lpfnFreeLib = (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle("Kernel32.dll"), "FreeLibrary");
    if (!lpfnFreeLib)
    {
        fprintf(stderr, "[CORE] Could no locate FreeLibrary...! (Error: %u)" CRLF, GetLastError());
        return -1;
    }

    pDllPath = VirtualAllocEx(ProcessInfo.hProcess, 0, Len, MEM_COMMIT, PAGE_READWRITE);
    if (!pDllPath)
    {
        fprintf(stderr, "[CORE] Failed to allocate DLL path...! (Error: %u)" CRLF, GetLastError());
        return -1;
    }

    Status = WriteProcessMemory(ProcessInfo.hProcess, pDllPath, (LPVOID)DllPath, Len, 0);
    if (!Status)
    {
        fprintf(stderr, "[CORE] Failed to write target memory...! (Error: %u)" CRLF, GetLastError());
        return -1;
    }

    // Fence
    Fence = CreateEventA(NULL, FALSE, FALSE, FenceName);
    if (!Fence)
    {
        fprintf(stderr, "[CORE] Failed to create fence...! (Error: %u)" CRLF, GetLastError());
        return (-1);
    }

    // Pipe thread
    PipeThread = CreateThread(NULL, 0, &InitializePipe, NULL, 0, NULL);

    // LoadLibrary thread
    LoadThread = CreateRemoteThread(ProcessInfo.hProcess, NULL, 0, lpfnLoadLibA, pDllPath, 0, NULL);
    if (!LoadThread)
    {
        fprintf(stderr, "[CORE] Failed to load remote thread...! (Error: %u)" CRLF, GetLastError());
        return -1;
    }
    WaitForSingleObject(LoadThread, INFINITE);

    // Main thread
    ResumeThread(ProcessInfo.hThread);

    // Read from pipe
    {
        CHAR        Buffer[1024];
        DWORD       NumRead;
        FILE        *OutputFile = stderr;


        if (Opts.OutputFilename[0])
        {
            OutputFile = fopen(Opts.OutputFilename, "w+");
        }

        for (;;)
        {
            Status = ReadFile(g_Pipe, Buffer, 512, &NumRead, NULL);
            if (Status)
            {
                Buffer[NumRead] = 0;
                fprintf(OutputFile, "%s", Buffer);
                SetEvent(Fence);
            }
            else
            {
                // target EXE is finished executing -> pipe closed
                break;
            }
        }

        if (Opts.OutputFilename[0])
        {
            fclose(OutputFile);
        }
    }

    WaitForSingleObject(ProcessInfo.hThread, INFINITE);

    // FreeLibrary thread
    LoadThread = CreateRemoteThread(ProcessInfo.hProcess, NULL, 0, lpfnFreeLib, pDllPath, 0, NULL);
    WaitForSingleObject(ProcessInfo.hThread, INFINITE);

    // Cleanup
    VirtualFreeEx(ProcessInfo.hProcess, pDllPath, Len, MEM_RELEASE);
    UnmapViewOfFile(FileMap);
    CloseHandle(FileMap);
    CloseHandle(g_Pipe);
    CloseHandle(Fence);

    return 0;
}

void
PrintUsage(void)
{
    HMODULE     WintraceDll;
    MYPROC      GetDllVersion;


    WintraceDll = LoadLibraryExA("wintrace.dll", NULL, DONT_RESOLVE_DLL_REFERENCES);
    GetDllVersion = (MYPROC)GetProcAddress(WintraceDll, "GetWintraceDllVersion");

    fprintf(stderr,  CRLF
            "core version: %s" CRLF
            "dll version: %s" CRLF CRLF
            "Usage: wintrace [options...] <exe> [args...]" CRLF CRLF
            "Options:" CRLF
            "  /c            Show function call count" CRLF
            "  /p            Show process ID" CRLF
            "  /t            Show thread ID" CRLF
            "  /T:fns        Trace only fns, a comma separated list of function names" CRLF
            "  /B:fns        Trace all functions except fns, a comma separated list of function names" CRLF
            "  /o:file       Output to file" CRLF
            "  /?            Show available options" CRLF,
            WINTRACE_CORE_VERSION, GetDllVersion());
}

T_WintraceOpts
ParseOpts(int argc,
          char **argv)
{
    INT                 OptInd;
    T_WintraceOpts      Opts = {0};


    if (argc < 2)
    {
        fprintf(stderr, CRLF "Usage: wintrace [options...] <exe> [args...]" CRLF);
        fprintf(stderr, "Use /? for more info" CRLF CRLF);
        exit(-1);
    }

    for (OptInd = 1; (OptInd < argc) && argv[OptInd][0] == '/'; OptInd++)
    {
        switch (argv[OptInd][1])
        {
            case 'c':
            {
                Opts.ShowFuncCount = TRUE;
            } break;
            case 't':
            {
                Opts.ShowThreadID = TRUE;
            } break;
            case 'p':
            {
                Opts.ShowProcessID = TRUE;
            } break;
            case 'o':
            {
                strcpy(Opts.OutputFilename, argv[OptInd] + 3);
            } break;
            case 'T':
            {
                CHAR *Token;
                INT I = 0;

                Token = strtok(argv[OptInd] + 3, ",");
                while (Token != NULL && I < 32)
                {
                    strcpy(Opts.TraceList[I], Token);
                    Token = strtok(NULL, ",");
                    I++;
                }
            } break;
            case 'B':
            {
                CHAR *Token;
                INT I = 0;

                Token = strtok(argv[OptInd] + 3, ",");
                while (Token != NULL && I < 32)
                {
                    strcpy(Opts.BlockList[I], Token);
                    Token = strtok(NULL, ",");
                    I++;
                }
            } break;
            case '?':
            {
                PrintUsage();
                exit(1);
            } break;

            default:
            {
                fprintf(stderr, CRLF "Usage: wintrace [options...] <exe> [args...]" CRLF);
                fprintf(stderr, "Use /? for more info" CRLF);
                exit(-1);
            } break;
        }
    }

    if (Opts.TraceList[0][0] && Opts.BlockList[0][0])
    {
        fprintf(stderr, "Error: can only trace (/T) OR block (/B) functions...!" CRLF);
        exit(-1);
    }

    // Fill out EXE name
    Opts.ProgramName = argv[OptInd++];

    // Fill out the cmdline args, if any
    if (OptInd < argc)
    {
        // Put program name as argv[0] because documentation says so
        strcpy(Opts.CmdArgs, Opts.ProgramName);
        for (OptInd; OptInd < argc; OptInd++)
        {
            strcat(Opts.CmdArgs, " ");
            strcat(Opts.CmdArgs, argv[OptInd]);
        }
    }

    return Opts;
}

DWORD __stdcall
InitializePipe(LPVOID Param)
{
    BOOL        Status;


    UNREFERENCED_PARAMETER(Param);

    g_Pipe = CreateNamedPipe(PipeName, PIPE_ACCESS_INBOUND, PIPE_TYPE_BYTE, 1, 0, 0, 0, NULL);
    fprintf(stderr, "[CORE] Created pipe...\r\n");
    Status = ConnectNamedPipe(g_Pipe, NULL);
    if (!Status)
    {
        fprintf(stderr, "[CORE] Failed to connect pipe...!\r\n");
    }
    else
    {
        fprintf(stderr, "[CORE] Connected pipe...\r\n");
    }

    return (0);
}


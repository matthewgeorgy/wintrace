/*
    Version History

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

	wintrace /e:HeapCreate ...			Fail ALL HeapCreate calls
	wintrace /e:HeapCreate:4 ...	 	Fail the 4th HeapCreate call
	wintrace /i:GetFileSize:25 ...		ALL GetFileSize calls return 25
	wintrace /i:GetFileSize:25:3 ...	GetFileSize call #3 returns 25

	wintrace {/i|/e}:HeapAlloc,HeapFree ...	Chain multiple funcs??
*/

/*
	Trace synopsis:

	wintrace /T:HeapAlloc,HeapCreate ...	Only trace HeapAlloc + HeapCreate
	Functions are arranged in a comma-seperated list
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

typedef struct _tag_WINTRACE_OPTS
{
    BOOL        ShowThreadID;
    BOOL        ShowProcessID;
    BOOL        ShowFuncCount;
    CHAR        OutputFilename[64];
    FILE        *OutputFile;
} T_WINTRACE_OPTS;

void PrintUsage(void);
T_WINTRACE_OPTS ParseOpts(int argc, char **argv);

int
main(int argc,
     char **argv)
{
    LPCSTR                      DllPath = "wintrace.dll";
    LPCSTR                      ProgramName = argv[argc - 1];
    STARTUPINFO                 si = {0};
    PROCESS_INFORMATION         pi = {0};
    LPVOID                      pDllPath;
    HANDLE                      LoadThread;
    SIZE_T                      Len = strlen(DllPath) + 1;
    BOOL                        Status;
    LPTHREAD_START_ROUTINE      lpfnLoadLibA;
    LPTHREAD_START_ROUTINE      lpfnFreeLib;
    T_WINTRACE_OPTS             Opts;
    LPVOID                      pOpts;
    HANDLE                      FileMap;


    // Parse opts
    Opts = ParseOpts(argc, argv);

    // Map shared memory
    FileMap = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, sizeof(T_WINTRACE_OPTS), "WintraceOpts");
    if (!FileMap)
    {
        printf("could not create file map (%d)\n", GetLastError());
        return -1;
    }
    pOpts = (T_WINTRACE_OPTS *)MapViewOfFile(FileMap, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(T_WINTRACE_OPTS));
    if (!pOpts)
    {
        printf("could not create map view (%d)\n", GetLastError());
        CloseHandle(FileMap);
        return -1;
    }
    CopyMemory((LPVOID)pOpts, &Opts, sizeof(T_WINTRACE_OPTS));

    // Inject DLL
    si.cb = sizeof(STARTUPINFO);
    Status = CreateProcess(ProgramName, NULL, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &si, &pi);
    if (!Status)
    {
        printf("failed to create process!\n");
        return -1;
    }

    lpfnLoadLibA = (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle("Kernel32.dll"), "LoadLibraryA");
    if (!lpfnLoadLibA)
    {
        printf("could no locate loadliba\n");
        return -1;
    }

    lpfnFreeLib = (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle("Kernel32.dll"), "FreeLibrary");
    if (!lpfnFreeLib)
    {
        printf("could no locate freeliba\n");
        return -1;
    }

    pDllPath = VirtualAllocEx(pi.hProcess, 0, Len, MEM_COMMIT, PAGE_READWRITE);
    if (!pDllPath)
    {
        printf("failed to allocate!\n");
        return -1;
    }

    Status = WriteProcessMemory(pi.hProcess, pDllPath, (LPVOID)DllPath, Len, 0);
    if (!Status)
    {
        printf("failed to write memory!\n");
        return -1;
    }

    LoadThread = CreateRemoteThread(pi.hProcess, NULL, 0, lpfnLoadLibA, pDllPath, 0, NULL);
    if (!LoadThread)
    {
        printf("failed to load thread\n");
        return -1;
    }

    WaitForSingleObject(LoadThread, INFINITE);

    ResumeThread(pi.hThread);

    WaitForSingleObject(pi.hThread, INFINITE);

    LoadThread = CreateRemoteThread(pi.hProcess, NULL, 0, lpfnFreeLib, pDllPath, 0, NULL);

    WaitForSingleObject(pi.hThread, INFINITE);

    // Cleanup
    VirtualFreeEx(pi.hProcess, pDllPath, Len, MEM_RELEASE);
    UnmapViewOfFile(FileMap);
    CloseHandle(FileMap);

    return 0;
}

void
PrintUsage(void)
{
    printf("\nOptions:\n");
    printf("  /c            Show function call count\n");
    printf("  /p            Show process ID\n");
    printf("  /t            Show thread ID\n");
    printf("  /o:[file]     Output to [file]\n");
}

T_WINTRACE_OPTS
ParseOpts(int argc,
          char **argv)
{
    INT                 OptInd;
    T_WINTRACE_OPTS     Opts = {0};


    if (argc < 2)
    {
        printf("\nUsage: wintrace [options] <exe>\n");
        printf("Use /? for more info\n\n");
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
            case '?':
            {
                PrintUsage();
                exit(1);
            } break;

            default:
            {
                printf("\nUsage: wintrace [options] <exe>\n");
                printf("Use /? for more info\n");
                exit(-1);
            } break;
        }
    }

    return Opts;
}


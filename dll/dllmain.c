#define _CRT_SECURE_NO_WARNINGS
#include <dllmain.h>

T_WintraceOpts      *pOpts;
HANDLE              g_Pipe;
HANDLE              g_Fence;

LPSTR __stdcall
GetWintraceDllVersion(void)
{
    return (WINTRACE_DLL_VERSION);
}

BOOL APIENTRY
DllMain(HMODULE hModule,
        DWORD fdwReason,
        LPVOID lpReserved)
{
    // Names
    CHAR        OptsName[32],
                PipeName[32],
                FenceName[32];


    UNREFERENCED_PARAMETER(hModule); 
    UNREFERENCED_PARAMETER(lpReserved);

    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
        {
            HANDLE      FileMap;
            DWORD       ProcessId;

            ProcessId = GetCurrentProcessId();

            // Construct names
            sprintf(OptsName, "WintraceOpts_%u", ProcessId);
            sprintf(PipeName, "\\\\.\\pipe\\WintracePipe_%u", ProcessId);
            sprintf(FenceName, "WintraceFence_%u", ProcessId);

            g_Pipe = CreateFileA(PipeName,
                GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
                NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            if (g_Pipe)
            {
                fprintf(stderr, "[DLL] Connected pipe...\r\n");
            }

            g_Fence = OpenEventA(SYNCHRONIZE, FALSE, FenceName);
            if (g_Fence)
            {
                fprintf(stderr, "[DLL] Opened the fence...\r\n");
            }

            FileMap = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, OptsName);
            if (FileMap)
            {
                pOpts = (T_WintraceOpts *)MapViewOfFile(FileMap, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(T_WintraceOpts));
                if (pOpts)
                {
                }
                else
                {
                    fprintf(stderr, "[DLL] Failed to map file view!(%d)\n", GetLastError());
                }
            }
            else
            {
                fprintf(stderr, "[DLL] Could not open file map!(%d)\n", GetLastError());
            }

            InitFuncRecs();
            PatchIAT();

        } break;
        case DLL_PROCESS_DETACH:
        {
            CloseHandle(g_Pipe);
        } break;
    }

    return TRUE;
}

void
PatchIAT(void)
{
    HANDLE                          ImageBase;
    PIMAGE_DOS_HEADER               DosHeader;
    PIMAGE_NT_HEADERS               NtHeader;
    PIMAGE_IMPORT_DESCRIPTOR        ImportDesc;
    IMAGE_DATA_DIRECTORY            ImportDir;
    PIMAGE_IMPORT_BY_NAME           FunctionName;
    PIMAGE_THUNK_DATA               OriginalFirstThunk,
                                    FirstThunk;
    DWORD                           FuncHash;


    ImageBase = GetModuleHandleA(NULL);
    DosHeader = (PIMAGE_DOS_HEADER)ImageBase;
    NtHeader = (PIMAGE_NT_HEADERS)((DWORD_PTR)ImageBase + DosHeader->e_lfanew);

    ImportDir = NtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
    ImportDesc = (PIMAGE_IMPORT_DESCRIPTOR)(ImportDir.VirtualAddress + (DWORD_PTR)ImageBase);

    while (ImportDesc->Name != 0)
    {
        OriginalFirstThunk = (PIMAGE_THUNK_DATA)((DWORD_PTR)ImageBase + ImportDesc->OriginalFirstThunk);
        FirstThunk = (PIMAGE_THUNK_DATA)((DWORD_PTR)ImageBase + ImportDesc->FirstThunk);

        while (OriginalFirstThunk->u1.AddressOfData != 0)
        {
            FunctionName = (PIMAGE_IMPORT_BY_NAME)((DWORD_PTR)ImageBase + OriginalFirstThunk->u1.AddressOfData);
            FuncHash = Djb2((LPSTR)FunctionName->Name);

            PatchFunction(FuncHash, FirstThunk);

            OriginalFirstThunk++;
            FirstThunk++;
        }

        ImportDesc++;
    }
}

void
ReadIAT(void)
{
    LPVOID                          ImageBase;
    PIMAGE_DOS_HEADER               DosHeader;
    PIMAGE_NT_HEADERS               NtHeader;
    PIMAGE_IMPORT_DESCRIPTOR        ImportDesc;
    IMAGE_DATA_DIRECTORY            ImportDir;
    LPCSTR                          LibraryName;
    HMODULE                         Library;
    PIMAGE_IMPORT_BY_NAME           FunctionName;
    PIMAGE_THUNK_DATA               OriginalFirstThunk,
                                    FirstThunk;


    printf("\n");
    ImageBase = GetModuleHandle(NULL);
    DosHeader = (PIMAGE_DOS_HEADER)ImageBase;
    NtHeader = (PIMAGE_NT_HEADERS)((DWORD_PTR)ImageBase + DosHeader->e_lfanew);

    ImportDir = NtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
    ImportDesc = (PIMAGE_IMPORT_DESCRIPTOR)(ImportDir.VirtualAddress + (DWORD_PTR)ImageBase);

    while (ImportDesc->Name != 0)
    {
        LibraryName = (LPCSTR)((DWORD_PTR)ImportDesc->Name) + (DWORD_PTR)ImageBase;
        Library = LoadLibraryA(LibraryName);
        printf("\n%s\n", LibraryName);

        if (Library)
        {
            OriginalFirstThunk = (PIMAGE_THUNK_DATA)((DWORD_PTR)ImageBase + ImportDesc->OriginalFirstThunk);
            FirstThunk = (PIMAGE_THUNK_DATA)((DWORD_PTR)ImageBase + ImportDesc->FirstThunk);

            while (OriginalFirstThunk->u1.AddressOfData != 0)
            {
                FunctionName = (PIMAGE_IMPORT_BY_NAME)((DWORD_PTR)ImageBase + OriginalFirstThunk->u1.AddressOfData);

                printf("%s\n", FunctionName->Name);

                OriginalFirstThunk++;
                FirstThunk++;
            }
        }

        ImportDesc++;
    }
}


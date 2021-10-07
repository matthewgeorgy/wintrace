#include "inc/dllmain.h"

T_WINTRACEOPTS      *pOpts;

BOOL APIENTRY
DllMain(HMODULE hModule,
        DWORD fdwReason,
        LPVOID lpReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
        {
            T_HFILEMAP		FileMap;

            FileMap = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, "wintraceOpts");
            if (FileMap)
            {
                pOpts = (T_WINTRACEOPTS *)MapViewOfFile(FileMap, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(T_WINTRACEOPTS));
                if (pOpts)
                {
                    printf("opts!:%d %d %d\n", pOpts->ShowThreadID, pOpts->ShowProcessID, pOpts->ShowFuncCount);
                }
                else
                {
                    printf("failed to map file view!(%d)\n", GetLastError());
                }
            }
            else
            {
                printf("could not open file map!(%d)\n", GetLastError());
            }
            /* ReadIAT(); */
            PatchIAT();
        } break;
        case DLL_PROCESS_DETACH:
        {
        } break;
    }

    return TRUE;
}

void
PatchIAT(void)
{
    LPVOID                          ImageBase;
    PIMAGE_DOS_HEADER               DosHeader;
    PIMAGE_NT_HEADERS               NtHeader;
    PIMAGE_IMPORT_DESCRIPTOR        ImportDesc;
    IMAGE_DATA_DIRECTORY            ImportDir;
    LPCSTR                          LibraryName;
    HMODULE                         Library;
    PIMAGE_IMPORT_BY_NAME           FunctionName;
    DWORD                           OldProtect;
    PIMAGE_THUNK_DATA               OriginalFirstThunk,
                                    FirstThunk;


    ImageBase = GetModuleHandle(NULL);
    DosHeader = (PIMAGE_DOS_HEADER)ImageBase;
    NtHeader = (PIMAGE_NT_HEADERS)((DWORD_PTR)ImageBase + DosHeader->e_lfanew);

    ImportDir = NtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
    ImportDesc = (PIMAGE_IMPORT_DESCRIPTOR)(ImportDir.VirtualAddress + (DWORD_PTR)ImageBase);

    while (ImportDesc->Name != 0)
    {
        LibraryName = (LPCSTR)ImportDesc->Name + (DWORD_PTR)ImageBase;
        Library = LoadLibraryA(LibraryName);

        if (Library)
        {
            OriginalFirstThunk = (PIMAGE_THUNK_DATA)((DWORD_PTR)ImageBase + ImportDesc->OriginalFirstThunk);
            FirstThunk = (PIMAGE_THUNK_DATA)((DWORD_PTR)ImageBase + ImportDesc->FirstThunk);

            while (OriginalFirstThunk->u1.AddressOfData != 0)
            {
                FunctionName = (PIMAGE_IMPORT_BY_NAME)((DWORD_PTR)ImageBase + OriginalFirstThunk->u1.AddressOfData);

#pragma warning(disable: 4127)
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "MessageBoxA") == 0) PatchEntry(WtMessageBoxA);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "GetCurrentProcess") == 0) PatchEntry(WtGetCurrentProcess);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "GetCurrentProcessId") == 0) PatchEntry(WtGetCurrentProcessId);
                // heapapi.h
#ifdef _WIN64
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "GetProcessHeap") == 0)       PatchEntry(WtGetProcessHeap);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "GetProcessHeaps") == 0)      PatchEntry(WtGetProcessHeaps);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "HeapAlloc") == 0)            PatchEntry(WtHeapAlloc);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "HeapCompact") == 0)          PatchEntry(WtHeapCompact);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "HeapCreate") == 0)           PatchEntry(WtHeapCreate);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "HeapDestroy") == 0)          PatchEntry(WtHeapDestroy);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "HeapFree") == 0)             PatchEntry(WtHeapFree);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "HeapLock") == 0)             PatchEntry(WtHeapLock);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "HeapQueryInformation") == 0) PatchEntry(WtHeapQueryInformation);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "HeapReAlloc") == 0)          PatchEntry(WtHeapReAlloc);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "HeapSetInformation") == 0)   PatchEntry(WtHeapSetInformation);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "HeapSize") == 0)             PatchEntry(WtHeapSize);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "HeapUnlock") == 0)           PatchEntry(WtHeapUnlock);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "HeapValidate") == 0)         PatchEntry(WtHeapValidate);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "HeapWalk") == 0)             PatchEntry(WtHeapWalk);
#endif // _WIN64
#pragma warning(default: 4127)

                OriginalFirstThunk++;
                FirstThunk++;
            }
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
        LibraryName = (LPCSTR)ImportDesc->Name + (DWORD_PTR)ImageBase;
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

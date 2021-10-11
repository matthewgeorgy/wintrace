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
            T_HFILEMAP      FileMap;

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
                // winuser.h
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "AdjustWindowRect") == 0) PatchEntry(WtAdjustWindowRect);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "AdjustWindowRectEx") == 0) PatchEntry(WtAdjustWindowRectEx);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "BeginPaint") == 0) PatchEntry(WtBeginPaint);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "ClientToScreen") == 0) PatchEntry(WtClientToScreen);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "ClipCursor") == 0) PatchEntry(WtClipCursor);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "CloseWindow") == 0) PatchEntry(WtCloseWindow);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "CreateWindowA") == 0) PatchEntry(WtCreateWindowA);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "CreateWindowW") == 0) PatchEntry(WtCreateWindowW);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "CreateWindowExA") == 0) PatchEntry(WtCreateWindowExA);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "CreateWindowExW") == 0) PatchEntry(WtCreateWindowExW);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "DefWindowProc") == 0) PatchEntry(WtDefWindowProc);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "DestroyWindow") == 0) PatchEntry(WtDestroyWindow);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "DispatchMessageA") == 0) PatchEntry(WtDispatchMessageA);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "DispatchMessageW") == 0) PatchEntry(WtDispatchMessageW);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "EndPaint") == 0) PatchEntry(WtEndPaint);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "FillRect") == 0) PatchEntry(WtFillRect);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "GetClientRect") == 0) PatchEntry(WtGetClientRect);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "GetCursorPos") == 0) PatchEntry(WtGetCursorPos);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "GetDC") == 0) PatchEntry(WtGetDC);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "GetMessage") == 0) PatchEntry(WtGetMessage);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "GetWindowRect") == 0) PatchEntry(WtGetWindowRect);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "MessageBoxA") == 0) PatchEntry(WtMessageBoxA);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "MessageBoxW") == 0) PatchEntry(WtMessageBoxW);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "MessageBoxExA") == 0) PatchEntry(WtMessageBoxExA);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "MessageBoxExW") == 0) PatchEntry(WtMessageBoxExW);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "PeekMessageA") == 0) PatchEntry(WtPeekMessageA);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "PeekMessageW") == 0) PatchEntry(WtPeekMessageW);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "PostMessageA") == 0) PatchEntry(WtPostMessageA);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "PostMessageW") == 0) PatchEntry(WtPostMessageW);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "PostQuitMessage") == 0) PatchEntry(WtPostQuitMessage);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "RegisterClassExA") == 0) PatchEntry(WtRegisterClassExA);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "RegisterClassExW") == 0) PatchEntry(WtRegisterClassExW);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "ReleaseDC") == 0) PatchEntry(WtReleaseDC);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "ScreenToClient") == 0) PatchEntry(WtScreenToClient);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "ShowCursor") == 0) PatchEntry(WtShowCursor);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "ShowWindow") == 0) PatchEntry(WtShowWindow);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "TranslateMessage") == 0) PatchEntry(WtTranslateMessage);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "UpdateWindow") == 0) PatchEntry(WtUpdateWindow);
#ifdef _WIN64
                // heapapi.h
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
                // processthreadspi.h
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "CreateProcessA") == 0)                   PatchEntry(WtCreateProcessA);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "CreateProcessW") == 0)                   PatchEntry(WtCreateProcessW);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "CreateProcessAsUserA") == 0)             PatchEntry(WtCreateProcessAsUserA);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "CreateProcessAsUserW") == 0)             PatchEntry(WtCreateProcessAsUserW);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "CreateRemoteThread") == 0)               PatchEntry(WtCreateRemoteThread);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "CreateRemoteThreadEx") == 0)             PatchEntry(WtCreateRemoteThreadEx);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "CreateThread") == 0)                     PatchEntry(WtCreateThread);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "DeleteProcThreadAttributeList") == 0)    PatchEntry(WtDeleteProcThreadAttributeList);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "ExitProcess") == 0)                      PatchEntry(WtExitProcess);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "ExitThread") == 0)                       PatchEntry(WtExitThread);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "GetCurrentProcess") == 0)                PatchEntry(WtGetCurrentProcess);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "GetCurrentProcessId") == 0)              PatchEntry(WtGetCurrentProcessId);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "ResumeThread") == 0)                     PatchEntry(WtResumeThread);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "SuspendThread") == 0)                    PatchEntry(WtSuspendThread);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "TerminateProcess") == 0)                 PatchEntry(WtTerminateProcess);
                if (lstrcmpiA((LPCSTR)FunctionName->Name, "TerminateThread") == 0)                  PatchEntry(WtTerminateThread);
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

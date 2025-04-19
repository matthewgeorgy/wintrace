#include <dllmain.h>

void
PatchIAT(void)
{
    HANDLE                          ImageBase;
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
    DWORD                           FuncHash;


    ImageBase = GetModuleHandleA(NULL);
    DosHeader = (PIMAGE_DOS_HEADER)ImageBase;
    NtHeader = (PIMAGE_NT_HEADERS)((DWORD_PTR)ImageBase + DosHeader->e_lfanew);

    ImportDir = NtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
    ImportDesc = (PIMAGE_IMPORT_DESCRIPTOR)(ImportDir.VirtualAddress + (DWORD_PTR)ImageBase);

    while (ImportDesc->Name != 0)
    {
        // NOTE(matthew): Do I actually need this? Why the fuck did I put this here??
        // It's not actually used for anything and calling LoadLibrary from DllMain is bad!

        /* LibraryName = (LPCSTR)((DWORD_PTR)ImportDesc->Name) + (DWORD_PTR)ImageBase; */
        /* Library = LoadLibraryA(LibraryName); */

        /* if (Library) */
        /* { */
        OriginalFirstThunk = (PIMAGE_THUNK_DATA)((DWORD_PTR)ImageBase + ImportDesc->OriginalFirstThunk);
        FirstThunk = (PIMAGE_THUNK_DATA)((DWORD_PTR)ImageBase + ImportDesc->FirstThunk);

        while (OriginalFirstThunk->u1.AddressOfData != 0)
        {
            FunctionName = (PIMAGE_IMPORT_BY_NAME)((DWORD_PTR)ImageBase + OriginalFirstThunk->u1.AddressOfData);
            FuncHash = Djb2((LPSTR)FunctionName->Name);

            switch (FuncHash)
            {
#pragma warning(disable: 4127)
                // winuser.h
                case FUNC_AdjustWindowRect:                 { PatchEntry(WtAdjustWindowRect); } break;
                case FUNC_AdjustWindowRectEx:               { PatchEntry(WtAdjustWindowRectEx); } break;
                case FUNC_BeginPaint:                       { PatchEntry(WtBeginPaint); } break;
                case FUNC_ClientToScreen:                   { PatchEntry(WtClientToScreen); } break;
                case FUNC_ClipCursor:                       { PatchEntry(WtClipCursor); } break;
                case FUNC_CloseWindow:                      { PatchEntry(WtCloseWindow); } break;
                case FUNC_CreateWindowA:                    { PatchEntry(WtCreateWindowA); } break;
                case FUNC_CreateWindowW:                    { PatchEntry(WtCreateWindowW); } break;
                case FUNC_CreateWindowExA:                  { PatchEntry(WtCreateWindowExA); } break;
                case FUNC_CreateWindowExW:                  { PatchEntry(WtCreateWindowExW); } break;
                case FUNC_DefWindowProcA:                   { PatchEntry(WtDefWindowProcA); } break;
                case FUNC_DefWindowProcW:                   { PatchEntry(WtDefWindowProcW); } break;
                case FUNC_DestroyWindow:                    { PatchEntry(WtDestroyWindow); } break;
                case FUNC_DispatchMessageA:                 { PatchEntry(WtDispatchMessageA); } break;
                case FUNC_DispatchMessageW:                 { PatchEntry(WtDispatchMessageW); } break;
                case FUNC_EndPaint:                         { PatchEntry(WtEndPaint); } break;
                case FUNC_FillRect:                         { PatchEntry(WtFillRect); } break;
                case FUNC_GetClientRect:                    { PatchEntry(WtGetClientRect); } break;
                case FUNC_GetCursorPos:                     { PatchEntry(WtGetCursorPos); } break;
                case FUNC_GetDC:                            { PatchEntry(WtGetDC); } break;
                case FUNC_GetMessageA:                      { PatchEntry(WtGetMessageA); } break;
                case FUNC_GetMessageW:                      { PatchEntry(WtGetMessageW); } break;
                case FUNC_GetWindowRect:                    { PatchEntry(WtGetWindowRect); } break;
                case FUNC_MessageBoxA:                      { PatchEntry(WtMessageBoxA); } break;
                case FUNC_MessageBoxW:                      { PatchEntry(WtMessageBoxW); } break;
                case FUNC_MessageBoxExA:                    { PatchEntry(WtMessageBoxExA); } break;
                case FUNC_MessageBoxExW:                    { PatchEntry(WtMessageBoxExW); } break;
                case FUNC_PeekMessageA:                     { PatchEntry(WtPeekMessageA); } break;
                case FUNC_PeekMessageW:                     { PatchEntry(WtPeekMessageW); } break;
                case FUNC_PostMessageA:                     { PatchEntry(WtPostMessageA); } break;
                case FUNC_PostMessageW:                     { PatchEntry(WtPostMessageW); } break;
                case FUNC_PostQuitMessage:                  { PatchEntry(WtPostQuitMessage); } break;
                case FUNC_RegisterClassExA:                 { PatchEntry(WtRegisterClassExA); } break;
                case FUNC_RegisterClassExW:                 { PatchEntry(WtRegisterClassExW); } break;
                case FUNC_ReleaseDC:                        { PatchEntry(WtReleaseDC); } break;
                case FUNC_ScreenToClient:                   { PatchEntry(WtScreenToClient); } break;
                case FUNC_ShowCursor:                       { PatchEntry(WtShowCursor); } break;
                case FUNC_ShowWindow:                       { PatchEntry(WtShowWindow); } break;
                case FUNC_TranslateMessage:                 { PatchEntry(WtTranslateMessage); } break;
                case FUNC_UpdateWindow:                     { PatchEntry(WtUpdateWindow); } break;
                // heapapi.h
                case FUNC_GetProcessHeap:                   { PatchEntry(WtGetProcessHeap); } break;
                case FUNC_GetProcessHeaps:                  { PatchEntry(WtGetProcessHeaps); } break;
                case FUNC_HeapAlloc:                        { PatchEntry(WtHeapAlloc); } break;
                case FUNC_HeapCompact:                      { PatchEntry(WtHeapCompact); } break;
                case FUNC_HeapCreate:                       { PatchEntry(WtHeapCreate); } break;
                case FUNC_HeapDestroy:                      { PatchEntry(WtHeapDestroy); } break;
                case FUNC_HeapFree:                         { PatchEntry(WtHeapFree); } break;
                case FUNC_HeapLock:                         { PatchEntry(WtHeapLock); } break;
                case FUNC_HeapQueryInformation:             { PatchEntry(WtHeapQueryInformation); } break;
                case FUNC_HeapReAlloc:                      { PatchEntry(WtHeapReAlloc); } break;
                case FUNC_HeapSetInformation:               { PatchEntry(WtHeapSetInformation); } break;
                case FUNC_HeapSize:                         { PatchEntry(WtHeapSize); } break;
                case FUNC_HeapUnlock:                       { PatchEntry(WtHeapUnlock); } break;
                case FUNC_HeapValidate:                     { PatchEntry(WtHeapValidate); } break;
                case FUNC_HeapWalk:                         { PatchEntry(WtHeapWalk); } break;
                // processthreadspi.h
                case FUNC_CreateProcessA:                   { PatchEntry(WtCreateProcessA); } break;
                case FUNC_CreateProcessW:                   { PatchEntry(WtCreateProcessW); } break;
                case FUNC_CreateProcessAsUserA:             { PatchEntry(WtCreateProcessAsUserA); } break;
                case FUNC_CreateProcessAsUserW:             { PatchEntry(WtCreateProcessAsUserW); } break;
                case FUNC_CreateRemoteThread:               { PatchEntry(WtCreateRemoteThread); } break;
                case FUNC_CreateRemoteThreadEx:             { PatchEntry(WtCreateRemoteThreadEx); } break;
                case FUNC_CreateThread:                     { PatchEntry(WtCreateThread); } break;
                case FUNC_DeleteProcThreadAttributeList:    { PatchEntry(WtDeleteProcThreadAttributeList); } break;
                case FUNC_ExitProcess:                      { PatchEntry(WtExitProcess); } break;
                case FUNC_ExitThread:                       { PatchEntry(WtExitThread); } break;
                case FUNC_GetCurrentProcess:                { PatchEntry(WtGetCurrentProcess); } break;
                case FUNC_GetCurrentProcessId:              { PatchEntry(WtGetCurrentProcessId); } break;
                case FUNC_ResumeThread:                     { PatchEntry(WtResumeThread); } break;
                case FUNC_SuspendThread:                    { PatchEntry(WtSuspendThread); } break;
                case FUNC_TerminateProcess:                 { PatchEntry(WtTerminateProcess); } break;
                case FUNC_TerminateThread:                  { PatchEntry(WtTerminateThread); } break;
                // fileapi.h
                case FUNC_CreateDirectoryA:                 { PatchEntry(WtCreateDirectoryA); } break;
                case FUNC_CreateDirectoryW:                 { PatchEntry(WtCreateDirectoryW); } break;
                case FUNC_CreateFileA:                      { PatchEntry(WtCreateFileA); } break;
                case FUNC_CreateFileW:                      { PatchEntry(WtCreateFileW); } break;
                case FUNC_DeleteFileA:                      { PatchEntry(WtDeleteFileA); } break;
                case FUNC_DeleteFileW:                      { PatchEntry(WtDeleteFileW); } break;
                case FUNC_GetFileSize:                      { PatchEntry(WtGetFileSize); } break;
                case FUNC_GetFileSizeEx:                    { PatchEntry(WtGetFileSizeEx); } break;
                case FUNC_GetFileType:                      { PatchEntry(WtGetFileType); } break;
                case FUNC_ReadFile:                         { PatchEntry(WtReadFile); } break;
                case FUNC_ReadFileEx:                       { PatchEntry(WtReadFileEx); } break;
                case FUNC_RemoveDirectoryA:                 { PatchEntry(WtRemoveDirectoryA); } break;
                case FUNC_RemoveDirectoryW:                 { PatchEntry(WtRemoveDirectoryW); } break;
                case FUNC_SetEndOfFile:                     { PatchEntry(WtSetEndOfFile); } break;
                case FUNC_SetFilePointer:                   { PatchEntry(WtSetFilePointer); } break;
                case FUNC_SetFilePointerEx:                 { PatchEntry(WtSetFilePointerEx); } break;
                case FUNC_WriteFile:                        { PatchEntry(WtWriteFile); } break;
                case FUNC_WriteFileEx:                      { PatchEntry(WtWriteFileEx); } break;
                // debugapi.h
                case FUNC_CheckRemoteDebuggerPresent:       { PatchEntry(WtCheckRemoteDebuggerPresent); } break;
                case FUNC_ContinueDebugEvent:               { PatchEntry(WtContinueDebugEvent); } break;
                case FUNC_DebugActiveProcess:               { PatchEntry(WtDebugActiveProcess); } break;
                case FUNC_DebugActiveProcessStop:           { PatchEntry(WtDebugActiveProcessStop); } break;
                case FUNC_DebugBreak:                       { PatchEntry(WtDebugBreak); } break;
                case FUNC_IsDebuggerPresent:                { PatchEntry(WtIsDebuggerPresent); } break;
                case FUNC_OutputDebugStringA:               { PatchEntry(WtOutputDebugStringA); } break;
                case FUNC_OutputDebugStringW:               { PatchEntry(WtOutputDebugStringW); } break;
                case FUNC_WaitForDebugEvent:                { PatchEntry(WtWaitForDebugEvent); } break;
                // profileapi.h
                case FUNC_QueryPerformanceCounter:          { PatchEntry(WtQueryPerformanceCounter); } break;
                case FUNC_QueryPerformanceFrequency:        { PatchEntry(WtQueryPerformanceFrequency); } break;
                // memoryapi.h
                case FUNC_CreateFileMappingA:               { PatchEntry(WtCreateFileMappingA); } break;
                case FUNC_CreateFileMappingW:               { PatchEntry(WtCreateFileMappingW); } break;
                case FUNC_FlushViewOfFile:                  { PatchEntry(WtFlushViewOfFile); } break;
                case FUNC_MapViewOfFile:                    { PatchEntry(WtMapViewOfFile); } break;
                case FUNC_MapViewOfFileEx:                  { PatchEntry(WtMapViewOfFileEx); } break;
                case FUNC_OpenFileMappingA:                 { PatchEntry(WtOpenFileMappingA); } break;
                case FUNC_OpenFileMappingW:                 { PatchEntry(WtOpenFileMappingW); } break;
                case FUNC_UnmapViewOfFile:                  { PatchEntry(WtUnmapViewOfFile); } break;
                case FUNC_VirtualAlloc:                     { PatchEntry(WtVirtualAlloc); } break;
                case FUNC_VirtualAllocEx:                   { PatchEntry(WtVirtualAllocEx); } break;
                case FUNC_VirtualFree:                      { PatchEntry(WtVirtualFree); } break;
                case FUNC_VirtualFreeEx:                    { PatchEntry(WtVirtualFreeEx); } break;
                case FUNC_VirtualLock:                      { PatchEntry(WtVirtualLock); } break;
                case FUNC_VirtualProtect:                   { PatchEntry(WtVirtualProtect); } break;
                case FUNC_VirtualProtectEx:                 { PatchEntry(WtVirtualProtectEx); } break;
                case FUNC_VirtualQuery:                     { PatchEntry(WtVirtualQuery); } break;
                case FUNC_VirtualQueryEx:                   { PatchEntry(WtVirtualQueryEx); } break;
                case FUNC_VirtualUnlock:                    { PatchEntry(WtVirtualUnlock); } break;
                // stdio.h
                case FUNC_fopen:                            { PatchEntry(wt_fopen); } break;
                case FUNC__wfopen:                          { PatchEntry(wt__wfopen); } break;
                case FUNC_fclose:                           { PatchEntry(wt_fclose); } break;
                // stdio.h
                case FUNC_malloc:                           { PatchEntry(wt_malloc); } break;
                case FUNC_free:                             { PatchEntry(wt_free); } break;
#pragma warning(default: 4127)
            }

            OriginalFirstThunk++;
            FirstThunk++;
        }
        /* } */

        ImportDesc++;
    }
}

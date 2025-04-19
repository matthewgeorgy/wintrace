#include <common.h>

extern T_WintraceOpts *pOpts;

// Full list of supported function records
T_FuncRec  g_FuncRecs[] =
{
    // debugapi.h
    { "CheckRemoteDebuggerPresent", 0, FALSE },
    { "ContinueDebugEvent", 0, FALSE },
    { "DebugActiveProcess", 0, FALSE },
    { "DebugActiveProcessStop", 0, FALSE },
    { "DebugBreak", 0, FALSE },
    { "IsDebuggerPresent", 0, FALSE },
    { "OutputDebugStringA", 0, FALSE },
    { "OutputDebugStringW", 0, FALSE },
    { "WaitForDebugEvent", 0, FALSE },
    // fileapi.h
    { "CreateDirectoryA", 0, FALSE },
    { "CreateDirectoryW", 0, FALSE },
    { "CreateFileA", 0, FALSE },
    { "CreateFileW", 0, FALSE },
    { "DeleteFileA", 0, FALSE },
    { "DeleteFileW", 0, FALSE },
    { "GetFileSize", 0, FALSE },
    { "GetFileSizeEx", 0, FALSE },
    { "GetFileType", 0, FALSE },
    { "ReadFile", 0, FALSE },
    { "ReadFileEx", 0, FALSE },
    { "RemoveDirectoryA", 0, FALSE },
    { "RemoveDirectoryW", 0, FALSE },
    { "SetEndOfFile", 0, FALSE },
    { "SetFilePointer", 0, FALSE },
    { "SetFilePointerEx", 0, FALSE },
    { "WriteFile", 0, FALSE },
    { "WriteFileEx", 0, FALSE },
    // heapapi.h
    { "GetProcessHeap", 0, FALSE },
    { "GetProcessHeaps", 0, FALSE },
    { "HeapAlloc", 0, FALSE },
    { "HeapCompact", 0, FALSE },
    { "HeapCreate", 0, FALSE },
    { "HeapDestroy", 0, FALSE },
    { "HeapFree", 0, FALSE },
    { "HeapLock", 0, FALSE },
    { "HeapQueryInformation", 0, FALSE },
    { "HeapReAlloc", 0, FALSE },
    { "HeapSetInformation", 0, FALSE },
    { "HeapSize", 0, FALSE },
    { "HeapUnlock", 0, FALSE },
    { "HeapValidate", 0, FALSE },
    { "HeapWalk", 0, FALSE },
    // memoryapi.h
    { "CreateFileMappingA", 0, FALSE },
    { "CreateFileMappingW", 0, FALSE },
    { "FlushViewOfFile", 0, FALSE },
    { "MapViewOfFile", 0, FALSE },
    { "MapViewOfFileEx", 0, FALSE },
    { "OpenFileMappingA", 0, FALSE },
    { "OpenFileMappingW", 0, FALSE },
    { "UnmapViewOfFile", 0, FALSE },
    { "VirtualAlloc", 0, FALSE },
    { "VirtualAllocEx", 0, FALSE },
    { "VirtualFree", 0, FALSE },
    { "VirtualFreeEx", 0, FALSE },
    { "VirtualLock", 0, FALSE },
    { "VirtualProtect", 0, FALSE },
    { "VirtualProtectEx", 0, FALSE },
    { "VirtualQuery", 0, FALSE },
    { "VirtualQueryEx", 0, FALSE },
    { "VirtualUnlock", 0, FALSE },
    // processthreadsapi.h
    { "CreateProcessA", 0, FALSE },
    { "CreateProcessW", 0, FALSE },
    { "CreateProcessAsUserA", 0, FALSE },
    { "CreateProcessAsUserW", 0, FALSE },
    { "CreateRemoteThread", 0, FALSE },
    { "CreateRemoteThreadEx", 0, FALSE },
    { "CreateThread", 0, FALSE },
    { "DeleteProcThreadAttributeList", 0, FALSE },
    { "ExitProcess", 0, FALSE },
    { "ExitThread", 0, FALSE },
    { "GetCurrentProcess", 0, FALSE },
    { "GetCurrentProcessId", 0, FALSE },
    { "ResumeThread", 0, FALSE },
    { "SuspendThread", 0, FALSE },
    { "TerminateProcess", 0, FALSE },
    { "TerminateThread", 0, FALSE },
    // profileapi.h
    { "QueryPerformanceCounter", 0, FALSE },
    { "QueryPerformanceFrequency", 0, FALSE },
    // winuser.h
    { "AdjustWindowRect", 0, FALSE },
    { "AdjustWindowRectEx", 0, FALSE },
    { "BeginPaint", 0, FALSE },
    { "ClientToScreen", 0, FALSE },
    { "ClipCursor", 0, FALSE },
    { "CloseWindow", 0, FALSE },
    { "CreateWindowA", 0, FALSE },
    { "CreateWindowW", 0, FALSE },
    { "CreateWindowExA", 0, FALSE },
    { "CreateWindowExW", 0, FALSE },
    { "DefWindowProcA", 0, FALSE },
    { "DefWindowProcW", 0, FALSE },
    { "DestroyWindow", 0, FALSE },
    { "DispatchMessageA", 0, FALSE },
    { "DispatchMessageW", 0, FALSE },
    { "EndPaint", 0, FALSE },
    { "FillRect", 0, FALSE },
    { "GetClientRect", 0, FALSE },
    { "GetCursorPos", 0, FALSE },
    { "GetDC", 0, FALSE },
    { "GetMessageA", 0, FALSE },
    { "GetMessageW", 0, FALSE },
    { "GetWindowRect", 0, FALSE },
    { "MessageBoxA", 0, FALSE },
    { "MessageBoxW", 0, FALSE },
    { "MessageBoxExA", 0, FALSE },
    { "MessageBoxExW", 0, FALSE },
    { "PeekMessageA", 0, FALSE },
    { "PeekMessageW", 0, FALSE },
    { "PostMessageA", 0, FALSE },
    { "PostMessageW", 0, FALSE },
    { "PostQuitMessage", 0, FALSE },
    { "RegisterClassExA", 0, FALSE },
    { "RegisterClassExW", 0, FALSE },
    { "ReleaseDC", 0, FALSE },
    { "ScreenToClient", 0, FALSE },
    { "ShowCursor", 0, FALSE },
    { "ShowWindow", 0, FALSE },
    { "TranslateMessage", 0, FALSE },
    { "UpdateWindow", 0, FALSE },
    // stdio.h
    { "fopen", 0, FALSE },
    { "_wfopen", 0, FALSE },
    { "fclose", 0, FALSE },
    // stdlib.h
    { "malloc", 0, FALSE },
    { "free", 0, FALSE },
};

void
SetTrace(DWORD Hash,
         BOOL bTrace)
{
    switch (Hash)
    {
        // debugapi.h
        case FUNC_CheckRemoteDebuggerPresent:       { g_FuncRecs[E_CheckRemoteDebuggerPresent].bTrace = bTrace; } break;
        case FUNC_ContinueDebugEvent:               { g_FuncRecs[E_ContinueDebugEvent].bTrace = bTrace; } break;
        case FUNC_DebugActiveProcess:               { g_FuncRecs[E_DebugActiveProcess].bTrace = bTrace; } break;
        case FUNC_DebugActiveProcessStop:           { g_FuncRecs[E_DebugActiveProcessStop].bTrace = bTrace; } break;
        case FUNC_DebugBreak:                       { g_FuncRecs[E_DebugBreak].bTrace = bTrace; } break;
        case FUNC_IsDebuggerPresent:                { g_FuncRecs[E_IsDebuggerPresent].bTrace = bTrace; } break;
        case FUNC_OutputDebugStringA:               { g_FuncRecs[E_OutputDebugStringA].bTrace = bTrace; } break;
        case FUNC_OutputDebugStringW:               { g_FuncRecs[E_OutputDebugStringW].bTrace = bTrace; } break;
        case FUNC_WaitForDebugEvent:                { g_FuncRecs[E_WaitForDebugEvent].bTrace = bTrace; } break;
        // fileapi.h
        case FUNC_CreateDirectoryA:                 { g_FuncRecs[E_CreateDirectoryA].bTrace = bTrace; } break;
        case FUNC_CreateDirectoryW:                 { g_FuncRecs[E_CreateDirectoryW].bTrace = bTrace; } break;
        case FUNC_CreateFileA:                      { g_FuncRecs[E_CreateFileA].bTrace = bTrace; } break;
        case FUNC_CreateFileW:                      { g_FuncRecs[E_CreateFileW].bTrace = bTrace; } break;
        case FUNC_DeleteFileA:                      { g_FuncRecs[E_DeleteFileA].bTrace = bTrace; } break;
        case FUNC_DeleteFileW:                      { g_FuncRecs[E_DeleteFileW].bTrace = bTrace; } break;
        case FUNC_GetFileSize:                      { g_FuncRecs[E_GetFileSize].bTrace = bTrace; } break;
        case FUNC_GetFileSizeEx:                    { g_FuncRecs[E_GetFileSizeEx].bTrace = bTrace; } break;
        case FUNC_GetFileType:                      { g_FuncRecs[E_GetFileType].bTrace = bTrace; } break;
        case FUNC_ReadFile:                         { g_FuncRecs[E_ReadFile].bTrace = bTrace; } break;
        case FUNC_ReadFileEx:                       { g_FuncRecs[E_ReadFileEx].bTrace = bTrace; } break;
        case FUNC_RemoveDirectoryA:                 { g_FuncRecs[E_RemoveDirectoryA].bTrace = bTrace; } break;
        case FUNC_RemoveDirectoryW:                 { g_FuncRecs[E_RemoveDirectoryW].bTrace = bTrace; } break;
        case FUNC_SetEndOfFile:                     { g_FuncRecs[E_SetEndOfFile].bTrace = bTrace; } break;
        case FUNC_SetFilePointer:                   { g_FuncRecs[E_SetFilePointer].bTrace = bTrace; } break;
        case FUNC_SetFilePointerEx:                 { g_FuncRecs[E_SetFilePointerEx].bTrace = bTrace; } break;
        case FUNC_WriteFile:                        { g_FuncRecs[E_WriteFile].bTrace = bTrace; } break;
        case FUNC_WriteFileEx:                      { g_FuncRecs[E_WriteFileEx].bTrace = bTrace; } break;
        // heapapi.h
        case FUNC_GetProcessHeap:                   { g_FuncRecs[E_GetProcessHeap].bTrace = bTrace; } break;
        case FUNC_GetProcessHeaps:                  { g_FuncRecs[E_GetProcessHeaps].bTrace = bTrace; } break;
        case FUNC_HeapAlloc:                        { g_FuncRecs[E_HeapAlloc].bTrace = bTrace; } break;
        case FUNC_HeapCompact:                      { g_FuncRecs[E_HeapCompact].bTrace = bTrace; } break;
        case FUNC_HeapCreate:                       { g_FuncRecs[E_HeapCreate].bTrace = bTrace; } break;
        case FUNC_HeapDestroy:                      { g_FuncRecs[E_HeapDestroy].bTrace = bTrace; } break;
        case FUNC_HeapFree:                         { g_FuncRecs[E_HeapFree].bTrace = bTrace; } break;
        case FUNC_HeapLock:                         { g_FuncRecs[E_HeapLock].bTrace = bTrace; } break;
        case FUNC_HeapQueryInformation:             { g_FuncRecs[E_HeapQueryInformation].bTrace = bTrace; } break;
        case FUNC_HeapReAlloc:                      { g_FuncRecs[E_HeapReAlloc].bTrace = bTrace; } break;
        case FUNC_HeapSetInformation:               { g_FuncRecs[E_HeapSetInformation].bTrace = bTrace; } break;
        case FUNC_HeapSize:                         { g_FuncRecs[E_HeapSize].bTrace = bTrace; } break;
        case FUNC_HeapUnlock:                       { g_FuncRecs[E_HeapUnlock].bTrace = bTrace; } break;
        case FUNC_HeapValidate:                     { g_FuncRecs[E_HeapValidate].bTrace = bTrace; } break;
        case FUNC_HeapWalk:                         { g_FuncRecs[E_HeapWalk].bTrace = bTrace; } break;
        // memoryapi.h
        case FUNC_CreateFileMappingA:               { g_FuncRecs[E_CreateFileMappingA].bTrace = bTrace; } break;
        case FUNC_CreateFileMappingW:               { g_FuncRecs[E_CreateFileMappingW].bTrace = bTrace; } break;
        case FUNC_FlushViewOfFile:                  { g_FuncRecs[E_FlushViewOfFile].bTrace = bTrace; } break;
        case FUNC_MapViewOfFile:                    { g_FuncRecs[E_MapViewOfFile].bTrace = bTrace; } break;
        case FUNC_MapViewOfFileEx:                  { g_FuncRecs[E_MapViewOfFileEx].bTrace = bTrace; } break;
        case FUNC_OpenFileMappingA:                 { g_FuncRecs[E_OpenFileMappingA].bTrace = bTrace; } break;
        case FUNC_OpenFileMappingW:                 { g_FuncRecs[E_OpenFileMappingW].bTrace = bTrace; } break;
        case FUNC_UnmapViewOfFile:                  { g_FuncRecs[E_UnmapViewOfFile].bTrace = bTrace; } break;
        case FUNC_VirtualAlloc:                     { g_FuncRecs[E_VirtualAlloc].bTrace = bTrace; } break;
        case FUNC_VirtualAllocEx:                   { g_FuncRecs[E_VirtualAllocEx].bTrace = bTrace; } break;
        case FUNC_VirtualFree:                      { g_FuncRecs[E_VirtualFree].bTrace = bTrace; } break;
        case FUNC_VirtualFreeEx:                    { g_FuncRecs[E_VirtualFreeEx].bTrace = bTrace; } break;
        case FUNC_VirtualLock:                      { g_FuncRecs[E_VirtualLock].bTrace = bTrace; } break;
        case FUNC_VirtualProtect:                   { g_FuncRecs[E_VirtualProtect].bTrace = bTrace; } break;
        case FUNC_VirtualProtectEx:                 { g_FuncRecs[E_VirtualProtectEx].bTrace = bTrace; } break;
        case FUNC_VirtualQuery:                     { g_FuncRecs[E_VirtualQuery].bTrace = bTrace; } break;
        case FUNC_VirtualQueryEx:                   { g_FuncRecs[E_VirtualQueryEx].bTrace = bTrace; } break;
        case FUNC_VirtualUnlock:                    { g_FuncRecs[E_VirtualUnlock].bTrace = bTrace; } break;
        // processthreadsapi.h
        case FUNC_CreateProcessA:                   { g_FuncRecs[E_CreateProcessA].bTrace = bTrace; } break;
        case FUNC_CreateProcessW:                   { g_FuncRecs[E_CreateProcessW].bTrace = bTrace; } break;
        case FUNC_CreateProcessAsUserA:             { g_FuncRecs[E_CreateProcessAsUserA].bTrace = bTrace; } break;
        case FUNC_CreateProcessAsUserW:             { g_FuncRecs[E_CreateProcessAsUserW].bTrace = bTrace; } break;
        case FUNC_CreateRemoteThread:               { g_FuncRecs[E_CreateRemoteThread].bTrace = bTrace; } break;
        case FUNC_CreateRemoteThreadEx:             { g_FuncRecs[E_CreateRemoteThreadEx].bTrace = bTrace; } break;
        case FUNC_CreateThread:                     { g_FuncRecs[E_CreateThread].bTrace = bTrace; } break;
        case FUNC_DeleteProcThreadAttributeList:    { g_FuncRecs[E_DeleteProcThreadAttributeList].bTrace = bTrace; } break;
        case FUNC_ExitProcess:                      { g_FuncRecs[E_ExitProcess].bTrace = bTrace; } break;
        case FUNC_ExitThread:                       { g_FuncRecs[E_ExitThread].bTrace = bTrace; } break;
        case FUNC_GetCurrentProcess:                { g_FuncRecs[E_GetCurrentProcess].bTrace = bTrace; } break;
        case FUNC_GetCurrentProcessId:              { g_FuncRecs[E_GetCurrentProcessId].bTrace = bTrace; } break;
        case FUNC_ResumeThread:                     { g_FuncRecs[E_ResumeThread].bTrace = bTrace; } break;
        case FUNC_SuspendThread:                    { g_FuncRecs[E_SuspendThread].bTrace = bTrace; } break;
        case FUNC_TerminateProcess:                 { g_FuncRecs[E_TerminateProcess].bTrace = bTrace; } break;
        case FUNC_TerminateThread:                  { g_FuncRecs[E_TerminateThread].bTrace = bTrace; } break;
        // profileapi.h
        case FUNC_QueryPerformanceCounter:          { g_FuncRecs[E_QueryPerformanceCounter].bTrace = bTrace; } break;
        case FUNC_QueryPerformanceFrequency:        { g_FuncRecs[E_QueryPerformanceFrequency].bTrace = bTrace; } break;
        // winuser.h
        case FUNC_AdjustWindowRect:                 { g_FuncRecs[E_AdjustWindowRect].bTrace = bTrace; } break;
        case FUNC_AdjustWindowRectEx:               { g_FuncRecs[E_AdjustWindowRectEx].bTrace = bTrace; } break;
        case FUNC_BeginPaint:                       { g_FuncRecs[E_BeginPaint].bTrace = bTrace; } break;
        case FUNC_ClientToScreen:                   { g_FuncRecs[E_ClientToScreen].bTrace = bTrace; } break;
        case FUNC_ClipCursor:                       { g_FuncRecs[E_ClipCursor].bTrace = bTrace; } break;
        case FUNC_CloseWindow:                      { g_FuncRecs[E_CloseWindow].bTrace = bTrace; } break;
        case FUNC_CreateWindowA:                    { g_FuncRecs[E_CreateWindowA].bTrace = bTrace; } break;
        case FUNC_CreateWindowW:                    { g_FuncRecs[E_CreateWindowW].bTrace = bTrace; } break;
        case FUNC_CreateWindowExA:                  { g_FuncRecs[E_CreateWindowExA].bTrace = bTrace; } break;
        case FUNC_CreateWindowExW:                  { g_FuncRecs[E_CreateWindowExW].bTrace = bTrace; } break;
        case FUNC_DefWindowProcA:                   { g_FuncRecs[E_DefWindowProcA].bTrace = bTrace; } break;
        case FUNC_DefWindowProcW:                   { g_FuncRecs[E_DefWindowProcW].bTrace = bTrace; } break;
        case FUNC_DestroyWindow:                    { g_FuncRecs[E_DestroyWindow].bTrace = bTrace; } break;
        case FUNC_DispatchMessageA:                 { g_FuncRecs[E_DispatchMessageA].bTrace = bTrace; } break;
        case FUNC_DispatchMessageW:                 { g_FuncRecs[E_DispatchMessageW].bTrace = bTrace; } break;
        case FUNC_EndPaint:                         { g_FuncRecs[E_EndPaint].bTrace = bTrace; } break;
        case FUNC_FillRect:                         { g_FuncRecs[E_FillRect].bTrace = bTrace; } break;
        case FUNC_GetClientRect:                    { g_FuncRecs[E_GetClientRect].bTrace = bTrace; } break;
        case FUNC_GetCursorPos:                     { g_FuncRecs[E_GetCursorPos].bTrace = bTrace; } break;
        case FUNC_GetDC:                            { g_FuncRecs[E_GetDC].bTrace = bTrace; } break;
        case FUNC_GetMessageA:                      { g_FuncRecs[E_GetMessageA].bTrace = bTrace; } break;
        case FUNC_GetMessageW:                      { g_FuncRecs[E_GetMessageW].bTrace = bTrace; } break;
        case FUNC_GetWindowRect:                    { g_FuncRecs[E_GetWindowRect].bTrace = bTrace; } break;
        case FUNC_MessageBoxA:                      { g_FuncRecs[E_MessageBoxA].bTrace = bTrace; } break;
        case FUNC_MessageBoxW:                      { g_FuncRecs[E_MessageBoxW].bTrace = bTrace; } break;
        case FUNC_MessageBoxExA:                    { g_FuncRecs[E_MessageBoxExA].bTrace = bTrace; } break;
        case FUNC_MessageBoxExW:                    { g_FuncRecs[E_MessageBoxExW].bTrace = bTrace; } break;
        case FUNC_PeekMessageA:                     { g_FuncRecs[E_PeekMessageA].bTrace = bTrace; } break;
        case FUNC_PeekMessageW:                     { g_FuncRecs[E_PeekMessageW].bTrace = bTrace; } break;
        case FUNC_PostMessageA:                     { g_FuncRecs[E_PostMessageA].bTrace = bTrace; } break;
        case FUNC_PostMessageW:                     { g_FuncRecs[E_PostMessageW].bTrace = bTrace; } break;
        case FUNC_PostQuitMessage:                  { g_FuncRecs[E_PostQuitMessage].bTrace = bTrace; } break;
        case FUNC_RegisterClassExA:                 { g_FuncRecs[E_RegisterClassExA].bTrace = bTrace; } break;
        case FUNC_RegisterClassExW:                 { g_FuncRecs[E_RegisterClassExW].bTrace = bTrace; } break;
        case FUNC_ReleaseDC:                        { g_FuncRecs[E_ReleaseDC].bTrace = bTrace; } break;
        case FUNC_ScreenToClient:                   { g_FuncRecs[E_ScreenToClient].bTrace = bTrace; } break;
        case FUNC_ShowCursor:                       { g_FuncRecs[E_ShowCursor].bTrace = bTrace; } break;
        case FUNC_ShowWindow:                       { g_FuncRecs[E_ShowWindow].bTrace = bTrace; } break;
        case FUNC_TranslateMessage:                 { g_FuncRecs[E_TranslateMessage].bTrace = bTrace; } break;
        case FUNC_UpdateWindow:                     { g_FuncRecs[E_UpdateWindow].bTrace = bTrace; } break;
        // stdio.h
        case FUNC_fopen:                            { g_FuncRecs[E_fopen].bTrace = bTrace; } break;
        case FUNC__wfopen:                          { g_FuncRecs[E__wfopen].bTrace = bTrace; } break;
        case FUNC_fclose:                           { g_FuncRecs[E_fclose].bTrace = bTrace; } break;
        // stdlib.h
        case FUNC_malloc:                           { g_FuncRecs[E_malloc].bTrace = bTrace; } break;
        case FUNC_free:                             { g_FuncRecs[E_free].bTrace = bTrace; } break;
    }
}

#include "inc/common.h"
#include "inc/hashes.h"
#include <stdio.h>

// Globals
extern      T_FuncRec g_FuncRecs[];
extern      T_WintraceOpts *pOpts;
BOOL        g_TraceAll = TRUE;
INT         g_CallLvl = 0;
T_FuncList  g_FuncList;

void
ShowDetails(T_WintraceOpts *Opts,
            DWORD Cnt)
{
    if (Opts->ShowProcessID)
        fprintf(Opts->OutputFile, "[%u] ", GetCurrentProcessId());
    if (Opts->ShowThreadID)
        fprintf(Opts->OutputFile, "<%u> ", GetCurrentThreadId());
    if (Opts->ShowFuncCount)
        fprintf(Opts->OutputFile, "(%u) ", Cnt);
}

DWORD
Djb2(LPSTR String)
{
    DWORD       Hash = 5381;
    INT         C = *String++;


    while (C)
    {
        Hash = ((Hash << 5) + Hash) + C;
        C = *String++;
    }

    return Hash;
}

BOOL
BeginTrace(E_FuncEnum FunctionName)
{
    T_FuncRec       *Func = &g_FuncRecs[FunctionName];


    if (Func->bTrace || g_TraceAll)
    {
        ShowDetails(pOpts, ++(Func->Cnt));
        fprintf(pOpts->OutputFile, "%*s%s", g_CallLvl++, "", Func->Name);
        return TRUE;
    }

    return FALSE;
}

void
InitFuncRecs()
{
    DWORD       Hash;
    INT         I;


    if (pOpts->TraceList[0][0])
    {
        g_TraceAll = FALSE;

        for (I = 0; I < 32 && pOpts->TraceList[I]; I++)
        {
            Hash = Djb2(pOpts->TraceList[I]);

            switch (Hash)
            {
                case FUNC_AdjustWindowRect:                 { g_FuncRecs[E_AdjustWindowRect].bTrace = TRUE; } break;
                case FUNC_AdjustWindowRectEx:               { g_FuncRecs[E_AdjustWindowRectEx].bTrace = TRUE; } break;
                case FUNC_BeginPaint:                       { g_FuncRecs[E_BeginPaint].bTrace = TRUE; } break;
                case FUNC_ClientToScreen:                   { g_FuncRecs[E_ClientToScreen].bTrace = TRUE; } break;
                case FUNC_ClipCursor:                       { g_FuncRecs[E_ClipCursor].bTrace = TRUE; } break;
                case FUNC_CloseWindow:                      { g_FuncRecs[E_CloseWindow].bTrace = TRUE; } break;
                case FUNC_CreateWindowA:                    { g_FuncRecs[E_CreateWindowA].bTrace = TRUE; } break;
                case FUNC_CreateWindowW:                    { g_FuncRecs[E_CreateWindowW].bTrace = TRUE; } break;
                case FUNC_CreateWindowExA:                  { g_FuncRecs[E_CreateWindowExA].bTrace = TRUE; } break;
                case FUNC_CreateWindowExW:                  { g_FuncRecs[E_CreateWindowExW].bTrace = TRUE; } break;
                case FUNC_DefWindowProc:                    { g_FuncRecs[E_DefWindowProc].bTrace = TRUE; } break;
                case FUNC_DestroyWindow:                    { g_FuncRecs[E_DestroyWindow].bTrace = TRUE; } break;
                case FUNC_DispatchMessageA:                 { g_FuncRecs[E_DispatchMessageA].bTrace = TRUE; } break;
                case FUNC_DispatchMessageW:                 { g_FuncRecs[E_DispatchMessageW].bTrace = TRUE; } break;
                case FUNC_EndPaint:                         { g_FuncRecs[E_EndPaint].bTrace = TRUE; } break;
                case FUNC_FillRect:                         { g_FuncRecs[E_FillRect].bTrace = TRUE; } break;
                case FUNC_GetClientRect:                    { g_FuncRecs[E_GetClientRect].bTrace = TRUE; } break;
                case FUNC_GetCursorPos:                     { g_FuncRecs[E_GetCursorPos].bTrace = TRUE; } break;
                case FUNC_GetDC:                            { g_FuncRecs[E_GetDC].bTrace = TRUE; } break;
                case FUNC_GetMessageA:                      { g_FuncRecs[E_GetMessageA].bTrace = TRUE; } break;
                case FUNC_GetMessageW:                      { g_FuncRecs[E_GetMessageW].bTrace = TRUE; } break;
                case FUNC_GetWindowRect:                    { g_FuncRecs[E_GetWindowRect].bTrace = TRUE; } break;
                case FUNC_MessageBoxA:                      { g_FuncRecs[E_MessageBoxA].bTrace = TRUE; } break;
                case FUNC_MessageBoxW:                      { g_FuncRecs[E_MessageBoxW].bTrace = TRUE; } break;
                case FUNC_MessageBoxExA:                    { g_FuncRecs[E_MessageBoxExA].bTrace = TRUE; } break;
                case FUNC_MessageBoxExW:                    { g_FuncRecs[E_MessageBoxExW].bTrace = TRUE; } break;
                case FUNC_PeekMessageA:                     { g_FuncRecs[E_PeekMessageA].bTrace = TRUE; } break;
                case FUNC_PeekMessageW:                     { g_FuncRecs[E_PeekMessageW].bTrace = TRUE; } break;
                case FUNC_PostMessageA:                     { g_FuncRecs[E_PostMessageA].bTrace = TRUE; } break;
                case FUNC_PostMessageW:                     { g_FuncRecs[E_PostMessageW].bTrace = TRUE; } break;
                case FUNC_PostQuitMessage:                  { g_FuncRecs[E_PostQuitMessage].bTrace = TRUE; } break;
                case FUNC_RegisterClassExA:                 { g_FuncRecs[E_RegisterClassExA].bTrace = TRUE; } break;
                case FUNC_RegisterClassExW:                 { g_FuncRecs[E_RegisterClassExW].bTrace = TRUE; } break;
                case FUNC_ReleaseDC:                        { g_FuncRecs[E_ReleaseDC].bTrace = TRUE; } break;
                case FUNC_ScreenToClient:                   { g_FuncRecs[E_ScreenToClient].bTrace = TRUE; } break;
                case FUNC_ShowCursor:                       { g_FuncRecs[E_ShowCursor].bTrace = TRUE; } break;
                case FUNC_ShowWindow:                       { g_FuncRecs[E_ShowWindow].bTrace = TRUE; } break;
                case FUNC_TranslateMessage:                 { g_FuncRecs[E_TranslateMessage].bTrace = TRUE; } break;
                case FUNC_UpdateWindow:                     { g_FuncRecs[E_UpdateWindow].bTrace = TRUE; } break;
                // heapapi.h
                case FUNC_GetProcessHeap:                   { g_FuncRecs[E_GetProcessHeap].bTrace = TRUE; } break;
                case FUNC_GetProcessHeaps:                  { g_FuncRecs[E_GetProcessHeaps].bTrace = TRUE; } break;
                case FUNC_HeapAlloc:                        { g_FuncRecs[E_HeapAlloc].bTrace = TRUE; } break;
                case FUNC_HeapCompact:                      { g_FuncRecs[E_HeapCompact].bTrace = TRUE; } break;
                case FUNC_HeapCreate:                       { g_FuncRecs[E_HeapCreate].bTrace = TRUE; } break;
                case FUNC_HeapDestroy:                      { g_FuncRecs[E_HeapDestroy].bTrace = TRUE; } break;
                case FUNC_HeapFree:                         { g_FuncRecs[E_HeapFree].bTrace = TRUE; } break;
                case FUNC_HeapLock:                         { g_FuncRecs[E_HeapLock].bTrace = TRUE; } break;
                case FUNC_HeapQueryInformation:             { g_FuncRecs[E_HeapQueryInformation].bTrace = TRUE; } break;
                case FUNC_HeapReAlloc:                      { g_FuncRecs[E_HeapReAlloc].bTrace = TRUE; } break;
                case FUNC_HeapSetInformation:               { g_FuncRecs[E_HeapSetInformation].bTrace = TRUE; } break;
                case FUNC_HeapSize:                         { g_FuncRecs[E_HeapSize].bTrace = TRUE; } break;
                case FUNC_HeapUnlock:                       { g_FuncRecs[E_HeapUnlock].bTrace = TRUE; } break;
                case FUNC_HeapValidate:                     { g_FuncRecs[E_HeapValidate].bTrace = TRUE; } break;
                case FUNC_HeapWalk:                         { g_FuncRecs[E_HeapWalk].bTrace = TRUE; } break;
                // processthreadspi.h
                case FUNC_CreateProcessA:                   { g_FuncRecs[E_CreateProcessA].bTrace = TRUE; } break;
                case FUNC_CreateProcessW:                   { g_FuncRecs[E_CreateProcessW].bTrace = TRUE; } break;
                case FUNC_CreateProcessAsUserA:             { g_FuncRecs[E_CreateProcessAsUserA].bTrace = TRUE; } break;
                case FUNC_CreateProcessAsUserW:             { g_FuncRecs[E_CreateProcessAsUserW].bTrace = TRUE; } break;
                case FUNC_CreateRemoteThread:               { g_FuncRecs[E_CreateRemoteThread].bTrace = TRUE; } break;
                case FUNC_CreateRemoteThreadEx:             { g_FuncRecs[E_CreateRemoteThreadEx].bTrace = TRUE; } break;
                case FUNC_CreateThread:                     { g_FuncRecs[E_CreateThread].bTrace = TRUE; } break;
                case FUNC_DeleteProcThreadAttributeList:    { g_FuncRecs[E_DeleteProcThreadAttributeList].bTrace = TRUE; } break;
                case FUNC_ExitProcess:                      { g_FuncRecs[E_ExitProcess].bTrace = TRUE; } break;
                case FUNC_ExitThread:                       { g_FuncRecs[E_ExitThread].bTrace = TRUE; } break;
                case FUNC_GetCurrentProcess:                { g_FuncRecs[E_GetCurrentProcess].bTrace = TRUE; } break;
                case FUNC_GetCurrentProcessId:              { g_FuncRecs[E_GetCurrentProcessId].bTrace = TRUE; } break;
                case FUNC_ResumeThread:                     { g_FuncRecs[E_ResumeThread].bTrace = TRUE; } break;
                case FUNC_SuspendThread:                    { g_FuncRecs[E_SuspendThread].bTrace = TRUE; } break;
                case FUNC_TerminateProcess:                 { g_FuncRecs[E_TerminateProcess].bTrace = TRUE; } break;
                case FUNC_TerminateThread:                  { g_FuncRecs[E_TerminateThread].bTrace = TRUE; } break;
                // fileapi.h
                case FUNC_CreateDirectoryA:                 { g_FuncRecs[E_CreateDirectoryA].bTrace = TRUE; } break;
                case FUNC_CreateDirectoryW:                 { g_FuncRecs[E_CreateDirectoryW].bTrace = TRUE; } break;
                case FUNC_CreateFileA:                      { g_FuncRecs[E_CreateFileA].bTrace = TRUE; } break;
                case FUNC_CreateFileW:                      { g_FuncRecs[E_CreateFileW].bTrace = TRUE; } break;
                case FUNC_DeleteFileA:                      { g_FuncRecs[E_DeleteFileA].bTrace = TRUE; } break;
                case FUNC_DeleteFileW:                      { g_FuncRecs[E_DeleteFileW].bTrace = TRUE; } break;
                case FUNC_GetFileSize:                      { g_FuncRecs[E_GetFileSize].bTrace = TRUE; } break;
                case FUNC_GetFileSizeEx:                    { g_FuncRecs[E_GetFileSizeEx].bTrace = TRUE; } break;
                case FUNC_GetFileType:                      { g_FuncRecs[E_GetFileType].bTrace = TRUE; } break;
                case FUNC_ReadFile:                         { g_FuncRecs[E_ReadFile].bTrace = TRUE; } break;
                case FUNC_ReadFileEx:                       { g_FuncRecs[E_ReadFileEx].bTrace = TRUE; } break;
                case FUNC_RemoveDirectoryA:                 { g_FuncRecs[E_RemoveDirectoryA].bTrace = TRUE; } break;
                case FUNC_RemoveDirectoryW:                 { g_FuncRecs[E_RemoveDirectoryW].bTrace = TRUE; } break;
                case FUNC_SetEndOfFile:                     { g_FuncRecs[E_SetEndOfFile].bTrace = TRUE; } break;
                case FUNC_SetFilePointer:                   { g_FuncRecs[E_SetFilePointer].bTrace = TRUE; } break;
                case FUNC_SetFilePointerEx:                 { g_FuncRecs[E_SetFilePointerEx].bTrace = TRUE; } break;
                case FUNC_WriteFile:                        { g_FuncRecs[E_WriteFile].bTrace = TRUE; } break;
                case FUNC_WriteFileEx:                      { g_FuncRecs[E_WriteFileEx].bTrace = TRUE; } break;
                // debugapi.h
                case FUNC_CheckRemoteDebuggerPresent:       { g_FuncRecs[E_CheckRemoteDebuggerPresent].bTrace = TRUE; } break;
                case FUNC_ContinueDebugEvent:               { g_FuncRecs[E_ContinueDebugEvent].bTrace = TRUE; } break;
                case FUNC_DebugActiveProcess:               { g_FuncRecs[E_DebugActiveProcess].bTrace = TRUE; } break;
                case FUNC_DebugActiveProcessStop:           { g_FuncRecs[E_DebugActiveProcessStop].bTrace = TRUE; } break;
                case FUNC_DebugBreak:                       { g_FuncRecs[E_DebugBreak].bTrace = TRUE; } break;
                case FUNC_IsDebuggerPresent:                { g_FuncRecs[E_IsDebuggerPresent].bTrace = TRUE; } break;
                case FUNC_OutputDebugStringA:               { g_FuncRecs[E_OutputDebugStringA].bTrace = TRUE; } break;
                case FUNC_OutputDebugStringW:               { g_FuncRecs[E_OutputDebugStringW].bTrace = TRUE; } break;
                case FUNC_WaitForDebugEvent:                { g_FuncRecs[E_WaitForDebugEvent].bTrace = TRUE; } break;
                // profileapi.h
                case FUNC_QueryPerformanceCounter:          { g_FuncRecs[E_QueryPerformanceCounter].bTrace = TRUE; } break;
                case FUNC_QueryPerformanceFrequency:        { g_FuncRecs[E_QueryPerformanceFrequency].bTrace = TRUE; } break;
                // memoryapi.h
                case FUNC_CreateFileMappingA:               { g_FuncRecs[E_CreateFileMappingA].bTrace = TRUE; } break;
                case FUNC_CreateFileMappingW:               { g_FuncRecs[E_CreateFileMappingW].bTrace = TRUE; } break;
                case FUNC_FlushViewOfFile:                  { g_FuncRecs[E_FlushViewOfFile].bTrace = TRUE; } break;
                case FUNC_MapViewOfFile:                    { g_FuncRecs[E_MapViewOfFile].bTrace = TRUE; } break;
                case FUNC_MapViewOfFileEx:                  { g_FuncRecs[E_MapViewOfFileEx].bTrace = TRUE; } break;
                case FUNC_OpenFileMappingA:                 { g_FuncRecs[E_OpenFileMappingA].bTrace = TRUE; } break;
                case FUNC_OpenFileMappingW:                 { g_FuncRecs[E_OpenFileMappingW].bTrace = TRUE; } break;
                case FUNC_UnmapViewOfFile:                  { g_FuncRecs[E_UnmapViewOfFile].bTrace = TRUE; } break;
                case FUNC_VirtualAlloc:                     { g_FuncRecs[E_VirtualAlloc].bTrace = TRUE; } break;
                case FUNC_VirtualAllocEx:                   { g_FuncRecs[E_VirtualAllocEx].bTrace = TRUE; } break;
                case FUNC_VirtualFree:                      { g_FuncRecs[E_VirtualFree].bTrace = TRUE; } break;
                case FUNC_VirtualFreeEx:                    { g_FuncRecs[E_VirtualFreeEx].bTrace = TRUE; } break;
                case FUNC_VirtualLock:                      { g_FuncRecs[E_VirtualLock].bTrace = TRUE; } break;
                case FUNC_VirtualProtect:                   { g_FuncRecs[E_VirtualProtect].bTrace = TRUE; } break;
                case FUNC_VirtualProtectEx:                 { g_FuncRecs[E_VirtualProtectEx].bTrace = TRUE; } break;
                case FUNC_VirtualQuery:                     { g_FuncRecs[E_VirtualQuery].bTrace = TRUE; } break;
                case FUNC_VirtualQueryEx:                   { g_FuncRecs[E_VirtualQueryEx].bTrace = TRUE; } break;
                case FUNC_VirtualUnlock:                    { g_FuncRecs[E_VirtualUnlock].bTrace = TRUE; } break;
            }
        }
    }
}

// *could use this param to check for if a function can report GetLastError()
void
EndTrace(E_FuncEnum FunctionName, // reserved for now*
         BOOL bError)
{
    g_CallLvl--;

    if (bError)
        fprintf(pOpts->OutputFile, "(ERROR: %u) ", GetLastError());
    fprintf(pOpts->OutputFile, "\r\n");
}

void
WriteFuncBuffer(char *Format,
                ...)
{
    T_FuncBuffer        *Buffer = &g_FuncList.Buffers[g_CallLvl];
    SIZE_T              Bytes;
    va_list             VarArgs;

    va_start(VarArgs, Format);

    Bytes = vsprintf(Buffer->Buff + Buffer->Pos, Format, VarArgs);
    Buffer->Pos += Bytes;

    va_end(VarArgs);
}

void
PrintFuncBuffer(T_FuncBuffer *Buffer)
{
    fprintf(pOpts->OutputFile, "%s", Buffer->Buff);
    Buffer->Pos = 0;
}


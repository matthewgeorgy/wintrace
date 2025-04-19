#include <common.h>
#include <hashes.h>
#include <stdio.h>

// Globals
extern      		T_FuncRec g_FuncRecs[];
extern      		T_WintraceOpts *pOpts;
BOOL        		g_TraceAll = TRUE;
INT         		g_CallLvl = 0;
T_FuncList  		g_FuncList;
extern HANDLE		g_Pipe;
extern HANDLE		g_Fence;

void
ShowDetails(T_WintraceOpts *Opts,
            DWORD Cnt)
{
    if (Opts->ShowProcessID)
        WriteFuncBuffer("[%u] ", GetCurrentProcessId());
    if (Opts->ShowThreadID)
        WriteFuncBuffer("<%u> ", GetCurrentThreadId());
    if (Opts->ShowFuncCount)
        WriteFuncBuffer("(%u) ", Cnt);
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


    if (Func->bTrace)
    {
        g_CallLvl++;
        ShowDetails(pOpts, ++(Func->Cnt));
        WriteFuncBuffer("%*c%s", g_CallLvl, ' ', Func->Name);
        return TRUE;
    }

    return FALSE;
}

void
InitFuncRecs()
{
    DWORD       Hash;
    INT         I;
    BOOL        bTrace = TRUE;
    DWORD       Offset = 0;


    // TODO: bulletproof this; do we need to have a ~ in front of every function
    // that we don't want to trace? How about something like /T:~Func1,Func2,...?
    if (pOpts->TraceList[0][0])
    {
        if (pOpts->TraceList[0][0] == '~')
        {
            bTrace = FALSE;
            for (I = 0; I < E_Count; I++)
            {
                g_FuncRecs[I].bTrace = TRUE;
            }
            Offset = 1;
        }

        for (I = 0; I < 32 && pOpts->TraceList[I]; I++)
        {
            Hash = Djb2(pOpts->TraceList[I] + Offset);

            switch (Hash)
            {
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
                // processthreadspi.h
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
                // profileapi.h
                case FUNC_QueryPerformanceCounter:          { g_FuncRecs[E_QueryPerformanceCounter].bTrace = bTrace; } break;
                case FUNC_QueryPerformanceFrequency:        { g_FuncRecs[E_QueryPerformanceFrequency].bTrace = bTrace; } break;
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
                // stdio.h
                case FUNC_fopen:                            { g_FuncRecs[E_fopen].bTrace = bTrace; } break;
                case FUNC__wfopen:                          { g_FuncRecs[E__wfopen].bTrace = bTrace; } break;
                case FUNC_fclose:                           { g_FuncRecs[E_fclose].bTrace = bTrace; } break;
                // stdlib.h
                case FUNC_malloc:                           { g_FuncRecs[E_malloc].bTrace = bTrace; } break;
                case FUNC_free:                             { g_FuncRecs[E_free].bTrace = bTrace; } break;
            }
        }
    }
    else
    {
        /* printf("here\n"); */
        for (I = 0; I < E_Count; I++)
        {
            g_FuncRecs[I].bTrace = TRUE;
        }
    }
}

// *could use this param to check for if a function can report GetLastError()
void
EndTrace(E_FuncEnum FunctionName, // reserved for now*
         BOOL bError)
{
    if (bError)
        WriteFuncBuffer(" (ERROR: %u) ", GetLastError());
    WriteFuncBuffer("\r\n");
    PrintFuncBuffer(&g_FuncList.Buffers[g_CallLvl--]);
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
	if (pOpts->UsePipes)
	{
		BOOL Status;
		DWORD NumRead;

		Status = WriteFile(g_Pipe, Buffer->Buff, 512, &NumRead, NULL);
		if (!Status)
		{
			printf("failed to write to pipe %d...!\r\n", GetLastError());
		}
		WaitForSingleObject(g_Fence, INFINITE);
	}
	else
	{
    	fprintf(pOpts->OutputFile, "%s", Buffer->Buff);
	}

    Buffer->Pos = 0;
}


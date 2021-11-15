#ifndef FUNC_RECORDS_H
#define FUNC_RECORDS_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

typedef struct _tag_FuncRec
{
	CHAR		*Name;
	DWORD		Cnt;
	BOOL		bTrace;
} T_FuncRec;

typedef enum _tag_FuncEnum
{
	// debugapi.h
	E_CheckRemoteDebuggerPresent,
	E_ContinueDebugEvent,
	E_DebugActiveProcess,
	E_DebugActiveProcessStop,
	E_DebugBreak,
	E_IsDebuggerPresent,
	E_OutputDebugStringA,
	E_OutputDebugStringW,
	E_WaitForDebugEvent,
	// fileapi.h
	E_CreateDirectoryA,
	E_CreateDirectoryW,
	E_CreateFileA,
	E_CreateFileW,
	E_DeleteFileA,
	E_DeleteFileW,
	E_GetFileSize,
	E_GetFileSizeEx,
	E_GetFileType,
	E_ReadFile,
	E_ReadFileEx,
	E_RemoveDirectoryA,
	E_RemoveDirectoryW,
	E_SetEndOfFile,
	E_SetFilePointer,
	E_SetFilePointerEx,
	E_WriteFile,
	E_WriteFileEx,
	// heapapi.h
	E_GetProcessHeap,
	E_GetProcessHeaps,
	E_HeapAlloc,
	E_HeapCompact,
	E_HeapCreate,
	E_HeapDestroy,
	E_HeapFree,
	E_HeapLock,
	E_HeapQueryInformation,
	E_HeapReAlloc,
	E_HeapSetInformation,
	E_HeapSize,
	E_HeapUnlock,
	E_HeapValidate,
	E_HeapWalk,
	// memoryapi.h
	E_CreateFileMappingA,
	E_CreateFileMappingW,
	E_FlushViewOfFile,
	E_MapViewOfFile,
	E_MapViewOfFileEx,
	E_OpenFileMappingA,
	E_OpenFileMappingW,
	E_UnmapViewOfFile,
	E_VirtualAlloc,
	E_VirtualAllocEx,
	E_VirtualFree,
	E_VirtualFreeEx,
	E_VirtualLock,
	E_VirtualProtect,
	E_VirtualProtectEx,
	E_VirtualQuery,
	E_VirtualQueryEx,
	E_VirtualUnlock,
	// processthreadsapi.h
	E_CreateProcessA,
	E_CreateProcessW,
	E_CreateProcessAsUserA,
	E_CreateProcessAsUserW,
	E_CreateRemoteThread,
	E_CreateRemoteThreadEx,
	E_CreateThread,
	E_DeleteProcThreadAttributeList,
	E_ExitProcess,
	E_ExitThread,
	E_GetCurrentProcess,
	E_GetCurrentProcessId,
	E_ResumeThread,
	E_SuspendThread,
	E_TerminateProcess,
	E_TerminateThread,
	// profileapi.h
	E_QueryPerformanceCounter,
	E_QueryPerformanceFrequency,
	// winuser.h
	E_AdjustWindowRect,
	E_AdjustWindowRectEx,
	E_BeginPaint,
	E_ClientToScreen,
	E_ClipCursor,
	E_CloseWindow,
	E_CreateWindowA,
	E_CreateWindowW,
	E_CreateWindowExA,
	E_CreateWindowExW,
	E_DefWindowProc,
	E_DestroyWindow,
	E_DispatchMessageA,
	E_DispatchMessageW,
	E_EndPaint,
	E_FillRect,
	E_GetClientRect,
	E_GetCursorPos,
	E_GetDC,
	E_GetMessageA,
	E_GetMessageW,
	E_GetWindowRect,
	E_MessageBoxA,
	E_MessageBoxW,
	E_MessageBoxExA,
	E_MessageBoxExW,
	E_PeekMessageA,
	E_PeekMessageW,
	E_PostMessageA,
	E_PostMessageW,
	E_PostQuitMessage,
	E_RegisterClassExA,
	E_RegisterClassExW,
	E_ReleaseDC,
	E_ScreenToClient,
	E_ShowCursor,
	E_ShowWindow,
	E_TranslateMessage,
	E_UpdateWindow,
	E_Count
} E_FuncEnum;

#endif // FUNC_RECORDS_H

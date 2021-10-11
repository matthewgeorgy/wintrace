#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

LPSTR Funcs[] =
{
	// winuser.h
	"AdjustWindowRect",
	"AdjustWindowRectEx",
	"BeginPaint",
	"ClientToScreen",
	"ClipCursor",
	"CloseWindow",
	"CreateWindowA",
	"CreateWindowW",
	"CreateWindowExA",
	"CreateWindowExW",
	"DefWindowProc",
	"DestroyWindow",
	"DispatchMessageA",
	"DispatchMessageW",
	"EndPaint",
	"FillRect",
	"GetClientRect",
	"GetCursorPos",
	"GetDC",
	"GetMessage",
	"GetWindowRect",
	"MessageBoxA",
	"MessageBoxW",
	"MessageBoxExA",
	"MessageBoxExW",
	"PeekMessageA",
	"PeekMessageW",
	"PostMessageA",
	"PostMessageW",
	"PostQuitMessage",
	"RegisterClassExA",
	"RegisterClassExW",
	"ReleaseDC",
	"ScreenToClient",
	"ShowCursor",
	"ShowWindow",
	"TranslateMessage",
	"UpdateWindow",
	// heapapi.h
	"GetProcessHeap",
    "GetProcessHeaps",
    "HeapAlloc",
    "HeapCompact",
    "HeapCreate",
    "HeapDestroy",
    "HeapFree",
    "HeapLock",
    "HeapQueryInformation",
    "HeapReAlloc",
    "HeapSetInformation",
    "HeapSize",
    "HeapUnlock",
    "HeapValidate",
    "HeapWalk",
	// processthreadsapi.h
	"CreateProcessA",
	"CreateProcessW",
	"CreateProcessAsUserA",
	"CreateProcessAsUserW",
	"CreateRemoteThread",
	"CreateRemoteThreadEx",
	"CreateThread",
	"DeleteProcThreadAttributeList",
	"ExitProcess",
	"ExitThread",
	"GetCurrentProcess",
	"GetCurrentProcessId",
	"ResumeThread",
	"SuspendThread",
	"TerminateProcess",
	"TerminateThread",
};


DWORD
Djb2(LPSTR String)
{
	DWORD		Hash = 5381;
	INT			C;


	while (C = *String++)
		Hash = ((Hash << 5) + Hash) + C;

	return Hash;
}

int
main(void)
{
	HANDLE		HashFile;
	SIZE_T		FuncsLen = sizeof(Funcs) / sizeof(Funcs[0]);
	SIZE_T		StrLen;
	INT			I;
	CHAR		Str[256];


	HashFile = CreateFile("w:\\wintrace\\dll\\inc\\hashes.h", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	for (I = 0; I < FuncsLen; I++)
	{
		sprintf(Str, "#define FUNC_%s %u\n", Funcs[I], Djb2(Funcs[I]));
		StrLen = strlen(Str);
		WriteFile(HashFile, Str, StrLen, NULL, NULL);
	}

	CloseHandle(HashFile);

	return 0;
}

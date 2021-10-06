#include "wt_winuser.h"
#include <stdio.h>

int WINAPI
WtMessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
	int			Ret;
	FARPROC		_MessageBoxA;

	_MessageBoxA = GetProcAddress(GetModuleHandle("User32.dll"), "MessageBoxA");
	Ret = MessageBoxA(hWnd, lpText, lpCaption, uType);
	printf("MessageBoxA(0x%p, \"%s\", \"%s\", %u) = %d\n", hWnd, lpText, lpCaption, uType, Ret);
	return Ret;
}


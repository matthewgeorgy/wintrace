#include "wt_winuser.h"
#include <stdio.h>

int WINAPI
WtMessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
	int					Ret;
	static DWORD		Cnt;

	printf("[%u] MessageBoxA(0x%p, \"%s\", \"%s\", %u)", Cnt++, hWnd, lpText, lpCaption, uType);
	Ret = MessageBoxA(hWnd, lpText, lpCaption, uType);
	printf(" = %d\n", Ret);
	return Ret;
}


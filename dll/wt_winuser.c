#include "inc/wt_winuser.h"
#include <stdio.h>

extern T_WINTRACEOPTS      *pOpts;

int WINAPI
WtMessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
    int                 Ret;
    static DWORD        Cnt;


    if (pOpts->ShowFuncCount)
        printf("[%u] ", Cnt);
    printf("MessageBoxA(0x%p, \"%s\", \"%s\", %u)", hWnd, lpText, lpCaption, uType);
    Ret = MessageBoxA(hWnd, lpText, lpCaption, uType);
    printf(" = %d\n", Ret);

    Cnt++;
    return Ret;
}


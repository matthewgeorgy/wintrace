#include "inc/wt_processthreadsapi.h"
#include <stdio.h>

extern T_WINTRACEOPTS      *pOpts;

HANDLE
WtGetCurrentProcess(void)
{
    HANDLE              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    printf("GetCurrentProcess()");
    Ret = GetCurrentProcess();
    printf(" = 0x%p\n", Ret);

    return Ret;
}

DWORD
WtGetCurrentProcessId(void)
{
    DWORD Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    printf("GetCurrentProcessId()");
    Ret = GetCurrentProcessId();
    printf(" = %u\n", Ret);

    return Ret;
}


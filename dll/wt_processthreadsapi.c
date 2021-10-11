#include "inc/wt_processthreadsapi.h"
#include <stdio.h>

extern T_WINTRACEOPTS      *pOpts;

HANDLE
WtGetCurrentProcess(void)
{
    HANDLE              Ret;
    static DWORD        Cnt;


    if (pOpts->ShowProcessID)
        printf("[%u] ", GetCurrentProcessId());
    if (pOpts->ShowThreadID)
        printf("<%u> ", GetCurrentThreadId());
    if (pOpts->ShowFuncCount)
        printf("(%u) ", ++Cnt);
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


    if (pOpts->ShowProcessID)
        printf("[%u] ", GetCurrentProcessId());
    if (pOpts->ShowThreadID)
        printf("<%u> ", GetCurrentThreadId());
    if (pOpts->ShowFuncCount)
        printf("(%u) ", ++Cnt);
    printf("GetCurrentProcessId()");
    Ret = GetCurrentProcessId();
    printf(" = %u\n", Ret);

    return Ret;
}


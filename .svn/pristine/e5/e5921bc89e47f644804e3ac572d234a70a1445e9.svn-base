#include "wt_processthreadsapi.h"
#include <stdio.h>

HANDLE
WtGetCurrentProcess(void)
{
    HANDLE              Ret;
    static DWORD        Cnt;

    
    Ret = GetCurrentProcess();
    printf("[%u] GetCurrentProcess() = 0x%p\n", Cnt++, Ret);

    return Ret;
}

DWORD
WtGetCurrentProcessId(void)
{
    DWORD Ret;
    static DWORD        Cnt;


    Ret = GetCurrentProcessId();
    printf("[%u] GetCurrentProcessId() = %u\n", Cnt++, Ret);

    return Ret;
}
    

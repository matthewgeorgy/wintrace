#include "inc/common.h"
#include <stdio.h>

void
ShowDetails(T_WINTRACEOPTS *pOpts,
            DWORD Cnt)
{
    if (pOpts->ShowProcessID)
        printf("[%u] ", GetCurrentProcessId());
    if (pOpts->ShowThreadID)
        printf("<%u> ", GetCurrentThreadId());
    if (pOpts->ShowFuncCount)
        printf("(%u) ", Cnt);
}

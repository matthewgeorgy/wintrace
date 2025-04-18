#include "inc/common.h"
#include <stdio.h>

void
ShowDetails(T_WINTRACE_OPTS *pOpts,
            DWORD Cnt)
{
    if (pOpts->ShowProcessID)
        fprintf(pOpts->OutputFile, "[%u] ", GetCurrentProcessId());
    if (pOpts->ShowThreadID)
        fprintf(pOpts->OutputFile, "<%u> ", GetCurrentThreadId());
    if (pOpts->ShowFuncCount)
        fprintf(pOpts->OutputFile, "(%u) ", Cnt);
}


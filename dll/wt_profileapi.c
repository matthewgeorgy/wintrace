#include "inc/wt_profileapi.h"

extern T_WINTRACE_OPTS *pOpts;

BOOL
WtQueryPerformanceCounter(
  LARGE_INTEGER *lpPerformanceCount
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "QueryPerformanceCounter(0x%p)", lpPerformanceCount);
    Ret = QueryPerformanceCounter(lpPerformanceCount);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtQueryPerformanceFrequency(
  LARGE_INTEGER *lpFrequency
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "QueryPerformanceFrequency(0x%p)", lpFrequency);
    Ret = QueryPerformanceFrequency(lpFrequency);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}


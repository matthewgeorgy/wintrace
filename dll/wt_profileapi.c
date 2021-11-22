#include "inc/wt_profileapi.h"

extern T_WintraceOpts *pOpts;

BOOL
WtQueryPerformanceCounter(
  LARGE_INTEGER *lpPerformanceCount
)
{
    BOOL        Ret;


    if (BeginTrace(E_QueryPerformanceCounter))
    {
        fprintf(pOpts->OutputFile, "(0x%p)", lpPerformanceCount);
        Ret = QueryPerformanceCounter(lpPerformanceCount);
        fprintf(pOpts->OutputFile, " = %d", Ret);
        EndTrace(E_QueryPerformanceCounter, Ret == FALSE);
    }
    else
        Ret = QueryPerformanceCounter(lpPerformanceCount);

    return Ret;
}

BOOL
WtQueryPerformanceFrequency(
  LARGE_INTEGER *lpFrequency
)
{
    BOOL        Ret;


    if (BeginTrace(E_QueryPerformanceFrequency))
    {
        fprintf(pOpts->OutputFile, "(0x%p)", lpFrequency);
        Ret = QueryPerformanceFrequency(lpFrequency);
        fprintf(pOpts->OutputFile, " = %d", Ret);
        EndTrace(E_QueryPerformanceFrequency, Ret == FALSE);
    }
    else
        Ret = QueryPerformanceFrequency(lpFrequency);

    return Ret;
}


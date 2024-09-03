#include <win32/wt_profileapi.h>

extern T_WintraceOpts		*pOpts;

BOOL
WtQueryPerformanceCounter(
	PLARGE_INTEGER lpPerformanceCount
)
{
	BOOL Ret;

	if (BeginTrace(E_QueryPerformanceCounter))
	{
		WriteFuncBuffer("(0x%p)", lpPerformanceCount);
		Ret = QueryPerformanceCounter(lpPerformanceCount);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_QueryPerformanceCounter, FALSE);
	}
	else
	{
		Ret = QueryPerformanceCounter(lpPerformanceCount);
	}

	return (Ret);
}

BOOL
WtQueryPerformanceFrequency(
	PLARGE_INTEGER lpFrequency
)
{
	BOOL Ret;

	if (BeginTrace(E_QueryPerformanceFrequency))
	{
		WriteFuncBuffer("(0x%p)", lpFrequency);
		Ret = QueryPerformanceFrequency(lpFrequency);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_QueryPerformanceFrequency, FALSE);
	}
	else
	{
		Ret = QueryPerformanceFrequency(lpFrequency);
	}

	return (Ret);
}


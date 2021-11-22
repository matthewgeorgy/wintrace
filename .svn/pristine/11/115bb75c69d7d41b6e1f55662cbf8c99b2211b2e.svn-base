#include "inc/wt_debugapi.h"

extern T_WintraceOpts *pOpts;

BOOL
WtCheckRemoteDebuggerPresent(
  HANDLE hProcess,
  PBOOL pbDebuggerPresent
)
{
    BOOL		Ret;


    if (BeginTrace(E_CheckRemoteDebuggerPresent))
	{
		fprintf(pOpts->OutputFile, "(0x%p, 0x%p)", hProcess, pbDebuggerPresent);
		Ret = CheckRemoteDebuggerPresent(hProcess, pbDebuggerPresent);
		fprintf(pOpts->OutputFile, " = %d\n", Ret);
	}
	else
		Ret = CheckRemoteDebuggerPresent(hProcess, pbDebuggerPresent);

    return Ret;
}

BOOL
WtContinueDebugEvent(
  DWORD dwProcessId,
  DWORD dwThreadId,
  DWORD dwContinueStatus
)
{
    BOOL		Ret;


    if (BeginTrace(E_ContinueDebugEvent))
	{
		fprintf(pOpts->OutputFile, "(%u, %u, %u)", dwProcessId, dwThreadId, dwContinueStatus);
		Ret = ContinueDebugEvent(dwProcessId, dwThreadId, dwContinueStatus);
		fprintf(pOpts->OutputFile, " = %d\n", Ret);
	}
	else
		Ret = ContinueDebugEvent(dwProcessId, dwThreadId, dwContinueStatus);

    return Ret;
}

BOOL
WtDebugActiveProcess(
  DWORD dwProcessId
)
{
    BOOL		Ret;


    if (BeginTrace(E_DebugActiveProcess))
	{
		fprintf(pOpts->OutputFile, "(%u)", dwProcessId);
		Ret = DebugActiveProcess(dwProcessId);
		fprintf(pOpts->OutputFile, " = %d\n", Ret);
	}
	else
		Ret = DebugActiveProcess(dwProcessId);

    return Ret;
}

BOOL
WtDebugActiveProcessStop(
  DWORD dwProcessId
)
{
    BOOL		Ret;


	if (BeginTrace(E_DebugActiveProcessStop))
	{
		fprintf(pOpts->OutputFile, "(%u)", dwProcessId);
		Ret = DebugActiveProcessStop(dwProcessId);
		fprintf(pOpts->OutputFile, " = %d\n", Ret);
	}
	else
		Ret = DebugActiveProcessStop(dwProcessId);

    return Ret;
}

void
WtDebugBreak()
{
    if (BeginTrace(E_DebugBreak))
    	fprintf(pOpts->OutputFile, "() = VOID\n");
    DebugBreak();
}

BOOL
WtIsDebuggerPresent()
{
    BOOL		Ret;


	if (BeginTrace(E_IsDebuggerPresent))
	{
		fprintf(pOpts->OutputFile, "()");
		Ret = IsDebuggerPresent();
		fprintf(pOpts->OutputFile, " = %d\n", Ret);
	}
	else
		Ret = IsDebuggerPresent();

    return Ret;
}

void
WtOutputDebugStringA(
  LPCSTR lpOutputString
)
{
	if (BeginTrace(E_OutputDebugStringA))
    	fprintf(pOpts->OutputFile, "(\"%s\") = VOID\n", lpOutputString);
    OutputDebugStringA(lpOutputString);
}

void
WtOutputDebugStringW(
  LPCWSTR lpOutputString
)
{
	if (BeginTrace(E_OutputDebugStringW))
    	fprintf(pOpts->OutputFile, "(\"%ws\") = VOID\n", lpOutputString);
    OutputDebugStringW(lpOutputString);
}

BOOL
WtWaitForDebugEvent(
  LPDEBUG_EVENT lpDebugEvent,
  DWORD         dwMilliseconds
)
{
    BOOL		Ret;


	if (BeginTrace(E_WaitForDebugEvent))
	{
		fprintf(pOpts->OutputFile, "(0x%p, %u)", lpDebugEvent, dwMilliseconds);
		Ret = WaitForDebugEvent(lpDebugEvent, dwMilliseconds);
		fprintf(pOpts->OutputFile, " = %d\n", Ret);
	}
	else
		Ret = WaitForDebugEvent(lpDebugEvent, dwMilliseconds);

    return Ret;
}

// Only in Win10!
/* BOOL */
/* WtWaitForDebugEventEx( */
/*   LPDEBUG_EVENT lpDebugEvent, */
/*   DWORD         dwMilliseconds */
/* ) */
/* { */
/*     BOOL                Ret; */
/*     static DWORD        Cnt; */


/*     ShowDetails(pOpts, ++Cnt); */
/*     fprintf(pOpts->OutputFile, "WaitForDebugEventEx(0x%p, %u)", lpDebugEvent, dwMilliseconds); */
/*     Ret = WaitForDebugEventEx(lpDebugEvent, dwMilliseconds); */
/*     fprintf(pOpts->OutputFile, " = %d\n", Ret); */

/*     return Ret; */
/* } */


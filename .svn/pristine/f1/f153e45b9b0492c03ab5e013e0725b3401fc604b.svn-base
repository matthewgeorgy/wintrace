#include "inc/wt_debugapi.h"

extern T_WintraceOpts *pOpts;

BOOL
WtCheckRemoteDebuggerPresent(
  HANDLE hProcess,
  PBOOL pbDebuggerPresent
)
{
    BOOL        Ret;


    if (BeginTrace(E_CheckRemoteDebuggerPresent))
    {
        WriteFuncBuffer("(0x%p, 0x%p)", hProcess, pbDebuggerPresent);
        Ret = CheckRemoteDebuggerPresent(hProcess, pbDebuggerPresent);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_CheckRemoteDebuggerPresent, Ret == FALSE);
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
    BOOL        Ret;


    if (BeginTrace(E_ContinueDebugEvent))
    {
        WriteFuncBuffer("(%u, %u, %u)", dwProcessId, dwThreadId, dwContinueStatus);
        Ret = ContinueDebugEvent(dwProcessId, dwThreadId, dwContinueStatus);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_ContinueDebugEvent, Ret == FALSE);
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
    BOOL        Ret;


    if (BeginTrace(E_DebugActiveProcess))
    {
        WriteFuncBuffer("(%u)", dwProcessId);
        Ret = DebugActiveProcess(dwProcessId);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_DebugActiveProcess, Ret == FALSE);
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
    BOOL        Ret;


    if (BeginTrace(E_DebugActiveProcessStop))
    {
        WriteFuncBuffer("(%u)", dwProcessId);
        Ret = DebugActiveProcessStop(dwProcessId);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_DebugActiveProcessStop, Ret == FALSE);
    }
    else
        Ret = DebugActiveProcessStop(dwProcessId);

    return Ret;
}

void
WtDebugBreak()
{
    if (BeginTrace(E_DebugBreak))
    {
        WriteFuncBuffer("() = VOID");
        EndTrace(E_DebugBreak, FALSE);
    }
    DebugBreak();
}

BOOL
WtIsDebuggerPresent()
{
    BOOL        Ret;


    if (BeginTrace(E_IsDebuggerPresent))
    {
        WriteFuncBuffer("()");
        Ret = IsDebuggerPresent();
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_IsDebuggerPresent, FALSE);
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
    {
        WriteFuncBuffer("(\"%s\") = VOID", lpOutputString);
        EndTrace(E_OutputDebugStringA, FALSE);
    }
    OutputDebugStringA(lpOutputString);
}

void
WtOutputDebugStringW(
  LPCWSTR lpOutputString
)
{
    if (BeginTrace(E_OutputDebugStringW))
    {
        WriteFuncBuffer("(\"%ws\") = VOID", lpOutputString);
        EndTrace(E_OutputDebugStringW, FALSE);
    }
    OutputDebugStringW(lpOutputString);
}

BOOL
WtWaitForDebugEvent(
  LPDEBUG_EVENT lpDebugEvent,
  DWORD         dwMilliseconds
)
{
    BOOL        Ret;


    if (BeginTrace(E_WaitForDebugEvent))
    {
        WriteFuncBuffer("(0x%p, %u)", lpDebugEvent, dwMilliseconds);
        Ret = WaitForDebugEvent(lpDebugEvent, dwMilliseconds);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_WaitForDebugEvent, Ret == FALSE);
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
/*     WriteFuncBuffer("WaitForDebugEventEx(0x%p, %u)", lpDebugEvent, dwMilliseconds); */
/*     Ret = WaitForDebugEventEx(lpDebugEvent, dwMilliseconds); */
/*     WriteFuncBuffer(" = %d", Ret); */

/*     return Ret; */
/* } */


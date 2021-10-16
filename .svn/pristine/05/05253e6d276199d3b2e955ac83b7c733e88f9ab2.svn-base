#include "inc/wt_debugapi.h"

extern T_WINTRACE_OPTS *pOpts;

BOOL
WtCheckRemoteDebuggerPresent(
  HANDLE hProcess,
  PBOOL pbDebuggerPresent
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "CheckRemoteDebuggerPresent(0x%p, 0x%p)", hProcess, pbDebuggerPresent);
    Ret = CheckRemoteDebuggerPresent(hProcess, pbDebuggerPresent);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtContinueDebugEvent(
  DWORD dwProcessId,
  DWORD dwThreadId,
  DWORD dwContinueStatus
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "ContinueDebugEvent(%u, %u, %u)", dwProcessId, dwThreadId, dwContinueStatus);
    Ret = ContinueDebugEvent(dwProcessId, dwThreadId, dwContinueStatus);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtDebugActiveProcess(
  DWORD dwProcessId
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "DebugActiveProcess(%u)", dwProcessId);
    Ret = DebugActiveProcess(dwProcessId);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtDebugActiveProcessStop(
  DWORD dwProcessId
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "DebugActiveProcessStop(%u)", dwProcessId);
    Ret = DebugActiveProcessStop(dwProcessId);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

void
WtDebugBreak()
{
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "DebugBreak() = VOID\n");
    DebugBreak();
}

BOOL
WtIsDebuggerPresent()
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "IsDebuggerPresent()");
    Ret = IsDebuggerPresent();
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

void
WtOutputDebugStringA(
  LPCSTR lpOutputString
)
{
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "OutputDebugStringA(\"%s\") = VOID\n", lpOutputString);
    OutputDebugStringA(lpOutputString);
}

void
WtOutputDebugStringW(
  LPCWSTR lpOutputString
)
{
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "OutputDebugStringW(\"%ws\") = VOID\n", lpOutputString);
    OutputDebugStringW(lpOutputString);
}

BOOL
WtWaitForDebugEvent(
  LPDEBUG_EVENT lpDebugEvent,
  DWORD         dwMilliseconds
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "WaitForDebugEvent(0x%p, %u)", lpDebugEvent, dwMilliseconds);
    Ret = WaitForDebugEvent(lpDebugEvent, dwMilliseconds);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

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

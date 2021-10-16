#include "inc/wt_processthreadsapi.h"
#include <stdio.h>

extern T_WINTRACEOPTS      *pOpts;

BOOL
WtCreateProcessA(
  LPCSTR                lpApplicationName,
  LPSTR                 lpCommandLine,
  LPSECURITY_ATTRIBUTES lpProcessAttributes,
  LPSECURITY_ATTRIBUTES lpThreadAttributes,
  BOOL                  bInheritHandles,
  DWORD                 dwCreationFlags,
  LPVOID                lpEnvironment,
  LPCSTR                lpCurrentDirectory,
  LPSTARTUPINFOA        lpStartupInfo,
  LPPROCESS_INFORMATION lpProcessInformation
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(stderr, "CreateProcessA(\"%s\", \"%s\", 0x%p, 0x%p, %d, %u, 0x%p, \"%s\", 0x%p, 0x%p", lpApplicationName, lpCommandLine,
            lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory,
            lpStartupInfo, lpProcessInformation);
    fprintf(stderr, ")");
    Ret = CreateProcessA(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
            dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
    fprintf(stderr, " = %d\n", Ret);

    return Ret;
}

BOOL
WtCreateProcessW(
  LPCWSTR               lpApplicationName,
  LPWSTR                lpCommandLine,
  LPSECURITY_ATTRIBUTES lpProcessAttributes,
  LPSECURITY_ATTRIBUTES lpThreadAttributes,
  BOOL                  bInheritHandles,
  DWORD                 dwCreationFlags,
  LPVOID                lpEnvironment,
  LPCWSTR               lpCurrentDirectory,
  LPSTARTUPINFOW        lpStartupInfo,
  LPPROCESS_INFORMATION lpProcessInformation
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(stderr, "CreateProcessW(\"%ws\", \"%ws\", 0x%p, 0x%p, %d, %u, 0x%p, \"%ws\", 0x%p, 0x%p", lpApplicationName, lpCommandLine,
            lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory,
            lpStartupInfo, lpProcessInformation);
    fprintf(stderr, ")");
    Ret = CreateProcessW(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
            dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
    fprintf(stderr, " = %d\n", Ret);

    return Ret;
}

BOOL
WtCreateProcessAsUserA(
  HANDLE                hToken,
  LPCSTR                lpApplicationName,
  LPSTR                 lpCommandLine,
  LPSECURITY_ATTRIBUTES lpProcessAttributes,
  LPSECURITY_ATTRIBUTES lpThreadAttributes,
  BOOL                  bInheritHandles,
  DWORD                 dwCreationFlags,
  LPVOID                lpEnvironment,
  LPCSTR                lpCurrentDirectory,
  LPSTARTUPINFOA        lpStartupInfo,
  LPPROCESS_INFORMATION lpProcessInformation
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(stderr, "CreateProcessAsUserA(0x%p, \"%s\", \"%s\", 0x%p, 0x%p, %d, %u, 0x%p, \"%s\", 0x%p, 0x%p", hToken, lpApplicationName, lpCommandLine,
            lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory,
            lpStartupInfo, lpProcessInformation);
    fprintf(stderr, ")");
    Ret = CreateProcessAsUserA(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
            dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
    fprintf(stderr, " = %d\n", Ret);

    return Ret;
}

BOOL WtCreateProcessAsUserW(
  HANDLE                hToken,
  LPCWSTR               lpApplicationName,
  LPWSTR                lpCommandLine,
  LPSECURITY_ATTRIBUTES lpProcessAttributes,
  LPSECURITY_ATTRIBUTES lpThreadAttributes,
  BOOL                  bInheritHandles,
  DWORD                 dwCreationFlags,
  LPVOID                lpEnvironment,
  LPCWSTR               lpCurrentDirectory,
  LPSTARTUPINFOW        lpStartupInfo,
  LPPROCESS_INFORMATION lpProcessInformation
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(stderr, "CreateProcessAsUserW(0x%p, \"%ws\", \"%ws\", 0x%p, 0x%p, %d, %u, 0x%p, \"%ws\", 0x%p, 0x%p", hToken, lpApplicationName, lpCommandLine,
            lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory,
            lpStartupInfo, lpProcessInformation);
    fprintf(stderr, ")");
    Ret = CreateProcessAsUserW(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
            dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
    fprintf(stderr, " = %d\n", Ret);

    return Ret;
}

HANDLE
WtCreateRemoteThread(
  HANDLE                 hProcess,
  LPSECURITY_ATTRIBUTES  lpThreadAttributes,
  SIZE_T                 dwStackSize,
  LPTHREAD_START_ROUTINE lpStartAddress,
  LPVOID                 lpParameter,
  DWORD                  dwCreationFlags,
  LPDWORD                lpThreadId
)
{
    HANDLE              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(stderr, "CreateRemoteThread(0x%p, 0x%p, %u, 0x%p, 0x%p, %u, 0x%p)", hProcess, lpThreadAttributes, dwStackSize,
            lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);
    Ret = CreateRemoteThread(hProcess, lpThreadAttributes, dwStackSize,
            lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);
    fprintf(stderr, " = 0x%p\n", Ret);

    return Ret;
}

HANDLE
WtCreateRemoteThreadEx(
  HANDLE                       hProcess,
  LPSECURITY_ATTRIBUTES        lpThreadAttributes,
  SIZE_T                       dwStackSize,
  LPTHREAD_START_ROUTINE       lpStartAddress,
  LPVOID                       lpParameter,
  DWORD                        dwCreationFlags,
  LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList,
  LPDWORD                      lpThreadId
)
{
    HANDLE              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(stderr, "CreateRemoteThreadEx(0x%p, 0x%p, %u, 0x%p, 0x%p, %u, 0x%p, 0x%p)", hProcess, lpThreadAttributes, dwStackSize,
            lpStartAddress, lpParameter, dwCreationFlags, lpAttributeList, lpThreadId);
    Ret = CreateRemoteThreadEx(hProcess, lpThreadAttributes, dwStackSize,
            lpStartAddress, lpParameter, dwCreationFlags, lpAttributeList, lpThreadId);
    fprintf(stderr, " = 0x%p\n", Ret);

    return Ret;
}

HANDLE
WtCreateThread(
  LPSECURITY_ATTRIBUTES   lpThreadAttributes,
  SIZE_T                  dwStackSize,
  LPTHREAD_START_ROUTINE  lpStartAddress,
  __drv_aliasesMem LPVOID lpParameter,
  DWORD                   dwCreationFlags,
  LPDWORD                 lpThreadId
)
{
    HANDLE              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(stderr, "CreateThread(0x%p, %u, 0x%p, 0x%p, %u, 0x%p)", lpThreadAttributes, dwStackSize, lpStartAddress,
            lpParameter, dwCreationFlags, lpThreadId);
    Ret = CreateThread(lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);
    fprintf(stderr, " = 0x%p\n", Ret);

    return Ret;
}

void
WtDeleteProcThreadAttributeList(
  LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList
)
{
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(stderr, "DeleteProcThreadAttributeList(0x%p)", lpAttributeList);
    DeleteProcThreadAttributeList(lpAttributeList);
    fprintf(stderr, " = VOID\n");
}

void
WtExitProcess(
  UINT uExitCode
)
{
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(stderr, "ExitProcess(%u)", uExitCode);
    ExitProcess(uExitCode);
    fprintf(stderr, " = VOID\n");
}


void
WtExitThread(
  DWORD dwExitCode
)
{
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(stderr, "ExitThread(%u)", dwExitCode);
    ExitThread(dwExitCode);
    fprintf(stderr, " = VOID\n");
}

HANDLE
WtGetCurrentProcess(void)
{
    HANDLE              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(stderr, "GetCurrentProcess()");
    Ret = GetCurrentProcess();
    fprintf(stderr, " = 0x%p\n", Ret);

    return Ret;
}

DWORD
WtGetCurrentProcessId(void)
{
    DWORD Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(stderr, "GetCurrentProcessId()");
    Ret = GetCurrentProcessId();
    fprintf(stderr, " = %u\n", Ret);

    return Ret;
}

DWORD
WtResumeThread(
  HANDLE hThread
)
{
    DWORD               Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(stderr, "ResumeThread(0x%p)", hThread);
    Ret = ResumeThread(hThread);
    fprintf(stderr, " = %u\n", Ret);

    return Ret;
}

DWORD
WtSuspendThread(
  HANDLE hThread
)
{
    DWORD               Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(stderr, "SuspendThread(0x%p)", hThread);
    Ret = SuspendThread(hThread);
    fprintf(stderr, " = %u\n", Ret);

    return Ret;
}

BOOL
WtTerminateProcess(
  HANDLE hProcess,
  UINT   uExitCode
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(stderr, "TerminateProcess(0x%p, %u)", hProcess, uExitCode);
    Ret = TerminateProcess(hProcess, uExitCode);
    fprintf(stderr, " = %d\n", Ret);

    return Ret;
}

BOOL
WtTerminateThread(
  HANDLE hThread,
  DWORD  dwExitCode
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(stderr, "TerminateThread(0x%p, %u)", hThread, dwExitCode);
    Ret = TerminateThread(hThread, dwExitCode);
    fprintf(stderr, " = %d\n", Ret);

    return Ret;
}


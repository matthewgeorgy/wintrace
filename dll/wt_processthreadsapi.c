#include "inc/wt_processthreadsapi.h"

extern T_WintraceOpts      *pOpts;

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
    BOOL        Ret;


    if (BeginTrace(E_CreateProcessA))
    {
        WriteFuncBuffer("(\"%s\", \"%s\", 0x%p, 0x%p, %d, %u, 0x%p, \"%s\", 0x%p, 0x%p)", lpApplicationName, lpCommandLine,
                lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory,
                lpStartupInfo, lpProcessInformation);
        Ret = CreateProcessA(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
                dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_CreateProcessA, Ret == FALSE);
    }
    else
    {
        Ret = CreateProcessA(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
                dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
    }

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
    BOOL        Ret;


    if (BeginTrace(E_CreateProcessW))
    {
        WriteFuncBuffer("(\"%ws\", \"%ws\", 0x%p, 0x%p, %d, %u, 0x%p, \"%ws\", 0x%p, 0x%p)", lpApplicationName, lpCommandLine,
                lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory,
                lpStartupInfo, lpProcessInformation);
        Ret = CreateProcessW(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
                dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_CreateProcessW, Ret == FALSE);
    }
    else
    {
        Ret = CreateProcessW(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
                dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
    }

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
    BOOL        Ret;


    if (BeginTrace(E_CreateProcessAsUserA))
    {
        WriteFuncBuffer("(0x%p, \"%s\", \"%s\", 0x%p, 0x%p, %d, %u, 0x%p, \"%s\", 0x%p, 0x%p)", hToken, lpApplicationName, lpCommandLine,
                lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory,
                lpStartupInfo, lpProcessInformation);
        Ret = CreateProcessAsUserA(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
                dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_CreateProcessAsUserA, Ret == FALSE);
    }
    else
    {
        Ret = CreateProcessAsUserA(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
                dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
    }

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
    BOOL        Ret;


    if (BeginTrace(E_CreateProcessAsUserW))
    {
        WriteFuncBuffer("(0x%p, \"%ws\", \"%ws\", 0x%p, 0x%p, %d, %u, 0x%p, \"%ws\", 0x%p, 0x%p)", hToken, lpApplicationName, lpCommandLine,
                lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory,
                lpStartupInfo, lpProcessInformation);
        Ret = CreateProcessAsUserW(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
                dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_CreateProcessAsUserW, Ret == FALSE);
    }
    else
    {
        Ret = CreateProcessAsUserW(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
                dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
    }

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
    HANDLE      Ret;


    if (BeginTrace(E_CreateRemoteThread))
    {
        WriteFuncBuffer("(0x%p, 0x%p, %u, 0x%p, 0x%p, %u, 0x%p)", hProcess, lpThreadAttributes, dwStackSize,
                lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);
        Ret = CreateRemoteThread(hProcess, lpThreadAttributes, dwStackSize,
                lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);
        WriteFuncBuffer(" = 0x%p", Ret);
        EndTrace(E_CreateRemoteThread, Ret == NULL);
    }
    else
    {
        Ret = CreateRemoteThread(hProcess, lpThreadAttributes, dwStackSize,
                lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);
    }

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
    HANDLE      Ret;


    if (BeginTrace(E_CreateRemoteThreadEx))
    {
        WriteFuncBuffer("(0x%p, 0x%p, %u, 0x%p, 0x%p, %u, 0x%p, 0x%p)", hProcess, lpThreadAttributes, dwStackSize,
                lpStartAddress, lpParameter, dwCreationFlags, lpAttributeList, lpThreadId);
        Ret = CreateRemoteThreadEx(hProcess, lpThreadAttributes, dwStackSize,
                lpStartAddress, lpParameter, dwCreationFlags, lpAttributeList, lpThreadId);
        WriteFuncBuffer(" = 0x%p", Ret);
        EndTrace(E_CreateRemoteThreadEx, Ret == NULL);
    }
    else
    {
        Ret = CreateRemoteThreadEx(hProcess, lpThreadAttributes, dwStackSize,
                lpStartAddress, lpParameter, dwCreationFlags, lpAttributeList, lpThreadId);
    }

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
    HANDLE      Ret;


    if (BeginTrace(E_CreateThread))
    {
        WriteFuncBuffer("(0x%p, %u, 0x%p, 0x%p, %u, 0x%p)", lpThreadAttributes, dwStackSize, lpStartAddress,
                lpParameter, dwCreationFlags, lpThreadId);
        Ret = CreateThread(lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);
        WriteFuncBuffer(" = 0x%p", Ret);
        EndTrace(E_CreateThread, Ret == NULL);
    }
    else
        Ret = CreateThread(lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);

    return Ret;
}

void
WtDeleteProcThreadAttributeList(
  LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList
)
{
    if (BeginTrace(E_DeleteProcThreadAttributeList))
    {
        WriteFuncBuffer("(0x%p) = VOID", lpAttributeList);
        EndTrace(E_DeleteProcThreadAttributeList, FALSE);
    }
    DeleteProcThreadAttributeList(lpAttributeList);
}

void
WtExitProcess(
  UINT uExitCode
)
{
    if (BeginTrace(E_ExitProcess))
    {
        WriteFuncBuffer("(%u) = VOID", uExitCode);
        EndTrace(E_ExitProcess, FALSE);
    }
    ExitProcess(uExitCode);
}


void
WtExitThread(
  DWORD dwExitCode
)
{
    if (BeginTrace(E_ExitThread))
    {
        WriteFuncBuffer("(%u) = VOID", dwExitCode);
        EndTrace(E_ExitThread, FALSE);
    }
    ExitThread(dwExitCode);
}

HANDLE
WtGetCurrentProcess(void)
{
    HANDLE      Ret;


    if (BeginTrace(E_GetCurrentProcess))
    {
        WriteFuncBuffer("()");
        Ret = GetCurrentProcess();
        WriteFuncBuffer(" = 0x%p", Ret);
        EndTrace(E_GetCurrentProcess, FALSE);
    }
    else
        Ret = GetCurrentProcess();

    return Ret;
}

DWORD
WtGetCurrentProcessId(void)
{
    DWORD       Ret;


    if (BeginTrace(E_GetCurrentProcessId))
    {
        WriteFuncBuffer("()");
        Ret = GetCurrentProcessId();
        WriteFuncBuffer(" = %u", Ret);
        EndTrace(E_GetCurrentProcessId, FALSE);
    }
    else
        Ret = GetCurrentProcessId();

    return Ret;
}

DWORD
WtResumeThread(
  HANDLE hThread
)
{
    DWORD       Ret;


    if (BeginTrace(E_ResumeThread))
    {
        WriteFuncBuffer("(0x%p)", hThread);
        Ret = ResumeThread(hThread);
        WriteFuncBuffer(" = %u", Ret);
        EndTrace(E_ResumeThread, Ret == (DWORD)-1);
    }
    else
        Ret = ResumeThread(hThread);

    return Ret;
}

DWORD
WtSuspendThread(
  HANDLE hThread
)
{
    DWORD       Ret;


    if (BeginTrace(E_SuspendThread))
    {
        WriteFuncBuffer("(0x%p)", hThread);
        Ret = SuspendThread(hThread);
        WriteFuncBuffer(" = %u", Ret);
        EndTrace(E_SuspendThread, Ret == (DWORD)-1);
    }
    else
        Ret = SuspendThread(hThread);

    return Ret;
}

BOOL
WtTerminateProcess(
  HANDLE hProcess,
  UINT   uExitCode
)
{
    BOOL        Ret;


    if (BeginTrace(E_TerminateProcess))
    {
        WriteFuncBuffer("(0x%p, %u)", hProcess, uExitCode);
        Ret = TerminateProcess(hProcess, uExitCode);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_TerminateProcess, Ret == FALSE);
    }
    else
        Ret = TerminateProcess(hProcess, uExitCode);

    return Ret;
}

BOOL
WtTerminateThread(
  HANDLE hThread,
  DWORD  dwExitCode
)
{
    BOOL        Ret;


    if (BeginTrace(E_TerminateThread))
    {
        WriteFuncBuffer("(0x%p, %u)", hThread, dwExitCode);
        Ret = TerminateThread(hThread, dwExitCode);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_TerminateThread, Ret == FALSE);
    }
    else
        Ret = TerminateThread(hThread, dwExitCode);

    return Ret;
}


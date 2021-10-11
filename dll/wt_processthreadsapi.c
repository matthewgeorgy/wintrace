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
    FARPROC             lpfnCreateProcessA;


    ShowDetails(pOpts, ++Cnt);
    lpfnCreateProcessA = GetProcAddress(GetModuleHandle("Kernel32.dll"), "CreateProcessA");
    printf("CreateProcessA(\"%s\", \"%s\", 0x%p, 0x%p, %d, %u, 0x%p, \"%s\", 0x%p, 0x%p", lpApplicationName, lpCommandLine,
            lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory,
            lpStartupInfo, lpProcessInformation);
    printf(")");
    Ret = lpfnCreateProcessA(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
            dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
    printf(" = %d\n", Ret);

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
    FARPROC             lpfnCreateProcessW;


    ShowDetails(pOpts, ++Cnt);
    lpfnCreateProcessW = GetProcAddress(GetModuleHandle("Kernel32.dll"), "CreateProcessW");
    printf("CreateProcessW(\"%ws\", \"%ws\", 0x%p, 0x%p, %d, %u, 0x%p, \"%ws\", 0x%p, 0x%p", lpApplicationName, lpCommandLine,
            lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory,
            lpStartupInfo, lpProcessInformation);
    printf(")");
    Ret = lpfnCreateProcessW(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
            dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
    printf(" = %d\n", Ret);

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
    FARPROC             lpfnCreateProcessAsUserA;


    ShowDetails(pOpts, ++Cnt);
    lpfnCreateProcessAsUserA = GetProcAddress(GetModuleHandle("Kernel32.dll"), "CreateProcessAsUserA");
    printf("CreateProcessAsUserA(0x%p, \"%s\", \"%s\", 0x%p, 0x%p, %d, %u, 0x%p, \"%s\", 0x%p, 0x%p", hToken, lpApplicationName, lpCommandLine,
            lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory,
            lpStartupInfo, lpProcessInformation);
    printf(")");
    Ret = lpfnCreateProcessAsUserA(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
            dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
    printf(" = %d\n", Ret);

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
    FARPROC             lpfnCreateProcessAsUserW;


    ShowDetails(pOpts, ++Cnt);
    lpfnCreateProcessAsUserW = GetProcAddress(GetModuleHandle("Kernel32.dll"), "CreateProcessAsUserW");
    printf("CreateProcessAsUserW(0x%p, \"%ws\", \"%ws\", 0x%p, 0x%p, %d, %u, 0x%p, \"%ws\", 0x%p, 0x%p", hToken, lpApplicationName, lpCommandLine,
            lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory,
            lpStartupInfo, lpProcessInformation);
    printf(")");
    Ret = lpfnCreateProcessAsUserW(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
            dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
    printf(" = %d\n", Ret);

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
    FARPROC             lpfnCreateRemoteThread;


    ShowDetails(pOpts, ++Cnt);
    lpfnCreateRemoteThread = GetProcAddress(GetModuleHandle("Kernel32.dll"), "CreateRemoteThread");
    printf("CreateRemoteThread(0x%p, 0x%p, %u, 0x%p, 0x%p, %u, 0x%p)", hProcess, lpThreadAttributes, dwStackSize,
            lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);
    Ret = lpfnCreateRemoteThread(hProcess, lpThreadAttributes, dwStackSize,
            lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);
    printf(" = 0x%p\n", Ret);

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
    FARPROC             lpfnCreateRemoteThreadEx;


    ShowDetails(pOpts, ++Cnt);
    lpfnCreateRemoteThreadEx = GetProcAddress(GetModuleHandle("Kernel32.dll"), "CreateRemoteThreadEx");
    printf("CreateRemoteThreadEx(0x%p, 0x%p, %u, 0x%p, 0x%p, %u, 0x%p, 0x%p)", hProcess, lpThreadAttributes, dwStackSize,
            lpStartAddress, lpParameter, dwCreationFlags, lpAttributeList, lpThreadId);
    Ret = lpfnCreateRemoteThreadEx(hProcess, lpThreadAttributes, dwStackSize,
            lpStartAddress, lpParameter, dwCreationFlags, lpAttributeList, lpThreadId);
    printf(" = 0x%p\n", Ret);

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
    FARPROC             lpfnCreateThread;


    ShowDetails(pOpts, ++Cnt);
    lpfnCreateThread = GetProcAddress(GetModuleHandle("Kernel32.dll"), "CreateThread");
    printf("CreateThread(0x%p, %u, 0x%p, 0x%p, %u, 0x%p)", lpThreadAttributes, dwStackSize, lpStartAddress,
            lpParameter, dwCreationFlags, lpThreadId);
    Ret = lpfnCreateThread(lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);
    printf(" = 0x%p\n", Ret);

    return Ret;
}

void
WtDeleteProcThreadAttributeList(
  LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList
)
{
    static DWORD        Cnt;
    FARPROC             lpfnDeleteProcThreadAttributeList;


    ShowDetails(pOpts, ++Cnt);
    lpfnDeleteProcThreadAttributeList = GetProcAddress(GetModuleHandle("Kernel32.dll"), "DeleteProcThreadAttributeList");
    printf("DeleteProcThreadAttributeList(0x%p)", lpAttributeList);
    lpfnDeleteProcThreadAttributeList(lpAttributeList);
    printf(" = VOID\n");
}

void
WtExitProcess(
  UINT uExitCode
)
{
    static DWORD        Cnt;
    FARPROC             lpfnExitProcess;


    ShowDetails(pOpts, ++Cnt);
    lpfnExitProcess = GetProcAddress(GetModuleHandle("Kernel32.dll"), "ExitProcess");
    printf("ExitProcess(%u)", uExitCode);
    lpfnExitProcess(uExitCode);
    printf(" = VOID\n");
}


void
WtExitThread(
  DWORD dwExitCode
)
{
    static DWORD        Cnt;
    FARPROC             lpfnExitThread;


    ShowDetails(pOpts, ++Cnt);
    lpfnExitThread = GetProcAddress(GetModuleHandle("Kernel32.dll"), "ExitThread");
    printf("ExitThread(%u)", dwExitCode);
    lpfnExitThread(dwExitCode);
    printf(" = VOID\n");
}

HANDLE
WtGetCurrentProcess(void)
{
    HANDLE              Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    printf("GetCurrentProcess()");
    Ret = GetCurrentProcess();
    printf(" = 0x%p\n", Ret);

    return Ret;
}

DWORD
WtGetCurrentProcessId(void)
{
    DWORD Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    printf("GetCurrentProcessId()");
    Ret = GetCurrentProcessId();
    printf(" = %u\n", Ret);

    return Ret;
}

DWORD
WtResumeThread(
  HANDLE hThread
)
{
    DWORD               Ret;
    static DWORD        Cnt;
    FARPROC             lpfnResumeThread;


    ShowDetails(pOpts, ++Cnt);
    lpfnResumeThread = GetProcAddress(GetModuleHandle("Kernel32.dll"), "ResumeThread");
    printf("ResumeThread(0x%p)", hThread);
    Ret = lpfnResumeThread(hThread);
    printf(" = %u\n", Ret);

    return Ret;
}

DWORD
WtSuspendThread(
  HANDLE hThread
)
{
    DWORD               Ret;
    static DWORD        Cnt;
    FARPROC             lpfnSuspendThread;


    ShowDetails(pOpts, ++Cnt);
    lpfnSuspendThread = GetProcAddress(GetModuleHandle("Kernel32.dll"), "SuspendThread");
    printf("SuspendThread(0x%p)", hThread);
    Ret = lpfnSuspendThread(hThread);
    printf(" = %u\n", Ret);

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
    FARPROC             lpfnTerminateProcess;


    ShowDetails(pOpts, ++Cnt);
    lpfnTerminateProcess = GetProcAddress(GetModuleHandle("Kernel32.dll"), "TerminateProcess");
    printf("TerminateProcess(0x%p, %u)", hProcess, uExitCode);
    Ret = lpfnTerminateProcess(hProcess, uExitCode);
    printf(" = %d\n", Ret);

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
    FARPROC             lpfnTerminateThread;


    ShowDetails(pOpts, ++Cnt);
    lpfnTerminateThread = GetProcAddress(GetModuleHandle("Kernel32.dll"), "TerminateThread");
    printf("TerminateThread(0x%p, %u)", hThread, dwExitCode);
    Ret = lpfnTerminateThread(hThread, dwExitCode);
    printf(" = %d\n", Ret);

    return Ret;
}


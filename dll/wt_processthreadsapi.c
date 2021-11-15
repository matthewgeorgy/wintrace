#include "inc/wt_processthreadsapi.h"
#include <stdio.h>

extern T_WINTRACE_OPTS      *pOpts;

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
    BOOL		Ret;


	if (BeginTrace(E_CreateProcessA))
	{
		fprintf(pOpts->OutputFile, "(\"%s\", \"%s\", 0x%p, 0x%p, %d, %u, 0x%p, \"%s\", 0x%p, 0x%p)", lpApplicationName, lpCommandLine,
				lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory,
				lpStartupInfo, lpProcessInformation);
		Ret = CreateProcessA(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
				dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
		fprintf(pOpts->OutputFile, " = %d\n", Ret);
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
    BOOL		Ret;


	if (BeginTrace(E_CreateProcessW))
	{
		fprintf(pOpts->OutputFile, "(\"%ws\", \"%ws\", 0x%p, 0x%p, %d, %u, 0x%p, \"%ws\", 0x%p, 0x%p)", lpApplicationName, lpCommandLine,
				lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory,
				lpStartupInfo, lpProcessInformation);
		Ret = CreateProcessW(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
				dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
		fprintf(pOpts->OutputFile, " = %d\n", Ret);
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
    BOOL		Ret;


	if (BeginTrace(E_CreateProcessAsUserA))
	{
    fprintf(pOpts->OutputFile, "(0x%p, \"%s\", \"%s\", 0x%p, 0x%p, %d, %u, 0x%p, \"%s\", 0x%p, 0x%p)", hToken, lpApplicationName, lpCommandLine,
            lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory,
            lpStartupInfo, lpProcessInformation);
    Ret = CreateProcessAsUserA(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
            dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);
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
    BOOL		Ret;


	if (BeginTrace(E_CreateProcessAsUserW))
	{
		fprintf(pOpts->OutputFile, "(0x%p, \"%ws\", \"%ws\", 0x%p, 0x%p, %d, %u, 0x%p, \"%ws\", 0x%p, 0x%p)", hToken, lpApplicationName, lpCommandLine,
				lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory,
				lpStartupInfo, lpProcessInformation);
		Ret = CreateProcessAsUserW(hToken, lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
				dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
		fprintf(pOpts->OutputFile, " = %d\n", Ret);
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
    HANDLE		Ret;


	if (BeginTrace(E_CreateRemoteThread))
	{
		fprintf(pOpts->OutputFile, "(0x%p, 0x%p, %u, 0x%p, 0x%p, %u, 0x%p)", hProcess, lpThreadAttributes, dwStackSize,
				lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);
		Ret = CreateRemoteThread(hProcess, lpThreadAttributes, dwStackSize,
				lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);
		fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);
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
    HANDLE		Ret;


	if (BeginTrace(E_CreateRemoteThreadEx))
	{
		fprintf(pOpts->OutputFile, "(0x%p, 0x%p, %u, 0x%p, 0x%p, %u, 0x%p, 0x%p)", hProcess, lpThreadAttributes, dwStackSize,
				lpStartAddress, lpParameter, dwCreationFlags, lpAttributeList, lpThreadId);
		Ret = CreateRemoteThreadEx(hProcess, lpThreadAttributes, dwStackSize,
				lpStartAddress, lpParameter, dwCreationFlags, lpAttributeList, lpThreadId);
		fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);
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
    HANDLE		Ret;


	if (BeginTrace(E_CreateThread))
	{
		fprintf(pOpts->OutputFile, "(0x%p, %u, 0x%p, 0x%p, %u, 0x%p)", lpThreadAttributes, dwStackSize, lpStartAddress,
				lpParameter, dwCreationFlags, lpThreadId);
		Ret = CreateThread(lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);
		fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);
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
		fprintf(pOpts->OutputFile, "(0x%p) = VOID\n", lpAttributeList);
	DeleteProcThreadAttributeList(lpAttributeList);
}

void
WtExitProcess(
  UINT uExitCode
)
{
	if (BeginTrace(E_ExitProcess))
    	fprintf(pOpts->OutputFile, "(%u) = VOID\n", uExitCode);
    ExitProcess(uExitCode);
}


void
WtExitThread(
  DWORD dwExitCode
)
{
	if (BeginTrace(E_ExitThread))
    	fprintf(pOpts->OutputFile, "(%u) = VOID\n", dwExitCode);
    ExitThread(dwExitCode);
}

HANDLE
WtGetCurrentProcess(void)
{
    HANDLE		Ret;


	if (BeginTrace(E_GetCurrentProcess))
	{
		fprintf(pOpts->OutputFile, "()");
		Ret = GetCurrentProcess();
		fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);
	}
	else
		Ret = GetCurrentProcess();

    return Ret;
}

DWORD
WtGetCurrentProcessId(void)
{
    DWORD		Ret;


	if (BeginTrace(E_GetCurrentProcessId))
	{
		fprintf(pOpts->OutputFile, "()");
		Ret = GetCurrentProcessId();
		fprintf(pOpts->OutputFile, " = %u\n", Ret);
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
    DWORD		Ret;


	if (BeginTrace(E_ResumeThread))
	{
		fprintf(pOpts->OutputFile, "(0x%p)", hThread);
		Ret = ResumeThread(hThread);
		fprintf(pOpts->OutputFile, " = %u\n", Ret);
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
    DWORD		Ret;


	if (BeginTrace(E_SuspendThread))
	{
		fprintf(pOpts->OutputFile, "(0x%p)", hThread);
		Ret = SuspendThread(hThread);
		fprintf(pOpts->OutputFile, " = %u\n", Ret);
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
    BOOL		Ret;


	if (BeginTrace(E_TerminateProcess))
	{
		fprintf(pOpts->OutputFile, "(0x%p, %u)", hProcess, uExitCode);
		Ret = TerminateProcess(hProcess, uExitCode);
		fprintf(pOpts->OutputFile, " = %d\n", Ret);
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
    BOOL		Ret;


	if (BeginTrace(E_TerminateThread))
	{
		fprintf(pOpts->OutputFile, "(0x%p, %u)", hThread, dwExitCode);
		Ret = TerminateThread(hThread, dwExitCode);
		fprintf(pOpts->OutputFile, " = %d\n", Ret);
	}
	else
		Ret = TerminateThread(hThread, dwExitCode);

    return Ret;
}


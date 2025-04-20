#include <win32/wt_syncapi.h>

extern T_WintraceOpts		*pOpts;

HANDLE
WtCreateMutexA(
	LPSECURITY_ATTRIBUTES lpMutexAttributes,
	BOOL bInitialOwner,
	LPCSTR lpName
)
{
	HANDLE Ret;

	if (BeginTrace(E_CreateMutexA))
	{
		WriteFuncBuffer("(0x%p, %d, \"%s\")", lpMutexAttributes, bInitialOwner, lpName);
		Ret = CreateMutexA(lpMutexAttributes, bInitialOwner, lpName);
		WriteFuncBuffer(" = 0x%p", Ret);
		EndTrace(E_CreateMutexA, FALSE);
	}
	else
	{
		Ret = CreateMutexA(lpMutexAttributes, bInitialOwner, lpName);
	}

	return (Ret);
}

HANDLE
WtCreateMutexW(
	LPSECURITY_ATTRIBUTES lpMutexAttributes,
	BOOL bInitialOwner,
	LPCWSTR lpName
)
{
	HANDLE Ret;

	if (BeginTrace(E_CreateMutexW))
	{
		WriteFuncBuffer("(0x%p, %d, \"%ws\")", lpMutexAttributes, bInitialOwner, lpName);
		Ret = CreateMutexW(lpMutexAttributes, bInitialOwner, lpName);
		WriteFuncBuffer(" = 0x%p", Ret);
		EndTrace(E_CreateMutexW, FALSE);
	}
	else
	{
		Ret = CreateMutexW(lpMutexAttributes, bInitialOwner, lpName);
	}

	return (Ret);
}

HANDLE
WtCreateMutexExA(
	LPSECURITY_ATTRIBUTES lpMutexAttributes,
	LPCSTR lpName,
	DWORD dwFlags,
	DWORD dwDesiredAccess
)
{
	HANDLE Ret;

	if (BeginTrace(E_CreateMutexExA))
	{
		WriteFuncBuffer("(0x%p, \"%s\", %u, %u)", lpMutexAttributes, lpName, dwFlags, dwDesiredAccess);
		Ret = CreateMutexExA(lpMutexAttributes, lpName, dwFlags, dwDesiredAccess);
		WriteFuncBuffer(" = 0x%p", Ret);
		EndTrace(E_CreateMutexExA, FALSE);
	}
	else
	{
		Ret = CreateMutexExA(lpMutexAttributes, lpName, dwFlags, dwDesiredAccess);
	}

	return (Ret);
}

HANDLE
WtCreateMutexExW(
	LPSECURITY_ATTRIBUTES lpMutexAttributes,
	LPCWSTR lpName,
	DWORD dwFlags,
	DWORD dwDesiredAccess
)
{
	HANDLE Ret;

	if (BeginTrace(E_CreateMutexExW))
	{
		WriteFuncBuffer("(0x%p, \"%ws\", %u, %u)", lpMutexAttributes, lpName, dwFlags, dwDesiredAccess);
		Ret = CreateMutexExW(lpMutexAttributes, lpName, dwFlags, dwDesiredAccess);
		WriteFuncBuffer(" = 0x%p", Ret);
		EndTrace(E_CreateMutexExW, FALSE);
	}
	else
	{
		Ret = CreateMutexExW(lpMutexAttributes, lpName, dwFlags, dwDesiredAccess);
	}

	return (Ret);
}

BOOL
WtReleaseMutex(
	HANDLE hMutex
)
{
	BOOL Ret;

	if (BeginTrace(E_ReleaseMutex))
	{
		WriteFuncBuffer("(0x%p)", hMutex);
		Ret = ReleaseMutex(hMutex);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_ReleaseMutex, FALSE);
	}
	else
	{
		Ret = ReleaseMutex(hMutex);
	}

	return (Ret);
}

HANDLE
WtCreateSemaphoreExW(
	LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
	LONG lInitialCount,
	LONG lMaximumCount,
	LPCWSTR lpName,
	DWORD dwFlags,
	DWORD dwDesiredAccess
)
{
	HANDLE Ret;

	if (BeginTrace(E_CreateSemaphoreExW))
	{
		WriteFuncBuffer("(0x%p, %d, %d, \"%ws\", %u, %u)", lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpName, dwFlags, dwDesiredAccess);
		Ret = CreateSemaphoreExW(lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpName, dwFlags, dwDesiredAccess);
		WriteFuncBuffer(" = 0x%p", Ret);
		EndTrace(E_CreateSemaphoreExW, FALSE);
	}
	else
	{
		Ret = CreateSemaphoreExW(lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpName, dwFlags, dwDesiredAccess);
	}

	return (Ret);
}

BOOL
WtReleaseSemaphore(
	HANDLE hSemaphore,
	LONG lReleaseCount,
	LPLONG lpPreviousCount
)
{
	BOOL Ret;

	if (BeginTrace(E_ReleaseSemaphore))
	{
		WriteFuncBuffer("(0x%p, %d, 0x%p)", hSemaphore, lReleaseCount, lpPreviousCount);
		Ret = ReleaseSemaphore(hSemaphore, lReleaseCount, lpPreviousCount);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_ReleaseSemaphore, FALSE);
	}
	else
	{
		Ret = ReleaseSemaphore(hSemaphore, lReleaseCount, lpPreviousCount);
	}

	return (Ret);
}

HANDLE
WtCreateEventA(
	LPSECURITY_ATTRIBUTES lpEventAttributes,
	BOOL bManualReset,
	BOOL bInitialState,
	LPCSTR lpName
)
{
	HANDLE Ret;

	if (BeginTrace(E_CreateEventA))
	{
		WriteFuncBuffer("(0x%p, %d, %d, \"%s\")", lpEventAttributes, bManualReset, bInitialState, lpName);
		Ret = CreateEventA(lpEventAttributes, bManualReset, bInitialState, lpName);
		WriteFuncBuffer(" = 0x%p", Ret);
		EndTrace(E_CreateEventA, FALSE);
	}
	else
	{
		Ret = CreateEventA(lpEventAttributes, bManualReset, bInitialState, lpName);
	}

	return (Ret);
}

HANDLE
WtCreateEventW(
	LPSECURITY_ATTRIBUTES lpEventAttributes,
	BOOL bManualReset,
	BOOL bInitialState,
	LPCWSTR lpName
)
{
	HANDLE Ret;

	if (BeginTrace(E_CreateEventW))
	{
		WriteFuncBuffer("(0x%p, %d, %d, \"%ws\")", lpEventAttributes, bManualReset, bInitialState, lpName);
		Ret = CreateEventW(lpEventAttributes, bManualReset, bInitialState, lpName);
		WriteFuncBuffer(" = 0x%p", Ret);
		EndTrace(E_CreateEventW, FALSE);
	}
	else
	{
		Ret = CreateEventW(lpEventAttributes, bManualReset, bInitialState, lpName);
	}

	return (Ret);
}

HANDLE
WtCreateEventExA(
	LPSECURITY_ATTRIBUTES lpEventAttributes,
	LPCSTR lpName,
	DWORD dwFlags,
	DWORD dwDesiredAccess
)
{
	HANDLE Ret;

	if (BeginTrace(E_CreateEventExA))
	{
		WriteFuncBuffer("(0x%p, \"%s\", %u, %u)", lpEventAttributes, lpName, dwFlags, dwDesiredAccess);
		Ret = CreateEventExA(lpEventAttributes, lpName, dwFlags, dwDesiredAccess);
		WriteFuncBuffer(" = 0x%p", Ret);
		EndTrace(E_CreateEventExA, FALSE);
	}
	else
	{
		Ret = CreateEventExA(lpEventAttributes, lpName, dwFlags, dwDesiredAccess);
	}

	return (Ret);
}

HANDLE
WtCreateEventExW(
	LPSECURITY_ATTRIBUTES lpEventAttributes,
	LPCWSTR lpName,
	DWORD dwFlags,
	DWORD dwDesiredAccess
)
{
	HANDLE Ret;

	if (BeginTrace(E_CreateEventExW))
	{
		WriteFuncBuffer("(0x%p, \"%ws\", %u, %u)", lpEventAttributes, lpName, dwFlags, dwDesiredAccess);
		Ret = CreateEventExW(lpEventAttributes, lpName, dwFlags, dwDesiredAccess);
		WriteFuncBuffer(" = 0x%p", Ret);
		EndTrace(E_CreateEventExW, FALSE);
	}
	else
	{
		Ret = CreateEventExW(lpEventAttributes, lpName, dwFlags, dwDesiredAccess);
	}

	return (Ret);
}

BOOL
WtSetEvent(
	HANDLE hEvent
)
{
	BOOL Ret;

	if (BeginTrace(E_SetEvent))
	{
		WriteFuncBuffer("(0x%p)", hEvent);
		Ret = SetEvent(hEvent);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_SetEvent, FALSE);
	}
	else
	{
		Ret = SetEvent(hEvent);
	}

	return (Ret);
}

BOOL
WtResetEvent(
	HANDLE hEvent
)
{
	BOOL Ret;

	if (BeginTrace(E_ResetEvent))
	{
		WriteFuncBuffer("(0x%p)", hEvent);
		Ret = ResetEvent(hEvent);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_ResetEvent, FALSE);
	}
	else
	{
		Ret = ResetEvent(hEvent);
	}

	return (Ret);
}

void
WtInitializeCriticalSection(
	LPCRITICAL_SECTION lpCriticalSection
)
{
	if (BeginTrace(E_InitializeCriticalSection))
	{
		WriteFuncBuffer("(0x%p)", lpCriticalSection);
		WriteFuncBuffer(" = VOID");
		EndTrace(E_InitializeCriticalSection, FALSE);
	}

	InitializeCriticalSection(lpCriticalSection);
}

void
WtEnterCriticalSection(
	LPCRITICAL_SECTION lpCriticalSection
)
{
	if (BeginTrace(E_EnterCriticalSection))
	{
		WriteFuncBuffer("(0x%p)", lpCriticalSection);
		WriteFuncBuffer(" = VOID");
		EndTrace(E_EnterCriticalSection, FALSE);
	}

	EnterCriticalSection(lpCriticalSection);
}

void
WtLeaveCriticalSection(
	LPCRITICAL_SECTION lpCriticalSection
)
{
	if (BeginTrace(E_LeaveCriticalSection))
	{
		WriteFuncBuffer("(0x%p)", lpCriticalSection);
		WriteFuncBuffer(" = VOID");
		EndTrace(E_LeaveCriticalSection, FALSE);
	}

	LeaveCriticalSection(lpCriticalSection);
}

BOOL
WtInitializeCriticalSectionAndSpinCount(
	LPCRITICAL_SECTION lpCriticalSection,
	DWORD dwSpinCount
)
{
	BOOL Ret;

	if (BeginTrace(E_InitializeCriticalSectionAndSpinCount))
	{
		WriteFuncBuffer("(0x%p, %u)", lpCriticalSection, dwSpinCount);
		Ret = InitializeCriticalSectionAndSpinCount(lpCriticalSection, dwSpinCount);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_InitializeCriticalSectionAndSpinCount, FALSE);
	}
	else
	{
		Ret = InitializeCriticalSectionAndSpinCount(lpCriticalSection, dwSpinCount);
	}

	return (Ret);
}

BOOL
WtInitializeCriticalSectionEx(
	LPCRITICAL_SECTION lpCriticalSection,
	DWORD dwSpinCount,
	DWORD Flags
)
{
	BOOL Ret;

	if (BeginTrace(E_InitializeCriticalSectionEx))
	{
		WriteFuncBuffer("(0x%p, %u, %u)", lpCriticalSection, dwSpinCount, Flags);
		Ret = InitializeCriticalSectionEx(lpCriticalSection, dwSpinCount, Flags);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_InitializeCriticalSectionEx, FALSE);
	}
	else
	{
		Ret = InitializeCriticalSectionEx(lpCriticalSection, dwSpinCount, Flags);
	}

	return (Ret);
}

DWORD
WtSetCriticalSectionSpinCount(
	LPCRITICAL_SECTION lpCriticalSection,
	DWORD dwSpinCount
)
{
	DWORD Ret;

	if (BeginTrace(E_SetCriticalSectionSpinCount))
	{
		WriteFuncBuffer("(0x%p, %u)", lpCriticalSection, dwSpinCount);
		Ret = SetCriticalSectionSpinCount(lpCriticalSection, dwSpinCount);
		WriteFuncBuffer(" = %u", Ret);
		EndTrace(E_SetCriticalSectionSpinCount, FALSE);
	}
	else
	{
		Ret = SetCriticalSectionSpinCount(lpCriticalSection, dwSpinCount);
	}

	return (Ret);
}

BOOL
WtTryEnterCriticalSection(
	LPCRITICAL_SECTION lpCriticalSection
)
{
	BOOL Ret;

	if (BeginTrace(E_TryEnterCriticalSection))
	{
		WriteFuncBuffer("(0x%p)", lpCriticalSection);
		Ret = TryEnterCriticalSection(lpCriticalSection);
		WriteFuncBuffer(" = %d", Ret);
		EndTrace(E_TryEnterCriticalSection, FALSE);
	}
	else
	{
		Ret = TryEnterCriticalSection(lpCriticalSection);
	}

	return (Ret);
}

void
WtDeleteCriticalSection(
	LPCRITICAL_SECTION lpCriticalSection
)
{
	if (BeginTrace(E_DeleteCriticalSection))
	{
		WriteFuncBuffer("(0x%p)", lpCriticalSection);
		WriteFuncBuffer(" = VOID");
		EndTrace(E_DeleteCriticalSection, FALSE);
	}

	DeleteCriticalSection(lpCriticalSection);
}

DWORD
WtWaitForSingleObject(
	HANDLE hHandle,
	DWORD dwMilliseconds
)
{
	DWORD Ret;

	if (BeginTrace(E_WaitForSingleObject))
	{
		WriteFuncBuffer("(0x%p, %u)", hHandle, dwMilliseconds);
		Ret = WaitForSingleObject(hHandle, dwMilliseconds);
		WriteFuncBuffer(" = %u", Ret);
		EndTrace(E_WaitForSingleObject, FALSE);
	}
	else
	{
		Ret = WaitForSingleObject(hHandle, dwMilliseconds);
	}

	return (Ret);
}

DWORD
WtWaitForSingleObjectEx(
	HANDLE hHandle,
	DWORD dwMilliseconds,
	BOOL bAlertable
)
{
	DWORD Ret;

	if (BeginTrace(E_WaitForSingleObjectEx))
	{
		WriteFuncBuffer("(0x%p, %u, %d)", hHandle, dwMilliseconds, bAlertable);
		Ret = WaitForSingleObjectEx(hHandle, dwMilliseconds, bAlertable);
		WriteFuncBuffer(" = %u", Ret);
		EndTrace(E_WaitForSingleObjectEx, FALSE);
	}
	else
	{
		Ret = WaitForSingleObjectEx(hHandle, dwMilliseconds, bAlertable);
	}

	return (Ret);
}

DWORD
WtWaitForMultipleObjectsEx(
	DWORD nCount,
	HANDLE *lpHandles,
	BOOL bWaitAll,
	DWORD dwMilliseconds,
	BOOL bAlertable
)
{
	DWORD Ret;

	if (BeginTrace(E_WaitForMultipleObjectsEx))
	{
		WriteFuncBuffer("(%u, 0x%p, %d, %u, %d)", nCount, *lpHandles, bWaitAll, dwMilliseconds, bAlertable);
		Ret = WaitForMultipleObjectsEx(nCount, *lpHandles, bWaitAll, dwMilliseconds, bAlertable);
		WriteFuncBuffer(" = %u", Ret);
		EndTrace(E_WaitForMultipleObjectsEx, FALSE);
	}
	else
	{
		Ret = WaitForMultipleObjectsEx(nCount, *lpHandles, bWaitAll, dwMilliseconds, bAlertable);
	}

	return (Ret);
}

DWORD
WtSleepEx(
	DWORD dwMilliseconds,
	BOOL bAlertable
)
{
	DWORD Ret;

	if (BeginTrace(E_SleepEx))
	{
		WriteFuncBuffer("(%u, %d)", dwMilliseconds, bAlertable);
		Ret = SleepEx(dwMilliseconds, bAlertable);
		WriteFuncBuffer(" = %u", Ret);
		EndTrace(E_SleepEx, FALSE);
	}
	else
	{
		Ret = SleepEx(dwMilliseconds, bAlertable);
	}

	return (Ret);
}


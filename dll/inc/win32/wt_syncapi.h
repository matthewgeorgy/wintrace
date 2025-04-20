#ifndef WT_SYNCAPI_H
#define WT_SYNCAPI_H

#include "common.h"

HANDLE WtCreateMutexA(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCSTR lpName);
HANDLE WtCreateMutexW(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCWSTR lpName);
HANDLE WtCreateMutexExA(LPSECURITY_ATTRIBUTES lpMutexAttributes, LPCSTR lpName, DWORD dwFlags, DWORD dwDesiredAccess);
HANDLE WtCreateMutexExW(LPSECURITY_ATTRIBUTES lpMutexAttributes, LPCWSTR lpName, DWORD dwFlags, DWORD dwDesiredAccess);
BOOL WtReleaseMutex(HANDLE hMutex);
HANDLE WtCreateSemaphoreExW(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes, LONG lInitialCount, LONG lMaximumCount, LPCWSTR lpName, DWORD dwFlags, DWORD dwDesiredAccess);
BOOL WtReleaseSemaphore(HANDLE hSemaphore, LONG lReleaseCount, LPLONG lpPreviousCount);
HANDLE WtCreateEventA(LPSECURITY_ATTRIBUTES lpEventAttributes, BOOL bManualReset, BOOL bInitialState, LPCSTR lpName);
HANDLE WtCreateEventW(LPSECURITY_ATTRIBUTES lpEventAttributes, BOOL bManualReset, BOOL bInitialState, LPCWSTR lpName);
HANDLE WtCreateEventExA(LPSECURITY_ATTRIBUTES lpEventAttributes, LPCSTR lpName, DWORD dwFlags, DWORD dwDesiredAccess);
HANDLE WtCreateEventExW(LPSECURITY_ATTRIBUTES lpEventAttributes, LPCWSTR lpName, DWORD dwFlags, DWORD dwDesiredAccess);
BOOL WtSetEvent(HANDLE hEvent);
BOOL WtResetEvent(HANDLE hEvent);
void WtInitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
void WtEnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
void WtLeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
BOOL WtInitializeCriticalSectionAndSpinCount(LPCRITICAL_SECTION lpCriticalSection, DWORD dwSpinCount);
BOOL WtInitializeCriticalSectionEx(LPCRITICAL_SECTION lpCriticalSection, DWORD dwSpinCount, DWORD Flags);
DWORD WtSetCriticalSectionSpinCount(LPCRITICAL_SECTION lpCriticalSection, DWORD dwSpinCount);
BOOL WtTryEnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
void WtDeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
DWORD WtWaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds);
DWORD WtWaitForSingleObjectEx(HANDLE hHandle, DWORD dwMilliseconds, BOOL bAlertable);
DWORD WtWaitForMultipleObjectsEx(DWORD nCount, HANDLE *lpHandles, BOOL bWaitAll, DWORD dwMilliseconds, BOOL bAlertable);
DWORD WtSleepEx(DWORD dwMilliseconds, BOOL bAlertable);

#endif // WT_SYNCAPI_H

#ifndef WT_DEBUGAPI_H
#define WT_DEBUGAPI_H

#include "common.h"

BOOL WtCheckRemoteDebuggerPresent(HANDLE hProcess, PBOOL pbDebuggerPresent);
BOOL WtContinueDebugEvent(DWORD dwProcessId, DWORD dwThreadId, DWORD dwContinueStatus);
BOOL WtDebugActiveProcess(DWORD dwProcessId);
BOOL WtDebugActiveProcessStop(DWORD dwProcessId);
void WtDebugBreak();
BOOL WtIsDebuggerPresent();
void WtOutputDebugStringA(LPCSTR lpOutputString);
void WtOutputDebugStringW(LPCWSTR lpOutputString);
BOOL WtWaitForDebugEvent(LPDEBUG_EVENT lpDebugEvent, DWORD dwMilliseconds);

#endif // WT_DEBUGAPI_H

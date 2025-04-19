#ifndef WT_WINUSER_H
#define WT_WINUSER_H

#include "common.h"

BOOL WtAdjustWindowRect(LPRECT lpRect, DWORD dwStyle, BOOL bMenu);
BOOL WtAdjustWindowRectEx(LPRECT lpRect, DWORD dwStyle, BOOL bMenu, DWORD dwExStyle);
HDC WtBeginPaint(HWND hWnd, LPPAINTSTRUCT lpPaint);
BOOL WtClientToScreen(HWND hWnd, LPPOINT lpPoint);
BOOL WtClipCursor(LPRECT lpRect);
BOOL WtCloseWindow(HWND hWnd);
HWND WtCreateWindowA(LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
HWND WtCreateWindowW(LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
HWND WtCreateWindowExA(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
HWND WtCreateWindowExW(DWORD dwExStyle, LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
LRESULT WtDefWindowProcA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
LRESULT WtDefWindowProcW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
BOOL WtDestroyWindow(HWND hWnd);
LRESULT WtDispatchMessageA(LPMSG lpMsg);
LRESULT WtDispatchMessageW(LPMSG lpMsg);
BOOL WtEndPaint(HWND hWnd, LPPAINTSTRUCT lpPaint);
int WtFillRect(HDC hDC, LPRECT lprc, HBRUSH hbr);
BOOL WtGetClientRect(HWND hWnd, LPRECT lpRect);
BOOL WtGetCursorPos(LPPOINT lpPoint);
HDC WtGetDC(HWND hWnd);
BOOL WtGetMessageA(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);
BOOL WtGetMessageW(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);
BOOL WtGetWindowRect(HWND hWnd, LPRECT lpRect);
int WtMessageBoxA(HWND hwnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);
int WtMessageBoxW(HWND hwnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType);
int WtMessageBoxExA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType, WORD wLanguageId);
int WtMessageBoxExW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType, WORD wLanguageId);
BOOL WtPeekMessageA(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg);
BOOL WtPeekMessageW(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg);
BOOL WtPostMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
BOOL WtPostMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
void WtPostQuitMessage(int nExitCode);
ATOM WtRegisterClassExA(LPWNDCLASSEXA unnamedParam1);
ATOM WtRegisterClassExW(LPWNDCLASSEXW unnamedParam1);
int WtReleaseDC(HWND hWnd, HDC hDC);
BOOL WtScreenToClient(HWND hWnd, LPPOINT lpPoint);
int WtShowCursor(BOOL bShow);
BOOL WtShowWindow(HWND hWnd, int nCmdShow);
BOOL WtTranslateMessage(LPMSG lpMsg);
BOOL WtUpdateWindow(HWND hWnd);

#endif // WT_WINUSER_H

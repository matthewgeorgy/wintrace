#ifndef WT_WINUSER_H
#define WT_WINUSER_H

#include "common.h"

BOOL WtAdjustWindowRect(
  LPRECT lpRect,
  DWORD  dwStyle,
  BOOL   bMenu
);

BOOL WtAdjustWindowRectEx(
  LPRECT lpRect,
  DWORD  dwStyle,
  BOOL   bMenu,
  DWORD  dwExStyle
);

HDC WtBeginPaint(
  HWND          hWnd,
  LPPAINTSTRUCT lpPaint
);

BOOL WtClientToScreen(
  HWND    hWnd,
  LPPOINT lpPoint
);

BOOL WtClipCursor( const RECT *lpRect
);

BOOL WtCloseWindow(
  HWND hWnd
);

HWND WtCreateWindowA(
    LPCSTR  lpClassName,
    LPCSTR  lpWindowName,
    DWORD  dwStyle,
    int  x,
    int  y,
    int  nWidth,
    int  nHeight,
    HWND hWndParent,
    HMENU  hMenu,
    HINSTANCE  hInstance,
    LPVOID lpParam
);

HWND WtCreateWindowW(
    LPCWSTR  lpClassName,
    LPCWSTR  lpWindowName,
    DWORD  dwStyle,
    int  x,
    int  y,
    int  nWidth,
    int  nHeight,
    HWND hWndParent,
    HMENU  hMenu,
    HINSTANCE  hInstance,
    LPVOID lpParam
);

HWND WtCreateWindowExA(
  DWORD     dwExStyle,
  LPCSTR    lpClassName,
  LPCSTR    lpWindowName,
  DWORD     dwStyle,
  int       X,
  int       Y,
  int       nWidth,
  int       nHeight,
  HWND      hWndParent,
  HMENU     hMenu,
  HINSTANCE hInstance,
  LPVOID    lpParam
);

HWND WtCreateWindowExW(
  DWORD     dwExStyle,
  LPCWSTR   lpClassName,
  LPCWSTR   lpWindowName,
  DWORD     dwStyle,
  int       X,
  int       Y,
  int       nWidth,
  int       nHeight,
  HWND      hWndParent,
  HMENU     hMenu,
  HINSTANCE hInstance,
  LPVOID    lpParam
);

LRESULT WtDefWindowProc(
  HWND   hWnd,
  UINT   Msg,
  WPARAM wParam,
  LPARAM lParam
);

BOOL WtDestroyWindow(
  HWND hWnd
);

LRESULT WtDispatchMessageA(
  const MSG *lpMsg
);

LRESULT WtDispatchMessageW(
  const MSG *lpMsg
);


BOOL WtEndPaint(
  HWND              hWnd,
  const PAINTSTRUCT *lpPaint
);

int WtFillRect(
  HDC        hDC,
  const RECT *lprc,
  HBRUSH     hbr
);

BOOL WtGetClientRect(
  HWND   hWnd,
  LPRECT lpRect
);

BOOL WtGetCursorPos(
  LPPOINT lpPoint
);

HDC WtGetDC(
  HWND hWnd
);

BOOL WtGetMessageA(
  LPMSG lpMsg,
  HWND  hWnd,
  UINT  wMsgFilterMin,
  UINT  wMsgFilterMax
);

BOOL WtGetMessageW(
  LPMSG lpMsg,
  HWND  hWnd,
  UINT  wMsgFilterMin,
  UINT  wMsgFilterMax
);

BOOL WtGetWindowRect(
  HWND   hWnd,
  LPRECT lpRect
);

int WINAPI WtMessageBoxA(HWND, LPCSTR, LPCSTR, UINT);

int WINAPI WtMessageBoxW(HWND, LPCWSTR, LPCWSTR, UINT);

int WtMessageBoxExA(
  HWND   hWnd,
  LPCSTR lpText,
  LPCSTR lpCaption,
  UINT   uType,
  WORD   wLanguageId
);

int WtMessageBoxExW(
  HWND    hWnd,
  LPCWSTR lpText,
  LPCWSTR lpCaption,
  UINT    uType,
  WORD    wLanguageId
);

BOOL WtPeekMessageA(
  LPMSG lpMsg,
  HWND  hWnd,
  UINT  wMsgFilterMin,
  UINT  wMsgFilterMax,
  UINT  wRemoveMsg
);

BOOL WtPeekMessageW(
  LPMSG lpMsg,
  HWND  hWnd,
  UINT  wMsgFilterMin,
  UINT  wMsgFilterMax,
  UINT  wRemoveMsg
);

BOOL WtPostMessageA(
  HWND   hWnd,
  UINT   Msg,
  WPARAM wParam,
  LPARAM lParam
);

BOOL WtPostMessageW(
  HWND   hWnd,
  UINT   Msg,
  WPARAM wParam,
  LPARAM lParam
);

void WtPostQuitMessage(
  int nExitCode
);

ATOM WtRegisterClassExA(
  const WNDCLASSEXA *unnamedParam1
);

ATOM WtRegisterClassExW(
  const WNDCLASSEXW *unnamedParam1
);

int WtReleaseDC(
  HWND hWnd,
  HDC  hDC
);

BOOL WtScreenToClient(
  HWND    hWnd,
  LPPOINT lpPoint
);

int WtShowCursor(
  BOOL bShow
);

BOOL WtShowWindow(
  HWND hWnd,
  int  nCmdShow
);

BOOL WtTranslateMessage(
  const MSG *lpMsg
);

BOOL WtUpdateWindow(
  HWND hWnd
);

#endif // WT_WINUSER_H


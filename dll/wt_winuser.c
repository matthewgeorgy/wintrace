#include "inc/wt_winuser.h"
#include <stdio.h>

extern T_WINTRACEOPTS      *pOpts;

BOOL
WtAdjustWindowRect(
  LPRECT lpRect,
  DWORD  dwStyle,
  BOOL   bMenu
)
{
    BOOL                Ret;
    static DWORD        Cnt;
    FARPROC             lpfnAdjustWindowRect;


    ShowDetails(pOpts, ++Cnt);
    lpfnAdjustWindowRect = GetProcAddress(GetModuleHandle("User32.dll"), "AdjustWindowRect");
    printf("AdjustWindowRect(0x%p, %u, %d)", lpRect, dwStyle, bMenu);
    Ret = lpfnAdjustWindowRect(lpRect, dwStyle, bMenu);
    printf(" = %d\n", Ret);

    return Ret;
}

BOOL
WtAdjustWindowRectEx(
  LPRECT lpRect,
  DWORD  dwStyle,
  BOOL   bMenu,
  DWORD  dwExStyle
)
{
    BOOL                Ret;
    static DWORD        Cnt;
    FARPROC             lpfnAdjustWindowRectEx;


    ShowDetails(pOpts, ++Cnt);
    lpfnAdjustWindowRectEx = GetProcAddress(GetModuleHandle("User32.dll"), "AdjustWindowRectEx");
    printf("AdjustWindowRectEx(0x%p, %u, %d, %u)", lpRect, dwStyle, bMenu, dwExStyle);
    Ret = lpfnAdjustWindowRectEx(lpRect, dwStyle, bMenu, dwExStyle);
    printf(" = %d\n", Ret);

    return Ret;
}

HDC
WtBeginPaint(
  HWND          hWnd,
  LPPAINTSTRUCT lpPaint
)
{
    HDC                 Ret;
    static DWORD        Cnt;
    FARPROC             lpfnBeginPaint;


    ShowDetails(pOpts, ++Cnt);
    lpfnBeginPaint = GetProcAddress(GetModuleHandle("User32.dll"), "BeginPaint");
    printf("BeginPaint(0x%p, 0x%p)", hWnd, lpPaint);
    Ret = lpfnBeginPaint(hWnd, lpPaint);
    printf(" = %d\n", Ret);

    return Ret;
}

BOOL
WtClientToScreen(
  HWND    hWnd,
  LPPOINT lpPoint
)
{
    BOOL                Ret;
    static DWORD        Cnt;
    FARPROC             lpfnClientToScreen;


    ShowDetails(pOpts, ++Cnt);
    lpfnClientToScreen = GetProcAddress(GetModuleHandle("User32.dll"), "ClientToScreen");
    printf("ClientToScreen(0x%p, 0x%p)", hWnd, lpPoint);
    Ret = lpfnClientToScreen(hWnd, lpPoint);
    printf(" = %d\n", Ret);

    return Ret;
}

BOOL
WtClipCursor( const RECT *lpRect
)
{
    BOOL                Ret;
    static DWORD        Cnt;
}

BOOL
WtCloseWindow(
  HWND hWnd
)
{
    BOOL                Ret;
    static DWORD        Cnt;
}

HWND
WtCreateWindowA(
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
)
{
    HWND                Ret;
    static DWORD        Cnt;
}

HWND
WtCreateWindowW(
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
)
{
    int                 Ret;
    static DWORD        Cnt;
}

HWND
WtCreateWindowExA(
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
)
{
    int                 Ret;
    static DWORD        Cnt;
}

HWND
WtCreateWindowExW(
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
)
{
    int                 Ret;
    static DWORD        Cnt;
}

LRESULT
WtDefWindowProc(
  HWND   hWnd,
  UINT   Msg,
  WPARAM wParam,
  LPARAM lParam
)
{
    int                 Ret;
    static DWORD        Cnt;
}

BOOL
WtDestroyWindow(
  HWND hWnd
)
{
    int                 Ret;
    static DWORD        Cnt;
}

LRESULT
WtDispatchMessageA(
  const MSG *lpMsg
)
{
    int                 Ret;
    static DWORD        Cnt;
}

LRESULT
WtDispatchMessageW(
  const MSG *lpMsg
)
{
    int                 Ret;
    static DWORD        Cnt;
}


BOOL
WtEndPaint(
  HWND              hWnd,
  const PAINTSTRUCT *lpPaint
)
{
    int                 Ret;
    static DWORD        Cnt;
}

int
WtFillRect(
  HDC        hDC,
  const RECT *lprc,
  HBRUSH     hbr
)
{
    int                 Ret;
    static DWORD        Cnt;
}

BOOL
WtGetClientRect(
  HWND   hWnd,
  LPRECT lpRect
)
{
    int                 Ret;
    static DWORD        Cnt;
}

BOOL
WtGetCursorPos(
  LPPOINT lpPoint
)
{
    int                 Ret;
    static DWORD        Cnt;
}

HDC
WtGetDC(
  HWND hWnd
)
{
    int                 Ret;
    static DWORD        Cnt;
}

BOOL
WtGetMessage(
  LPMSG lpMsg,
  HWND  hWnd,
  UINT  wMsgFilterMin,
  UINT  wMsgFilterMax
)
{
    int                 Ret;
    static DWORD        Cnt;
}

BOOL
WtGetWindowRect(
  HWND   hWnd,
  LPRECT lpRect
)
{
    int                 Ret;
    static DWORD        Cnt;
}

int WINAPI
WtMessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
    int                 Ret;
    static DWORD        Cnt;
    FARPROC             lpfnMessageBoxA;


    ShowDetails(pOpts, ++Cnt);
    lpfnMessageBoxA = GetProcAddress(GetModuleHandle("User32.dll"), "MessageBoxA");
    printf("MessageBoxA(0x%p, \"%s\", \"%s\", %u)", hWnd, lpText, lpCaption, uType);
    Ret = lpfnMessageBoxA(hWnd, lpText, lpCaption, uType);
    printf(" = %d\n", Ret);

    return Ret;
}

int WINAPI
WtMessageBoxW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType)
{
    int                 Ret;
    static DWORD        Cnt;
    FARPROC             lpfnMessageBoxW;


    ShowDetails(pOpts, ++Cnt);
    lpfnMessageBoxW = GetProcAddress(GetModuleHandle("User32.dll"), "MessageBoxW");
    printf("MessageBoxW(0x%p, \"%ws\", \"%ws\", %u)", hWnd, lpText, lpCaption, uType);
    Ret = lpfnMessageBoxW(hWnd, lpText, lpCaption, uType);
    printf(" = %d\n", Ret);

    return Ret;
}

int
WtMessageBoxExA(
  HWND   hWnd,
  LPCSTR lpText,
  LPCSTR lpCaption,
  UINT   uType,
  WORD   wLanguageId
)
{
    int                 Ret;
    static DWORD        Cnt;
}

int
WtMessageBoxExW(
  HWND    hWnd,
  LPCWSTR lpText,
  LPCWSTR lpCaption,
  UINT    uType,
  WORD    wLanguageId
)
{
    int                 Ret;
    static DWORD        Cnt;
}

BOOL
WtPeekMessageA(
  LPMSG lpMsg,
  HWND  hWnd,
  UINT  wMsgFilterMin,
  UINT  wMsgFilterMax,
  UINT  wRemoveMsg
)
{
    int                 Ret;
    static DWORD        Cnt;
}

BOOL
WtPeekMessageW(
  LPMSG lpMsg,
  HWND  hWnd,
  UINT  wMsgFilterMin,
  UINT  wMsgFilterMax,
  UINT  wRemoveMsg
)
{
    int                 Ret;
    static DWORD        Cnt;
}

BOOL
WtPostMessageA(
  HWND   hWnd,
  UINT   Msg,
  WPARAM wParam,
  LPARAM lParam
)
{
    int                 Ret;
    static DWORD        Cnt;
}

BOOL
WtPostMessageW(
  HWND   hWnd,
  UINT   Msg,
  WPARAM wParam,
  LPARAM lParam
)
{
    int                 Ret;
    static DWORD        Cnt;
}

void
WtPostQuitMessage(
  int nExitCode
)
{
    int                 Ret;
    static DWORD        Cnt;
}

ATOM
WtRegisterClassExA(
  const WNDCLASSEXA *unnamedParam1
)
{
    int                 Ret;
    static DWORD        Cnt;
}

ATOM
WtRegisterClassExW(
  const WNDCLASSEXW *unnamedParam1
)
{
    int                 Ret;
    static DWORD        Cnt;
}

int
WtReleaseDC(
  HWND hWnd,
  HDC  hDC
)
{
    int                 Ret;
    static DWORD        Cnt;
}

BOOL
WtScreenToClient(
  HWND    hWnd,
  LPPOINT lpPoint
)
{
    int                 Ret;
    static DWORD        Cnt;
}

int
WtShowCursor(
  BOOL bShow
)
{
    int                 Ret;
    static DWORD        Cnt;
}

BOOL
WtShowWindow(
  HWND hWnd,
  int  nCmdShow
)
{
    int                 Ret;
    static DWORD        Cnt;
}

BOOL
WtTranslateMessage(
  const MSG *lpMsg
)
{
    int                 Ret;
    static DWORD        Cnt;
}

BOOL
WtUpdateWindow(
  HWND hWnd
)
{
    int                 Ret;
    static DWORD        Cnt;
}


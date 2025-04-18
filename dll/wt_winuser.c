#include "inc/wt_winuser.h"
#include <stdio.h>

extern T_WINTRACE_OPTS      *pOpts;

BOOL
WtAdjustWindowRect(
  LPRECT lpRect,
  DWORD  dwStyle,
  BOOL   bMenu
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "AdjustWindowRect(0x%p, %u, %d)", lpRect, dwStyle, bMenu);
    Ret = AdjustWindowRect(lpRect, dwStyle, bMenu);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

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


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "AdjustWindowRectEx(0x%p, %u, %d, %u)", lpRect, dwStyle, bMenu, dwExStyle);
    Ret = AdjustWindowRectEx(lpRect, dwStyle, bMenu, dwExStyle);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

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


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "BeginPaint(0x%p, 0x%p)", hWnd, lpPaint);
    Ret = BeginPaint(hWnd, lpPaint);
    fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);

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


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "ClientToScreen(0x%p, 0x%p)", hWnd, lpPoint);
    Ret = ClientToScreen(hWnd, lpPoint);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtClipCursor( const RECT *lpRect
)
{
    BOOL                Ret;
    static DWORD        Cnt;

    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "ClipCursor(0x%p)", lpRect);
    Ret = ClipCursor(lpRect);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);


    return Ret;
}

BOOL
WtCloseWindow(
  HWND hWnd
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "CloseWindow(0x%p)", hWnd);
    Ret = CloseWindow(hWnd);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
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


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "CreateWindowA(\"%s\", \"%s\", %u, %d, %d, %d, %d, 0x%p, 0x%p, 0x%p, 0x%p",
            lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent,
            hMenu, hInstance, lpParam);
    fprintf(pOpts->OutputFile, ")");
    Ret = CreateWindowA(lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight,
            hWndParent, hMenu, hInstance, lpParam);
    fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);

    return Ret;
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
    HWND                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "CreateWindowW(\"%ws\", \"%ws\", %u, %d, %d, %d, %d, 0x%p, 0x%p, 0x%p, 0x%p",
            lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent,
            hMenu, hInstance, lpParam);
    fprintf(pOpts->OutputFile, ")");
    Ret = CreateWindowW(lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight,
            hWndParent, hMenu, hInstance, lpParam);
    fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);

    return Ret;
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
    HWND                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "CreateWindowExA(%u, \"%s\", \"%s\", %u, %d, %d, %d, %d, 0x%p, 0x%p, 0x%p, 0x%p",
            dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent,
            hMenu, hInstance, lpParam);
    fprintf(pOpts->OutputFile, ")");
    Ret = CreateWindowA(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight,
            hWndParent, hMenu, hInstance, lpParam);
    fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);

    return Ret;
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
    HWND                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "CreateWindowExW(%u, \"%ws\", \"%ws\", %u, %d, %d, %d, %d, 0x%p, 0x%p, 0x%p, 0x%p",
            dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent,
            hMenu, hInstance, lpParam);
    fprintf(pOpts->OutputFile, ")");
    Ret = CreateWindowW(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight,
            hWndParent, hMenu, hInstance, lpParam);
    fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);

    return Ret;
}

LRESULT
WtDefWindowProc(
  HWND   hWnd,
  UINT   Msg,
  WPARAM wParam,
  LPARAM lParam
)
{
    LRESULT             Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "DefWindowProc(0x%p, %u, %u, %u)", hWnd, Msg, wParam, lParam);
    Ret = DefWindowProc(hWnd, Msg, wParam, lParam);
    fprintf(pOpts->OutputFile, " = %u", Ret);

    return Ret;
}

BOOL
WtDestroyWindow(
  HWND hWnd
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "DestroyWindow(0x%p)", hWnd);
    Ret = DestroyWindow(hWnd);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

LRESULT
WtDispatchMessageA(
  const MSG *lpMsg
)
{
    LRESULT             Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "DispatchMessageA(0x%p)", lpMsg);
    Ret = DispatchMessageA(lpMsg);
    fprintf(pOpts->OutputFile, " = %u\n", Ret);

    return Ret;
}

LRESULT
WtDispatchMessageW(
  const MSG *lpMsg
)
{
    LRESULT             Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "DispatchMessageW(0x%p)", lpMsg);
    Ret = DispatchMessageW(lpMsg);
    fprintf(pOpts->OutputFile, " = %u\n", Ret);

    return Ret;
}


BOOL
WtEndPaint(
  HWND              hWnd,
  const PAINTSTRUCT *lpPaint
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "EndPaint(0x%p, 0x%p)", hWnd, lpPaint);
    Ret = EndPaint(hWnd, lpPaint);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
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


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "FillRect(0x%p, 0x%p, 0x%p)", hDC, lprc, hbr);
    Ret = FillRect(hDC, lprc, hbr);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtGetClientRect(
  HWND   hWnd,
  LPRECT lpRect
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "GetClientRect(0x%p, 0x%p)", hWnd, lpRect);
    Ret = GetClientRect(hWnd, lpRect);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtGetCursorPos(
  LPPOINT lpPoint
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "GetCursorPos(0x%p)", lpPoint);
    Ret = GetCursorPos(lpPoint);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

HDC
WtGetDC(
  HWND hWnd
)
{
    HDC                 Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "GetDC(0x%p)", hWnd);
    Ret = GetDC(hWnd);
    fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);

    return Ret;
}

BOOL
WtGetMessageA(
  LPMSG lpMsg,
  HWND  hWnd,
  UINT  wMsgFilterMin,
  UINT  wMsgFilterMax
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "GetMessage(0x%p, 0x%p, %u, %u)", lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
    Ret = GetMessage(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtGetMessageW(
  LPMSG lpMsg,
  HWND  hWnd,
  UINT  wMsgFilterMin,
  UINT  wMsgFilterMax
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "GetMessage(0x%p, 0x%p, %u, %u)", lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
    Ret = GetMessage(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtGetWindowRect(
  HWND   hWnd,
  LPRECT lpRect
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "GetWindowRect(0x%p, 0x%p)", hWnd, lpRect);
    Ret = GetWindowRect(hWnd, lpRect);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

int WINAPI
WtMessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
    int                 Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "MessageBoxA(0x%p, \"%s\", \"%s\", %u)", hWnd, lpText, lpCaption, uType);
    Ret = MessageBoxA(hWnd, lpText, lpCaption, uType);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

int WINAPI
WtMessageBoxW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType)
{
    int                 Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "MessageBoxW(0x%p, \"%ws\", \"%ws\", %u)", hWnd, lpText, lpCaption, uType);
    Ret = MessageBoxW(hWnd, lpText, lpCaption, uType);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

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


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "MessageBoxExA(0x%p, \"%s\", \"%s\", %u, %hu)", hWnd, lpText, lpCaption, uType, wLanguageId);
    Ret = MessageBoxExA(hWnd, lpText, lpCaption, uType, wLanguageId);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
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


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "MessageBoxExW(0x%p, \"%ws\", \"%ws\", %u, %hu)", hWnd, lpText, lpCaption, uType, wLanguageId);
    Ret = MessageBoxExW(hWnd, lpText, lpCaption, uType, wLanguageId);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
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
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "PeekMessageA(0x%p, 0x%p, %u, %u, %u)", lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
    Ret = PeekMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
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
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "PeekMessageW(0x%p, 0x%p, %u, %u, %u)", lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
    Ret = PeekMessageW(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtPostMessageA(
  HWND   hWnd,
  UINT   Msg,
  WPARAM wParam,
  LPARAM lParam
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "PostMessageA(0x%p, %u, %u, %u)", hWnd, Msg, wParam, lParam);
    Ret = PostMessageA(hWnd, Msg, wParam, lParam);
    fprintf(pOpts->OutputFile, " = %d", Ret);

    return Ret;
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


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "PostMessageW(0x%p, %u, %u, %u)", hWnd, Msg, wParam, lParam);
    Ret = PostMessageW(hWnd, Msg, wParam, lParam);
    fprintf(pOpts->OutputFile, " = %d", Ret);

    return Ret;
}

void
WtPostQuitMessage(
  int nExitCode
)
{
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "PostQuitMessage(%d)", nExitCode);
    PostQuitMessage(nExitCode);
    fprintf(pOpts->OutputFile, " = VOID\n");
}

ATOM
WtRegisterClassExA(
  const WNDCLASSEXA *unnamedParam1
)
{
    ATOM                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "RegisterClassExA(0x%p)", unnamedParam1);
    Ret = RegisterClassExA(unnamedParam1);
    fprintf(pOpts->OutputFile, " = %hu\n", Ret);

    return Ret;
}

ATOM
WtRegisterClassExW(
  const WNDCLASSEXW *unnamedParam1
)
{
    ATOM                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "RegisterClassExW(0x%p)", unnamedParam1);
    Ret = RegisterClassExW(unnamedParam1);
    fprintf(pOpts->OutputFile, " = %hu\n", Ret);

    return Ret;
}

int
WtReleaseDC(
  HWND hWnd,
  HDC  hDC
)
{
    int                 Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "ReleaseDC(0x%p, 0x%p)", hWnd, hDC);
    Ret = ReleaseDC(hWnd, hDC);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtScreenToClient(
  HWND    hWnd,
  LPPOINT lpPoint
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "ScreenToClient(0x%p, 0x%p)", hWnd, lpPoint);
    Ret = ScreenToClient(hWnd, lpPoint);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

int
WtShowCursor(
  BOOL bShow
)
{
    int                 Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "ShowCursor(%d)", bShow);
    Ret = ShowCursor(bShow);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtShowWindow(
  HWND hWnd,
  int  nCmdShow
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "ShowWindow(0x%p, %d)", hWnd, nCmdShow);
    Ret = ShowWindow(hWnd, nCmdShow);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtTranslateMessage(
  const MSG *lpMsg
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "TranslateMessage(0x%p)", lpMsg);
    Ret = TranslateMessage(lpMsg);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}

BOOL
WtUpdateWindow(
  HWND hWnd
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    fprintf(pOpts->OutputFile, "UpdateWindow(0x%p)", hWnd);
    Ret = UpdateWindow(hWnd);
    fprintf(pOpts->OutputFile, " = %d\n", Ret);

    return Ret;
}


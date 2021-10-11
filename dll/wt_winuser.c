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


    ShowDetails(pOpts, ++Cnt);
    printf("AdjustWindowRect(0x%p, %u, %d)", lpRect, dwStyle, bMenu);
    Ret = AdjustWindowRect(lpRect, dwStyle, bMenu);
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


    ShowDetails(pOpts, ++Cnt);
    printf("AdjustWindowRectEx(0x%p, %u, %d, %u)", lpRect, dwStyle, bMenu, dwExStyle);
    Ret = AdjustWindowRectEx(lpRect, dwStyle, bMenu, dwExStyle);
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


    ShowDetails(pOpts, ++Cnt);
    printf("BeginPaint(0x%p, 0x%p)", hWnd, lpPaint);
    Ret = BeginPaint(hWnd, lpPaint);
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


    ShowDetails(pOpts, ++Cnt);
    printf("ClientToScreen(0x%p, 0x%p)", hWnd, lpPoint);
    Ret = ClientToScreen(hWnd, lpPoint);
    printf(" = %d\n", Ret);

    return Ret;
}

BOOL
WtClipCursor( const RECT *lpRect
)
{
    BOOL                Ret;
    static DWORD        Cnt;

    ShowDetails(pOpts, ++Cnt);
    printf("ClipCursor(0x%p)", lpRect);
    Ret = ClipCursor(lpRect);
    printf(" = %d\n", Ret);


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
    printf("CloseWindow(0x%p)", hWnd);
    Ret = CloseWindow(hWnd);
    printf(" = %d\n", Ret);

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
    printf("CreateWindowA(\"%s\", \"%s\", %u, %d, %d, %d, %d, 0x%p, 0x%p, 0x%p, 0x%p",
            lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent,
            hMenu, hInstance, lpParam);
    printf(")");
    Ret = CreateWindowA(lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight,
            hWndParent, hMenu, hInstance, lpParam);
    printf(" = 0x%p\n", Ret);

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
    printf("CreateWindowW(\"%ws\", \"%ws\", %u, %d, %d, %d, %d, 0x%p, 0x%p, 0x%p, 0x%p",
            lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent,
            hMenu, hInstance, lpParam);
    printf(")");
    Ret = CreateWindowW(lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight,
            hWndParent, hMenu, hInstance, lpParam);
    printf(" = 0x%p\n", Ret);

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
    printf("CreateWindowExA(%u, \"%s\", \"%s\", %u, %d, %d, %d, %d, 0x%p, 0x%p, 0x%p, 0x%p",
            dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent,
            hMenu, hInstance, lpParam);
    printf(")");
    Ret = CreateWindowA(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight,
            hWndParent, hMenu, hInstance, lpParam);
    printf(" = 0x%p\n", Ret);

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
    printf("CreateWindowExW(%u, \"%ws\", \"%ws\", %u, %d, %d, %d, %d, 0x%p, 0x%p, 0x%p, 0x%p",
            dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent,
            hMenu, hInstance, lpParam);
    printf(")");
    Ret = CreateWindowW(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight,
            hWndParent, hMenu, hInstance, lpParam);
    printf(" = 0x%p\n", Ret);

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
    printf("DefWindowProc(0x%p, %u, %u, %u)", hWnd, Msg, wParam, lParam);
    Ret = DefWindowProc(hWnd, Msg, wParam, lParam);
    printf(" = %u", Ret);

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
    printf("DestroyWindow(0x%p)", hWnd);
    Ret = DestroyWindow(hWnd);
    printf(" = %d\n", Ret);

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
    printf("DispatchMessageA(0x%p)", lpMsg);
    Ret = DispatchMessageA(lpMsg);
    printf(" = %u\n", Ret);

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
    printf("DispatchMessageW(0x%p)", lpMsg);
    Ret = DispatchMessageW(lpMsg);
    printf(" = %u\n", Ret);

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
    printf("EndPaint(0x%p, 0x%p)", hWnd, lpPaint);
    Ret = EndPaint(hWnd, lpPaint);
    printf(" = %d\n", Ret);

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
    printf("FillRect(0x%p, 0x%p, 0x%p)", hDC, lprc, hbr);
    Ret = FillRect(hDC, lprc, hbr);
    printf(" = %d\n", Ret);

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
    printf("GetClientRect(0x%p, 0x%p)", hWnd, lpRect);
    Ret = GetClientRect(hWnd, lpRect);
    printf(" = %d\n", Ret);

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
    printf("GetCursorPos(0x%p)", lpPoint);
    Ret = GetCursorPos(lpPoint);
    printf(" = %d\n", Ret);

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
    printf("GetDC(0x%p)", hWnd);
    Ret = GetDC(hWnd);
    printf(" = 0x%p\n", Ret);

    return Ret;
}

BOOL
WtGetMessage(
  LPMSG lpMsg,
  HWND  hWnd,
  UINT  wMsgFilterMin,
  UINT  wMsgFilterMax
)
{
    BOOL                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    printf("GetMessage(0x%p, 0x%p, %u, %u)", lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
    Ret = GetMessage(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
    printf(" = %d\n", Ret);

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
    printf("GetWindowRect(0x%p, 0x%p)", hWnd, lpRect);
    Ret = GetWindowRect(hWnd, lpRect);
    printf(" = %d\n", Ret);

    return Ret;
}

int WINAPI
WtMessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
    int                 Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    printf("MessageBoxA(0x%p, \"%s\", \"%s\", %u)", hWnd, lpText, lpCaption, uType);
    Ret = MessageBoxA(hWnd, lpText, lpCaption, uType);
    printf(" = %d\n", Ret);

    return Ret;
}

int WINAPI
WtMessageBoxW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType)
{
    int                 Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    printf("MessageBoxW(0x%p, \"%ws\", \"%ws\", %u)", hWnd, lpText, lpCaption, uType);
    Ret = MessageBoxW(hWnd, lpText, lpCaption, uType);
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


    ShowDetails(pOpts, ++Cnt);
    printf("MessageBoxExA(0x%p, \"%s\", \"%s\", %u, %hu)", hWnd, lpText, lpCaption, uType, wLanguageId);
    Ret = MessageBoxExA(hWnd, lpText, lpCaption, uType, wLanguageId);
    printf(" = %d\n", Ret);

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
    printf("MessageBoxExW(0x%p, \"%ws\", \"%ws\", %u, %hu)", hWnd, lpText, lpCaption, uType, wLanguageId);
    Ret = MessageBoxExW(hWnd, lpText, lpCaption, uType, wLanguageId);
    printf(" = %d\n", Ret);

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
    printf("PeekMessageA(0x%p, 0x%p, %u, %u, %u)", lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
    Ret = PeekMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
    printf(" = %d\n", Ret);

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
    printf("PeekMessageW(0x%p, 0x%p, %u, %u, %u)", lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
    Ret = PeekMessageW(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
    printf(" = %d\n", Ret);

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
    printf("PostMessageA(0x%p, %u, %u, %u)", hWnd, Msg, wParam, lParam);
    Ret = PostMessageA(hWnd, Msg, wParam, lParam);
    printf(" = %d", Ret);

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
    printf("PostMessageW(0x%p, %u, %u, %u)", hWnd, Msg, wParam, lParam);
    Ret = PostMessageW(hWnd, Msg, wParam, lParam);
    printf(" = %d", Ret);

    return Ret;
}

void
WtPostQuitMessage(
  int nExitCode
)
{
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    printf("PostQuitMessage(%d)", nExitCode);
    PostQuitMessage(nExitCode);
    printf(" = VOID\n");
}

ATOM
WtRegisterClassExA(
  const WNDCLASSEXA *unnamedParam1
)
{
    ATOM                Ret;
    static DWORD        Cnt;


    ShowDetails(pOpts, ++Cnt);
    printf("RegisterClassExA(0x%p)", unnamedParam1);
    Ret = RegisterClassExA(unnamedParam1);
    printf(" = %hu", Ret);

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
    printf("RegisterClassExW(0x%p)", unnamedParam1);
    Ret = RegisterClassExW(unnamedParam1);
    printf(" = %hu", Ret);

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
    printf("ReleaseDC(0x%p, 0x%p)", hWnd, hDC);
    Ret = ReleaseDC(hWnd, hDC);
    printf(" = %d\n", Ret);

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
    printf("ScreenToClient(0x%p, 0x%p)", hWnd, lpPoint);
    Ret = ScreenToClient(hWnd, lpPoint);
    printf(" = %d\n", Ret);

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
    printf("ShowCursor(%d)", bShow);
    Ret = ShowCursor(bShow);
    printf(" = %d\n", Ret);

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
    printf("ShowWindow(0x%p, %d)", hWnd, nCmdShow);
    Ret = ShowWindow(hWnd, nCmdShow);
    printf(" = %d\n", Ret);

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
    printf("TranslateMessage(0x%p)", lpMsg);
    Ret = TranslateMessage(lpMsg);
    printf(" = %d\n", Ret);

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
    printf("UpdateWindow(0x%p)", hWnd);
    Ret = UpdateWindow(hWnd);
    printf(" = %d\n", Ret);

    return Ret;
}


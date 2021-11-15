#include "inc/wt_winuser.h"

extern T_WintraceOpts      *pOpts;

BOOL
WtAdjustWindowRect(
  LPRECT lpRect,
  DWORD  dwStyle,
  BOOL   bMenu
)
{
    BOOL                Ret;


    if (BeginTrace(E_AdjustWindowRect))
    {
        fprintf(pOpts->OutputFile, "(0x%p, %u, %d)", lpRect, dwStyle, bMenu);
        Ret = AdjustWindowRect(lpRect, dwStyle, bMenu);
        fprintf(pOpts->OutputFile, " = %d\n", Ret);
    }
    else
        Ret = AdjustWindowRect(lpRect, dwStyle, bMenu);

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


    if (BeginTrace(E_AdjustWindowRectEx))
    {
        fprintf(pOpts->OutputFile, "(0x%p, %u, %d, %u)", lpRect, dwStyle, bMenu, dwExStyle);
        Ret = AdjustWindowRectEx(lpRect, dwStyle, bMenu, dwExStyle);
        fprintf(pOpts->OutputFile, " = %d\n", Ret);
    }
    else
        Ret = AdjustWindowRectEx(lpRect, dwStyle, bMenu, dwExStyle);

    return Ret;
}

HDC
WtBeginPaint(
  HWND          hWnd,
  LPPAINTSTRUCT lpPaint
)
{
    HDC                 Ret;


    if (BeginTrace(E_BeginPaint))
    {
        fprintf(pOpts->OutputFile, "(0x%p, 0x%p)", hWnd, lpPaint);
        Ret = BeginPaint(hWnd, lpPaint);
        fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);
    }
    else
        Ret = BeginPaint(hWnd, lpPaint);

    return Ret;
}

BOOL
WtClientToScreen(
  HWND    hWnd,
  LPPOINT lpPoint
)
{
    BOOL                Ret;


    if (BeginTrace(E_ClientToScreen))
    {
        fprintf(pOpts->OutputFile, "(0x%p, 0x%p)", hWnd, lpPoint);
        Ret = ClientToScreen(hWnd, lpPoint);
        fprintf(pOpts->OutputFile, " = %d\n", Ret);
    }
    else
        Ret = ClientToScreen(hWnd, lpPoint);

    return Ret;
}

BOOL
WtClipCursor( const RECT *lpRect
)
{
    BOOL                Ret;


    if (BeginTrace(E_ClipCursor))
    {
        fprintf(pOpts->OutputFile, "(0x%p)", lpRect);
        Ret = ClipCursor(lpRect);
        fprintf(pOpts->OutputFile, " = %d\n", Ret);
    }
    else
        Ret = ClipCursor(lpRect);

    return Ret;
}

BOOL
WtCloseWindow(
  HWND hWnd
)
{
    BOOL                Ret;


    if (BeginTrace(E_CloseWindow))
    {
        fprintf(pOpts->OutputFile, "(0x%p)", hWnd);
        Ret = CloseWindow(hWnd);
        fprintf(pOpts->OutputFile, " = %d\n", Ret);
    }
    else
        Ret = CloseWindow(hWnd);

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


    if (BeginTrace(E_CreateWindowA))
    {
        fprintf(pOpts->OutputFile, "(\"%s\", \"%s\", %u, %d, %d, %d, %d, 0x%p, 0x%p, 0x%p, 0x%p)",
                lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent,
                hMenu, hInstance, lpParam);
        Ret = CreateWindowA(lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight,
                hWndParent, hMenu, hInstance, lpParam);
        fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);
    }
    else
    {
        Ret = CreateWindowA(lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight,
                hWndParent, hMenu, hInstance, lpParam);
    }

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


    if (BeginTrace(E_CreateWindowW))
    {
        fprintf(pOpts->OutputFile, "(\"%ws\", \"%ws\", %u, %d, %d, %d, %d, 0x%p, 0x%p, 0x%p, 0x%p)",
                lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent,
                hMenu, hInstance, lpParam);
        Ret = CreateWindowW(lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight,
                hWndParent, hMenu, hInstance, lpParam);
        fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);
    }
    else
    {
        Ret = CreateWindowW(lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight,
                hWndParent, hMenu, hInstance, lpParam);
    }

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


    if (BeginTrace(E_CreateWindowExA))
    {
        fprintf(pOpts->OutputFile, "(%u, \"%s\", \"%s\", %u, %d, %d, %d, %d, 0x%p, 0x%p, 0x%p, 0x%p)",
                dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent,
                hMenu, hInstance, lpParam);
        Ret = CreateWindowA(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight,
                hWndParent, hMenu, hInstance, lpParam);
        fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);
    }
    else
    {
        Ret = CreateWindowA(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight,
                hWndParent, hMenu, hInstance, lpParam);
    }

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


    if (BeginTrace(E_CreateWindowExW))
    {
        fprintf(pOpts->OutputFile, "(%u, \"%ws\", \"%ws\", %u, %d, %d, %d, %d, 0x%p, 0x%p, 0x%p, 0x%p)",
                dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent,
                hMenu, hInstance, lpParam);
        Ret = CreateWindowW(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight,
                hWndParent, hMenu, hInstance, lpParam);
        fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);
    }
    else
    {
        Ret = CreateWindowW(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight,
                hWndParent, hMenu, hInstance, lpParam);
    }

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


    if (BeginTrace(E_DefWindowProc))
    {
        fprintf(pOpts->OutputFile, "(0x%p, %u, %u, %u)", hWnd, Msg, wParam, lParam);
        Ret = DefWindowProc(hWnd, Msg, wParam, lParam);
        fprintf(pOpts->OutputFile, " = %u", Ret);
    }
    else
        Ret = DefWindowProc(hWnd, Msg, wParam, lParam);

    return Ret;
}

BOOL
WtDestroyWindow(
  HWND hWnd
)
{
    BOOL                Ret;


    if (BeginTrace(E_DestroyWindow))
    {
        fprintf(pOpts->OutputFile, "(0x%p)", hWnd);
        Ret = DestroyWindow(hWnd);
        fprintf(pOpts->OutputFile, " = %d\n", Ret);
    }
    else
        Ret = DestroyWindow(hWnd);

    return Ret;
}

LRESULT
WtDispatchMessageA(
  const MSG *lpMsg
)
{
    LRESULT             Ret;


    if (BeginTrace(E_DispatchMessageA))
    {
        fprintf(pOpts->OutputFile, "(0x%p)", lpMsg);
        Ret = DispatchMessageA(lpMsg);
        fprintf(pOpts->OutputFile, " = %u\n", Ret);
    }
    else
        Ret = DispatchMessageA(lpMsg);

    return Ret;
}

LRESULT
WtDispatchMessageW(
  const MSG *lpMsg
)
{
    LRESULT             Ret;


    if (BeginTrace(E_DispatchMessageW))
    {
        fprintf(pOpts->OutputFile, "(0x%p)", lpMsg);
        Ret = DispatchMessageW(lpMsg);
        fprintf(pOpts->OutputFile, " = %u\n", Ret);
    }
    else
        Ret = DispatchMessageW(lpMsg);

    return Ret;
}


BOOL
WtEndPaint(
  HWND              hWnd,
  const PAINTSTRUCT *lpPaint
)
{
    BOOL                Ret;


    if (BeginTrace(E_EndPaint))
    {
        fprintf(pOpts->OutputFile, "(0x%p, 0x%p)", hWnd, lpPaint);
        Ret = EndPaint(hWnd, lpPaint);
        fprintf(pOpts->OutputFile, " = %d\n", Ret);
    }
    else
        Ret = EndPaint(hWnd, lpPaint);

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


    if (BeginTrace(E_FillRect))
    {
        fprintf(pOpts->OutputFile, "(0x%p, 0x%p, 0x%p)", hDC, lprc, hbr);
        Ret = FillRect(hDC, lprc, hbr);
        fprintf(pOpts->OutputFile, " = %d\n", Ret);
    }
    else
        Ret = FillRect(hDC, lprc, hbr);

    return Ret;
}

BOOL
WtGetClientRect(
  HWND   hWnd,
  LPRECT lpRect
)
{
    BOOL                Ret;


    if (BeginTrace(E_GetClientRect))
    {
        fprintf(pOpts->OutputFile, "(0x%p, 0x%p)", hWnd, lpRect);
        Ret = GetClientRect(hWnd, lpRect);
        fprintf(pOpts->OutputFile, " = %d\n", Ret);
    }
    else
        Ret = GetClientRect(hWnd, lpRect);

    return Ret;
}

BOOL
WtGetCursorPos(
  LPPOINT lpPoint
)
{
    BOOL                Ret;


    if (BeginTrace(E_GetCursorPos))
    {
        fprintf(pOpts->OutputFile, "(0x%p)", lpPoint);
        Ret = GetCursorPos(lpPoint);
        fprintf(pOpts->OutputFile, " = %d\n", Ret);
    }
    else
        Ret = GetCursorPos(lpPoint);

    return Ret;
}

HDC
WtGetDC(
  HWND hWnd
)
{
    HDC                 Ret;


    if (BeginTrace(E_GetDC))
    {
        fprintf(pOpts->OutputFile, "(0x%p)", hWnd);
        Ret = GetDC(hWnd);
        fprintf(pOpts->OutputFile, " = 0x%p\n", Ret);
    }
    else
        Ret = GetDC(hWnd);

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


    if (BeginTrace(E_GetMessageA))
    {
        fprintf(pOpts->OutputFile, "(0x%p, 0x%p, %u, %u)", lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
        Ret = GetMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
        fprintf(pOpts->OutputFile, " = %d\n", Ret);
    }
    else
        Ret = GetMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);

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


    if (BeginTrace(E_GetMessageW))
    {
        fprintf(pOpts->OutputFile, "(0x%p, 0x%p, %u, %u)", lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
        Ret = GetMessageW(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
        fprintf(pOpts->OutputFile, " = %d\n", Ret);
    }
    else
        Ret = GetMessageW(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);

    return Ret;
}

BOOL
WtGetWindowRect(
  HWND   hWnd,
  LPRECT lpRect
)
{
    BOOL                Ret;


    if (BeginTrace(E_GetWindowRect))
    {
        fprintf(pOpts->OutputFile, "(0x%p, 0x%p)", hWnd, lpRect);
        Ret = GetWindowRect(hWnd, lpRect);
        fprintf(pOpts->OutputFile, " = %d\n", Ret);
    }
    else
        Ret = GetWindowRect(hWnd, lpRect);

    return Ret;
}

int WINAPI
WtMessageBoxA(
  HWND hWnd,
  LPCSTR lpText,
  LPCSTR lpCaption,
  UINT uType)
{
    int                 Ret;


    if (BeginTrace(E_MessageBoxA))
    {
        fprintf(pOpts->OutputFile, "(0x%p, \"%s\", \"%s\", %u)", hWnd, lpText, lpCaption, uType);
        Ret = MessageBoxA(hWnd, lpText, lpCaption, uType);
        fprintf(pOpts->OutputFile, " = %d\n", Ret);
    }
    else
        Ret = MessageBoxA(hWnd, lpText, lpCaption, uType);

    return Ret;
}

int WINAPI
WtMessageBoxW(
  HWND hWnd,
  LPCWSTR lpText,
  LPCWSTR lpCaption,
  UINT uType)
{
    int                 Ret;


    if (BeginTrace(E_MessageBoxW))
    {
        fprintf(pOpts->OutputFile, "(0x%p, \"%ws\", \"%ws\", %u)", hWnd, lpText, lpCaption, uType);
        Ret = MessageBoxW(hWnd, lpText, lpCaption, uType);
        fprintf(pOpts->OutputFile, " = %d\n", Ret);
    }
    else
        Ret = MessageBoxW(hWnd, lpText, lpCaption, uType);

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


    if (BeginTrace(E_MessageBoxExA))
    {
        fprintf(pOpts->OutputFile, "(0x%p, \"%s\", \"%s\", %u, %hu)", hWnd, lpText, lpCaption, uType, wLanguageId);
        Ret = MessageBoxExA(hWnd, lpText, lpCaption, uType, wLanguageId);
        fprintf(pOpts->OutputFile, " = %d\n", Ret);
    }
    else
        Ret = MessageBoxExA(hWnd, lpText, lpCaption, uType, wLanguageId);

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


    if (BeginTrace(E_MessageBoxExW))
    {
        fprintf(pOpts->OutputFile, "(0x%p, \"%ws\", \"%ws\", %u, %hu)", hWnd, lpText, lpCaption, uType, wLanguageId);
        Ret = MessageBoxExW(hWnd, lpText, lpCaption, uType, wLanguageId);
        fprintf(pOpts->OutputFile, " = %d\n", Ret);
    }
    else
        Ret = MessageBoxExW(hWnd, lpText, lpCaption, uType, wLanguageId);

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


    if (BeginTrace(E_PeekMessageA))
    {
        fprintf(pOpts->OutputFile, "(0x%p, 0x%p, %u, %u, %u)", lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
        Ret = PeekMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
        fprintf(pOpts->OutputFile, " = %d\n", Ret);
    }
    else
        Ret = PeekMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);

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


    if (BeginTrace(E_PeekMessageW))
    {
        fprintf(pOpts->OutputFile, "(0x%p, 0x%p, %u, %u, %u)", lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
        Ret = PeekMessageW(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
        fprintf(pOpts->OutputFile, " = %d\n", Ret);
    }
    else
        Ret = PeekMessageW(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);

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


    if (BeginTrace(E_PostMessageA))
    {
        fprintf(pOpts->OutputFile, "(0x%p, %u, %u, %u)", hWnd, Msg, wParam, lParam);
        Ret = PostMessageA(hWnd, Msg, wParam, lParam);
        fprintf(pOpts->OutputFile, " = %d", Ret);
    }
    else
        Ret = PostMessageA(hWnd, Msg, wParam, lParam);

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


    if (BeginTrace(E_PostMessageW))
    {
        fprintf(pOpts->OutputFile, "(0x%p, %u, %u, %u)", hWnd, Msg, wParam, lParam);
        Ret = PostMessageW(hWnd, Msg, wParam, lParam);
        fprintf(pOpts->OutputFile, " = %d", Ret);
    }
    else
        Ret = PostMessageW(hWnd, Msg, wParam, lParam);

    return Ret;
}

void
WtPostQuitMessage(
  int nExitCode
)
{
    if (BeginTrace(E_PostQuitMessage))
        fprintf(pOpts->OutputFile, "(%d) = VOID\n", nExitCode);
    PostQuitMessage(nExitCode);
}

ATOM
WtRegisterClassExA(
  const WNDCLASSEXA *unnamedParam1
)
{
    ATOM                Ret;


    if (BeginTrace(E_RegisterClassExA))
    {
        fprintf(pOpts->OutputFile, "(0x%p)", unnamedParam1);
        Ret = RegisterClassExA(unnamedParam1);
        fprintf(pOpts->OutputFile, " = %hu\n", Ret);
    }
    else
        Ret = RegisterClassExA(unnamedParam1);

    return Ret;
}

ATOM
WtRegisterClassExW(
  const WNDCLASSEXW *unnamedParam1
)
{
    ATOM                Ret;


    if (BeginTrace(E_RegisterClassExW))
    {
        fprintf(pOpts->OutputFile, "(0x%p)", unnamedParam1);
        Ret = RegisterClassExW(unnamedParam1);
        fprintf(pOpts->OutputFile, " = %hu\n", Ret);
    }
    else
        Ret = RegisterClassExW(unnamedParam1);

    return Ret;
}

int
WtReleaseDC(
  HWND hWnd,
  HDC  hDC
)
{
    int                 Ret;


    if (BeginTrace(E_ReleaseDC))
    {
        fprintf(pOpts->OutputFile, "(0x%p, 0x%p)", hWnd, hDC);
        Ret = ReleaseDC(hWnd, hDC);
        fprintf(pOpts->OutputFile, " = %d\n", Ret);
    }
    else
        Ret = ReleaseDC(hWnd, hDC);

    return Ret;
}

BOOL
WtScreenToClient(
  HWND    hWnd,
  LPPOINT lpPoint
)
{
    BOOL                Ret;


    if (BeginTrace(E_ScreenToClient))
    {
        fprintf(pOpts->OutputFile, "(0x%p, 0x%p)", hWnd, lpPoint);
        Ret = ScreenToClient(hWnd, lpPoint);
        fprintf(pOpts->OutputFile, " = %d\n", Ret);
    }
    else
        Ret = ScreenToClient(hWnd, lpPoint);

    return Ret;
}

int
WtShowCursor(
  BOOL bShow
)
{
    int                 Ret;


    if (BeginTrace(E_ShowCursor))
    {
        fprintf(pOpts->OutputFile, "(%d)", bShow);
        Ret = ShowCursor(bShow);
        fprintf(pOpts->OutputFile, " = %d\n", Ret);
    }
    else
        Ret = ShowCursor(bShow);

    return Ret;
}

BOOL
WtShowWindow(
  HWND hWnd,
  int  nCmdShow
)
{
    BOOL                Ret;


    if (BeginTrace(E_ShowWindow))
    {
        fprintf(pOpts->OutputFile, "(0x%p, %d)", hWnd, nCmdShow);
        Ret = ShowWindow(hWnd, nCmdShow);
        fprintf(pOpts->OutputFile, " = %d\n", Ret);
    }
    else
        Ret = ShowWindow(hWnd, nCmdShow);

    return Ret;
}

BOOL
WtTranslateMessage(
  const MSG *lpMsg
)
{
    BOOL                Ret;


    if (BeginTrace(E_TranslateMessage))
    {
        fprintf(pOpts->OutputFile, "(0x%p)", lpMsg);
        Ret = TranslateMessage(lpMsg);
        fprintf(pOpts->OutputFile, " = %d\n", Ret);
    }
    else
        Ret = TranslateMessage(lpMsg);

    return Ret;
}

BOOL
WtUpdateWindow(
  HWND hWnd
)
{
    BOOL                Ret;


    if (BeginTrace(E_UpdateWindow))
    {
        fprintf(pOpts->OutputFile, "(0x%p)", hWnd);
        Ret = UpdateWindow(hWnd);
        fprintf(pOpts->OutputFile, " = %d\n", Ret);
    }
    else
        Ret = UpdateWindow(hWnd);

    return Ret;
}


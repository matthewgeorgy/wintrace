#include <win32/wt_winuser.h>

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
        WriteFuncBuffer("(0x%p, %u, %d)", lpRect, dwStyle, bMenu);
        Ret = AdjustWindowRect(lpRect, dwStyle, bMenu);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_AdjustWindowRect, Ret == FALSE);
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
        WriteFuncBuffer("(0x%p, %u, %d, %u)", lpRect, dwStyle, bMenu, dwExStyle);
        Ret = AdjustWindowRectEx(lpRect, dwStyle, bMenu, dwExStyle);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_AdjustWindowRectEx, Ret == FALSE);
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
        WriteFuncBuffer("(0x%p, 0x%p)", hWnd, lpPaint);
        Ret = BeginPaint(hWnd, lpPaint);
        WriteFuncBuffer(" = 0x%p", Ret);
        EndTrace(E_BeginPaint, Ret == NULL);
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
        WriteFuncBuffer("(0x%p, 0x%p)", hWnd, lpPoint);
        Ret = ClientToScreen(hWnd, lpPoint);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_ClientToScreen, Ret == FALSE);
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
        WriteFuncBuffer("(0x%p)", lpRect);
        Ret = ClipCursor(lpRect);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_ClipCursor, Ret == FALSE);
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
        WriteFuncBuffer("(0x%p)", hWnd);
        Ret = CloseWindow(hWnd);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_CloseWindow, Ret == FALSE);
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
        WriteFuncBuffer("(\"%s\", \"%s\", %u, %d, %d, %d, %d, 0x%p, 0x%p, 0x%p, 0x%p)",
                lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent,
                hMenu, hInstance, lpParam);
        Ret = CreateWindowA(lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight,
                hWndParent, hMenu, hInstance, lpParam);
        WriteFuncBuffer(" = 0x%p", Ret);
        EndTrace(E_CreateWindowA, Ret == NULL);
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
        WriteFuncBuffer("(\"%ws\", \"%ws\", %u, %d, %d, %d, %d, 0x%p, 0x%p, 0x%p, 0x%p)",
                lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent,
                hMenu, hInstance, lpParam);
        Ret = CreateWindowW(lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight,
                hWndParent, hMenu, hInstance, lpParam);
        WriteFuncBuffer(" = 0x%p", Ret);
        EndTrace(E_CreateWindowW, Ret == NULL);
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
        WriteFuncBuffer("(%u, \"%s\", \"%s\", %u, %d, %d, %d, %d, 0x%p, 0x%p, 0x%p, 0x%p)",
                dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent,
                hMenu, hInstance, lpParam);
        Ret = CreateWindowA(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight,
                hWndParent, hMenu, hInstance, lpParam);
        WriteFuncBuffer(" = 0x%p", Ret);
        EndTrace(E_CreateWindowExA, Ret == NULL);
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
        WriteFuncBuffer("(%u, \"%ws\", \"%ws\", %u, %d, %d, %d, %d, 0x%p, 0x%p, 0x%p, 0x%p)",
                dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent,
                hMenu, hInstance, lpParam);
        Ret = CreateWindowW(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight,
                hWndParent, hMenu, hInstance, lpParam);
        WriteFuncBuffer(" = 0x%p", Ret);
        EndTrace(E_CreateWindowExW, Ret == NULL);
    }
    else
    {
        Ret = CreateWindowW(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight,
                hWndParent, hMenu, hInstance, lpParam);
    }

    return Ret;
}

LRESULT
WtDefWindowProcA(
  HWND   hWnd,
  UINT   Msg,
  WPARAM wParam,
  LPARAM lParam
)
{
    LRESULT             Ret;


    if (BeginTrace(E_DefWindowProcA))
    {
        WriteFuncBuffer("(0x%p, %u, %u, %u)", hWnd, Msg, wParam, lParam);
        Ret = DefWindowProcA(hWnd, Msg, wParam, lParam);
        WriteFuncBuffer(" = %u", Ret);
        EndTrace(E_DefWindowProcA, FALSE);
    }
    else
        Ret = DefWindowProcA(hWnd, Msg, wParam, lParam);

    return Ret;
}

LRESULT
WtDefWindowProcW(
  HWND   hWnd,
  UINT   Msg,
  WPARAM wParam,
  LPARAM lParam
)
{
    LRESULT             Ret;


    if (BeginTrace(E_DefWindowProcW))
    {
        WriteFuncBuffer("(0x%p, %u, %u, %u)", hWnd, Msg, wParam, lParam);
        Ret = DefWindowProcW(hWnd, Msg, wParam, lParam);
        WriteFuncBuffer(" = %u", Ret);
        EndTrace(E_DefWindowProcW, FALSE);
    }
    else
        Ret = DefWindowProcW(hWnd, Msg, wParam, lParam);

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
        WriteFuncBuffer("(0x%p)", hWnd);
        Ret = DestroyWindow(hWnd);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_DestroyWindow, Ret == FALSE);
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
        WriteFuncBuffer("(0x%p)", lpMsg);
        Ret = DispatchMessageA(lpMsg);
        WriteFuncBuffer(" = %u", Ret);
        EndTrace(E_DispatchMessageA, FALSE);
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
        WriteFuncBuffer("(0x%p)", lpMsg);
        Ret = DispatchMessageW(lpMsg);
        WriteFuncBuffer(" = %u", Ret);
        EndTrace(E_DispatchMessageW, FALSE);
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
        WriteFuncBuffer("(0x%p, 0x%p)", hWnd, lpPaint);
        Ret = EndPaint(hWnd, lpPaint);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_EndPaint, FALSE);
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
        WriteFuncBuffer("(0x%p, 0x%p, 0x%p)", hDC, lprc, hbr);
        Ret = FillRect(hDC, lprc, hbr);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_FillRect, Ret == 0);
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
        WriteFuncBuffer("(0x%p, 0x%p)", hWnd, lpRect);
        Ret = GetClientRect(hWnd, lpRect);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_GetClientRect, Ret == FALSE);
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
        WriteFuncBuffer("(0x%p)", lpPoint);
        Ret = GetCursorPos(lpPoint);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_GetCursorPos, Ret == FALSE);
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
        WriteFuncBuffer("(0x%p)", hWnd);
        Ret = GetDC(hWnd);
        WriteFuncBuffer(" = 0x%p", Ret);
        EndTrace(E_GetDC, Ret == NULL);
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
        WriteFuncBuffer("(0x%p, 0x%p, %u, %u)", lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
        Ret = GetMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_GetMessageA, Ret == -1);
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
        WriteFuncBuffer("(0x%p, 0x%p, %u, %u)", lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
        Ret = GetMessageW(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_GetMessageW, Ret == -1);
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
        WriteFuncBuffer("(0x%p, 0x%p)", hWnd, lpRect);
        Ret = GetWindowRect(hWnd, lpRect);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_GetWindowRect, Ret == FALSE);
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
        WriteFuncBuffer("(0x%p, \"%s\", \"%s\", %u)", hWnd, lpText, lpCaption, uType);
        Ret = MessageBoxA(hWnd, lpText, lpCaption, uType);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_MessageBoxA, Ret == 0);
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
        WriteFuncBuffer("(0x%p, \"%ws\", \"%ws\", %u)", hWnd, lpText, lpCaption, uType);
        Ret = MessageBoxW(hWnd, lpText, lpCaption, uType);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_MessageBoxW, Ret == 0);
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
        WriteFuncBuffer("(0x%p, \"%s\", \"%s\", %u, %hu)", hWnd, lpText, lpCaption, uType, wLanguageId);
        Ret = MessageBoxExA(hWnd, lpText, lpCaption, uType, wLanguageId);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_MessageBoxExA, Ret == 0);
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
        WriteFuncBuffer("(0x%p, \"%ws\", \"%ws\", %u, %hu)", hWnd, lpText, lpCaption, uType, wLanguageId);
        Ret = MessageBoxExW(hWnd, lpText, lpCaption, uType, wLanguageId);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_MessageBoxExW, Ret == 0);
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
        WriteFuncBuffer("(0x%p, 0x%p, %u, %u, %u)", lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
        Ret = PeekMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_PeekMessageA, FALSE);
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
        WriteFuncBuffer("(0x%p, 0x%p, %u, %u, %u)", lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
        Ret = PeekMessageW(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_PeekMessageW, FALSE);
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
        WriteFuncBuffer("(0x%p, %u, %u, %u)", hWnd, Msg, wParam, lParam);
        Ret = PostMessageA(hWnd, Msg, wParam, lParam);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_PostMessageA, Ret == FALSE);
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
        WriteFuncBuffer("(0x%p, %u, %u, %u)", hWnd, Msg, wParam, lParam);
        Ret = PostMessageW(hWnd, Msg, wParam, lParam);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_PostMessageW, Ret == FALSE);
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
    {
        WriteFuncBuffer("(%d) = VOID", nExitCode);
        EndTrace(E_PostQuitMessage, FALSE);
    }
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
        WriteFuncBuffer("(0x%p)", unnamedParam1);
        Ret = RegisterClassExA(unnamedParam1);
        WriteFuncBuffer(" = %hu", Ret);
        EndTrace(E_RegisterClassExA, Ret == 0);
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
        WriteFuncBuffer("(0x%p)", unnamedParam1);
        Ret = RegisterClassExW(unnamedParam1);
        WriteFuncBuffer(" = %hu", Ret);
        EndTrace(E_RegisterClassExW, Ret == 0);
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
        WriteFuncBuffer("(0x%p, 0x%p)", hWnd, hDC);
        Ret = ReleaseDC(hWnd, hDC);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_ReleaseDC, FALSE);
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
        WriteFuncBuffer("(0x%p, 0x%p)", hWnd, lpPoint);
        Ret = ScreenToClient(hWnd, lpPoint);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_ScreenToClient, Ret == FALSE);
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
        WriteFuncBuffer("(%d)", bShow);
        Ret = ShowCursor(bShow);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_ShowCursor, FALSE);
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
        WriteFuncBuffer("(0x%p, %d)", hWnd, nCmdShow);
        Ret = ShowWindow(hWnd, nCmdShow);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_ShowWindow, FALSE);
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
        WriteFuncBuffer("(0x%p)", lpMsg);
        Ret = TranslateMessage(lpMsg);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_TranslateMessage, FALSE);
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
        WriteFuncBuffer("(0x%p)", hWnd);
        Ret = UpdateWindow(hWnd);
        WriteFuncBuffer(" = %d", Ret);
        EndTrace(E_UpdateWindow, FALSE);
    }
    else
        Ret = UpdateWindow(hWnd);

    return Ret;
}


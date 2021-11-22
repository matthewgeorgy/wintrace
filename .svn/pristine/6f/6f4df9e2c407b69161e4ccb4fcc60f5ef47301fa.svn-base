#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int
main(void)
{
	WNDCLASSEX		WndClass = {0};
	HWND			Wnd;
	MSG				Msg;
	RECT			WndDim;
	INT				N = 0;


    printf("\n|------------TEST: %s------------|\n", __FILE__);
	WndClass.cbSize = sizeof(WndClass);
	WndClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = &WndProc;
	WndClass.hInstance = GetModuleHandle(NULL);
	WndClass.lpszClassName = "WinuserTestClass";

	if (!RegisterClassEx(&WndClass))
	{
		MessageBoxA(NULL, "Failed to register class!", "Error", MB_OK | MB_ICONERROR);
		return -1;
	}

	WndDim.left = 0;
	WndDim.top = 0;
	WndDim.right = 640;
	WndDim.bottom = 480;
	AdjustWindowRect(&WndDim, WS_OVERLAPPEDWINDOW, FALSE);

	Wnd = CreateWindowEx(0, WndClass.lpszClassName, "test_winuser", WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, WndDim.right - WndDim.left,
			WndDim.bottom - WndDim.top, NULL, NULL, WndClass.hInstance, NULL);

	if (!Wnd)
	{
		MessageBoxA(NULL, "Failed to create window!", "Error", MB_OK | MB_ICONERROR);
		return -1;
	}

	ShowWindow(Wnd, SW_SHOW);
	UpdateWindow(Wnd);

	// N = 0 -> N++ so that we have only 1 iteration of message handling
	while (N == 0)
	{
		if (PeekMessage(&Msg, 0, 0, 0, PM_REMOVE))
		{
			if (Msg.message == WM_QUIT)
				break;
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}
		N++;
	}
    printf("|-----------------------------|\n\n");

	return 0;
}

LRESULT CALLBACK 
WndProc(HWND hWnd, 
		UINT Msg, 
		WPARAM wParam, 
		LPARAM lParam)
{
	return DefWindowProc(hWnd, Msg, wParam, lParam);
}


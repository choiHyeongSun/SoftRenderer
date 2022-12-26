#include <Windows.h>
#include <iostream>

#include <Draw.h>

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

const int canvasWidth = 1280, canvasHeight = 720;
int main()
{
	WNDCLASSEX wc = {
		sizeof(WNDCLASSEX),
		CS_CLASSDC,
		WndProc,
		0L,
		0L,
		GetModuleHandle(NULL),
		NULL,
		NULL,
		NULL,
		NULL,
		L"HongLabGraphics",
		NULL
	};

	RegisterClassEx(&wc);
	RECT wr = { 0,0,canvasWidth , canvasHeight };
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

	HWND hwnd = CreateWindow(
		wc.lpszClassName,
		L"HongLabGraphics",
		WS_OVERLAPPEDWINDOW,
		100,
		100,
		wr.right - wr.left,
		wr.bottom - wr.top,
		NULL,
		NULL,
		wc.hInstance,
		NULL
	);

	ShowWindow(hwnd, SW_SHOWDEFAULT);
	UpdateWindow(hwnd);

	MSG msg = {};

	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}		
	}

	UnregisterClass(wc.lpszClassName, wc.hInstance);
	return 0;
}

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_DESTROY:
			::PostQuitMessage(0);
			return 0;
		case WM_PAINT:
			Drawing::Draw::SetPainter(hWnd);
			Drawing::Draw::DrawCoordinate(canvasWidth, canvasHeight, 30);
			Drawing::Draw::EndPainter(hWnd);
			return 0;
	}
	return ::DefWindowProc(hWnd, msg, wParam, lParam);
}
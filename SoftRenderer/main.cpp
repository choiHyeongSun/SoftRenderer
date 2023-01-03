#include <Windows.h>
#include <iostream>
#include <Draw.h>
#include "SoftRenderer/TimeManager.h"

//LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


const int canvasWidth = 1280, canvasHeight = 720;
int Frames;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	WNDCLASSEX wc = {
	sizeof(WNDCLASSEX),
	CS_HREDRAW | CS_VREDRAW,
	WndProc,
	0L,
	0L,
	hInstance,
	NULL,
	NULL,
	(HBRUSH)(COLOR_WINDOW + 1),
	L"SoftRenderer",
	L"SoftRenderer",
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
	TimeManager::Initialization();
	Drawing::Draw::Initlization(hwnd, canvasWidth, canvasHeight);

	Drawing::Draw::DoubleBuffering();
	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{	
			TimeManager::Update(hwnd);			
			Drawing::Draw::DrawCoordinate(30);

			static float X = 0;
			static float Y = 0;

			
			if (GetAsyncKeyState(VK_LEFT) & 0x8000)
			{
				X--;
			}
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			{
				X++;
			}

			if (GetAsyncKeyState(VK_UP) & 0x8000)
			{
				Y--;
			}
			if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			{
				Y++;
			}


			for (int i = -50; i < 50; i++)
			{
				for (int ii = -50; ii < 50; ii++)
				{
					if ((i * i) + (ii * ii) < pow(50,2))
					{
						Drawing::Draw::DrawPixel(i + 100 + X,ii + 100 + Y);
					}
				}
			}

			Drawing::Draw::DrawingEnd();			

			
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

	}
	return ::DefWindowProc(hWnd, msg, wParam, lParam);
}

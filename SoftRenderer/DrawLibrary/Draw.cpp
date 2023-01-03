
#include "Library/Draw.h"
#include "Library/Framework.h"
#include <cmath>
#include <iostream>

namespace Drawing
{


	int Draw::Width;
	int Draw::Height;
	HWND Draw::hWnd;
	HDC Draw::hdc;
	HDC Draw::memDC;
	HBITMAP Draw::hBit;
	void Draw::Initlization(const HWND hWnd, const int Width, const int Height)
	{
		Draw::Width = Width;
		Draw::Height = Height;
		Draw::hWnd = hWnd;		
		hdc = GetDC(hWnd);
	}

	const void Draw::Release()
	{
		ReleaseDC(hWnd, hdc);
		DeleteDC(memDC);
		DeleteObject(hBit);
	}


	void Draw::DrawCoordinate(float Spacing)
	{
		Rectangle(memDC, -1, -1, Width + 1, Height + 1);
		
		for (float i = -Width * 0.5f; i < Width * 0.5f; i += Spacing)
		{
			auto Start = Vector::Vector2(i, -Height * 0.5f);
			auto End = Vector::Vector2(i, Height);
			DrawLine(Start, End);
		}
		
		for (float i = -Height * 0.5f; i < Height * 0.5f; i += Spacing)
		{
			auto Start = Vector::Vector2(-Width * 0.5f, i);
			auto End = Vector::Vector2(Width * 0.5f, i);
			DrawLine(Start, End);
		}
	}


	

	

	void const Draw::DrawPixel(const float x, const float y, const COLORREF rgb)
	{
		SetPixel(memDC, std::round(x), std::round(y), rgb);
	}
	void const Draw::DrawPixel(const Vector::Vector2 v, const COLORREF rgb)
	{
		DrawPixel(v.x, v.y, rgb);
	}
	void const Draw::DrawPixel(const Vector::Vector3 v, const COLORREF rgb)
	{
		DrawPixel(v.x, v.y, rgb);
	}
	void const Draw::DrawPixel(const Vector::Vector4 v, const COLORREF rgb)
	{
		DrawPixel(v.x, v.y, rgb);
	}




	void const Draw::DrawLine(const float fromX, const float fromY, const float toX, const float toY, const COLORREF rgb)
	{		
		
		MoveToEx(memDC, std::round(fromX) + Width * 0.5f, std::round(fromY) + Height * 0.5f, nullptr);
		LineTo(memDC, std::round(toX) + Width * 0.5f, std::round(toY) + Height * 0.5f);
	}

	void const Draw::DrawLine(const Vector::Vector2 from, const Vector::Vector2 to, const COLORREF rgb)
	{
		DrawLine(from.x, from.y, to.x, to.y, rgb);
	}

	void const Draw::DrawLine(const Vector::Vector3 from, const Vector::Vector3 to, const COLORREF rgb)
	{
		DrawLine(from.x, from.y, to.x, to.y, rgb);
	}

	void const Draw::DrawLine(const Vector::Vector4 from, const Vector::Vector4 to, const COLORREF rgb)
	{
		DrawLine(from.x, from.y, to.x, to.y, rgb);
	}

	void Draw::DoubleBuffering()
	{
		//이중 버퍼 
		hBit = CreateCompatibleBitmap(hdc, Width, Height);
		memDC = CreateCompatibleDC(hdc);

		HBITMAP OldBit = (HBITMAP)SelectObject(memDC, hBit);
		DeleteObject(OldBit);
	}

	void const Draw::DrawingEnd()
	{
		BitBlt(hdc, 0, 0, Width, Height, memDC, 0, 0 , SRCCOPY);
	}


	




}


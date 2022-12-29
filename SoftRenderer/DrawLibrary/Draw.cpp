
#include "Library/Draw.h"
#include "Library/Framework.h"
#include <cmath>
#include <iostream>

namespace Drawing
{

	HDC Draw::DrawHDC;
	PAINTSTRUCT Draw::DrawPainter;
	int Draw::Width;
	int Draw::Height;

	void Draw::SetHDC(HWND hWnd)
	{
		DrawHDC = GetDC(hWnd);
	}

	void Draw::ReleaseHDC(HWND hWnd)
	{
		ReleaseDC(hWnd, DrawHDC);
	}

	void Draw::SetPainter(HWND hWnd)
	{
		DrawHDC = BeginPaint(hWnd, &DrawPainter) ;
	}

	void Draw::EndPainter(HWND hWnd)
	{
		EndPaint(hWnd, &DrawPainter);
	}

	HDC Draw::GetHDC()
	{
		return DrawHDC;
	}

	void Draw::DrawCoordinate(int Width, int Height, float Spacing)
	{
		static int data = 0;
		data+=30;
		
		Draw::Width = Width;
		Draw::Height = Height;


		auto v = Vector::Vector2(data, 0.0f);
		auto v1 = Vector::Vector2(0.0f , data);

		Matrix::Matrix2x2 RotateMat(v, v1);
		auto Scale = RotateMat * Vector::Vector2(1, 1);

		for (float i = 0; i < Width; i += Scale.x)
		{
			auto Start = Vector::Vector2(i, 0.0f);
			auto End = Vector::Vector2(i, Height);
			DrawLine(Start, End);
		}

		for (float i = 0; i < Height; i += Scale.y)
		{
			auto Start = Vector::Vector2(0.0f, i);
			auto End = Vector::Vector2(Width, i);
			DrawLine(Start, End);
		}

	}



	void Draw::DrawPixel(float x, float y, COLORREF rgb)
	{
		SetPixel(DrawHDC, std::round(x), std::round(y), rgb);
	}
	void Draw::DrawPixel(Vector::Vector2 v, COLORREF rgb)
	{
		DrawPixel(v.x, v.y, rgb);
	}
	void Draw::DrawPixel(Vector::Vector3 v, COLORREF rgb)
	{
		DrawPixel(v.x, v.y, rgb);
	}
	void Draw::DrawPixel(Vector::Vector4 v, COLORREF rgb)
	{
		DrawPixel(v.x, v.y, rgb);
	}




	void Draw::DrawLine(float fromX, float fromY, float toX, float toY, COLORREF rgb)
	{
		SetDCBrushColor(DrawHDC, rgb);
		MoveToEx(DrawHDC, std::round(fromX), std::round(fromY), nullptr);
		LineTo(DrawHDC, std::round(toX), std::round(toY));
	}

	void Draw::DrawLine(Vector::Vector2 from, Vector::Vector2 to, COLORREF rgb)
	{
		DrawLine(from.x, from.y, to.x, to.y, rgb);
	}

	void Draw::DrawLine(Vector::Vector3 from, Vector::Vector3 to, COLORREF rgb)
	{
		DrawLine(from.x, from.y, to.x, to.y, rgb);
	}

	void Draw::DrawLine(Vector::Vector4 from, Vector::Vector4 to, COLORREF rgb)
	{
		DrawLine(from.x, from.y, to.x, to.y, rgb);
	}




}


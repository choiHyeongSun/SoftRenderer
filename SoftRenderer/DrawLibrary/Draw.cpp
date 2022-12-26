
#include "Library/Draw.h"
#include "Library/Framework.h"
#include <cmath>


namespace Drawing
{
	
	HDC Draw::DrawHDC;
	PAINTSTRUCT Draw::DrawPainter;
	int Draw::Width;
	int Draw::Height;

	constexpr void Draw::SetHDC(HWND hWnd)
	{
		DrawHDC = GetDC(hWnd);
	}

	constexpr void Draw::ReleaseHDC(HWND hWnd)
	{
		ReleaseDC(hWnd, DrawHDC);
	}

	constexpr void Draw::SetPainter(HWND hWnd)
	{
		DrawHDC = BeginPaint(hWnd, &DrawPainter);
	}

	constexpr void Draw::EndPainter(HWND hWnd)
	{
		EndPaint(hWnd , &DrawPainter);
	}

	constexpr HDC Draw::GetHDC()
	{
		return DrawHDC;		
	}

	constexpr void Draw::DrawCoordinate(int Width, int Height , float Spacing)
	{
		Draw::Width = Width;
		Draw::Height = Height;

		for (float i = 0; i < Width; i += Spacing)
		{
			DrawLine(i, 0.0f, i , Height);
		}

		for (float i = 0; i < Height; i += Spacing)
		{
			DrawLine(0.0f, i, Width, i);
		}

	}


	
	constexpr void Draw::DrawPixel(float x, float y, COLORREF rgb)
	{		
		SetPixel(DrawHDC, std::round(x), std::round(y), rgb);
	}
	constexpr void Draw::DrawPixel(Vector::Vector2 v , COLORREF rgb)
	{
		DrawPixel(v.x, v.y, rgb);
	}
	constexpr void Draw::DrawPixel(Vector::Vector3 v , COLORREF rgb)
	{
		DrawPixel(v.x, v.y, rgb);
	}
	constexpr void Draw::DrawPixel(Vector::Vector4 v , COLORREF rgb)
	{		
		DrawPixel(v.x, v.y, rgb);		
	}




	constexpr void Draw::DrawLine(float fromX, float fromY, float toX, float toY, COLORREF rgb)
	{
		SetDCBrushColor(DrawHDC, rgb);
		MoveToEx(DrawHDC, std::round(fromX) , std::round(fromY), nullptr);
		LineTo(DrawHDC, std::round(toX), std::round(toY));
	}

	constexpr void Draw::DrawLine(Vector::Vector2 from, Vector::Vector2 to, COLORREF rgb)
	{
		DrawLine(from.x, from.y, to.x, to.y, rgb);
	}

	constexpr void Draw::DrawLine(Vector::Vector3 from, Vector::Vector3 to, COLORREF rgb)
	{
		DrawLine(from.x, from.y, to.x, to.y, rgb);
	}

	constexpr void Draw::DrawLine(Vector::Vector4 from, Vector::Vector4 to, COLORREF rgb)
	{
		DrawLine(from.x, from.y, to.x, to.y, rgb);
	}


	

}


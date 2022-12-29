#pragma once
#include <Windows.h>



namespace Vector
{
	class Vector2;
	class Vector3;
	class Vector4;
}
 

namespace Drawing
{

	class Draw
	{

	private:				
		Draw() = delete;

		static int Width;
		static int Height;
		static HWND hWnd;
		static HDC hdc;
		static HDC memDC;
		static HBITMAP hBit;

		

	public:
		static void Initlization(const HWND hWnd, const int Width, const int Height);
		static void DrawCoordinate(const float Spacing);		
		static const void Release();
					
		static const void DrawPixel(const float x, const float y, const COLORREF rgb = 0x00000000);
		static const void DrawPixel(const Vector::Vector2 v, const COLORREF rgb = 0x00000000);
		static const void DrawPixel(const Vector::Vector3 v, const COLORREF rgb = 0x00000000);
		static const void DrawPixel(const Vector::Vector4 v , const COLORREF rgb = 0x00000000);

		static const void DrawLine(const float fromX , const float fromY , const float toX , const float toY, const COLORREF rgb = 0x00000000);
		static const void DrawLine(const Vector::Vector2 from, const Vector::Vector2 to, const COLORREF rgb = 0x00000000);
		static const void DrawLine(const Vector::Vector3 from, const Vector::Vector3 to, const COLORREF rgb = 0x00000000);
		static const void DrawLine(const Vector::Vector4 from, const Vector::Vector4 to, const COLORREF rgb = 0x00000000);

		static void DoubleBuffering();
		static const void DrawingEnd();		
		
	};



}

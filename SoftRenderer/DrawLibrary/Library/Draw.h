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
		static HDC DrawHDC;
		static PAINTSTRUCT DrawPainter;
		static int Width;
		static int Height;

	public:
		static void DrawCoordinate(int Width, int Height , float Spacing);
		static void SetHDC(HWND hWnd);
		static void ReleaseHDC(HWND hWnd);
		static void SetPainter(HWND hWnd);
		static void EndPainter(HWND hWnd);

		static constexpr HDC GetHDC();


		static void DrawPixel(float x, float y, COLORREF rgb = 0x00FFFFFF);
		static void DrawPixel(Vector::Vector2 v , COLORREF rgb = 0x00FFFFFF);
		static void DrawPixel(Vector::Vector3 v , COLORREF rgb = 0x00FFFFFF);
		static void DrawPixel(Vector::Vector4 v , COLORREF rgb = 0x00FFFFFF);

		static void DrawLine(float fromX , float fromY , float toX , float toY, COLORREF rgb = 0x00FFFFFF);
		static void DrawLine(Vector::Vector2 from, Vector::Vector2 to, COLORREF rgb = 0x00FFFFFF);
		static void DrawLine(Vector::Vector3 from, Vector::Vector3 to, COLORREF rgb = 0x00FFFFFF);
		static void DrawLine(Vector::Vector4 from, Vector::Vector4 to, COLORREF rgb = 0x00FFFFFF);
		
	};



}

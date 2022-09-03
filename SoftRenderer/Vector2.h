#pragma once
#include <cmath>
namespace Vector
{
	class Vector2
	{
	public:

		Vector2(float _x, float _y) {
			x = _x;
			y = _y;
		}


		float x;
		float y;

	public:
		inline float Dot(Vector2 v1);
		inline Vector2 Normalize();
		inline void Scale(Vector2 v1);
		inline float Distance(Vector2 v1);


	public:
		static float Dot(Vector2 v1, Vector2 v2)
		{
			return v1.x * v2.x + v1.y * v2.y;
		}
		static Vector2 Normalize(Vector2 v1)
		{

			float Distance = sqrt(v1.x * v1.x + v1.y * v1.y);
			Vector2 Result(v1.x / Distance, v1.y / Distance);
			return Result;
		}
		static float Distance(Vector2 v1, Vector2 v2)
		{
			Vector2 TempX = v1 - v2;
			return sqrt(abs(TempX.x * TempX.x + TempX.y * TempX.y));
		}
		static Vector2 Scale(Vector2 v1, Vector2 v2)
		{
			return Vector2(v1.x * v2.x, v1.y * v1.y);
		}
		static Vector2 Lerp(Vector2 v1, Vector2 v2, float t)
		{
			if (t > 1.0f)
				t = 1.0f;
			else if (t < 0.0f)
				t = 0.0f;

			return Vector2((1.0f - t) * v1.x + v2.x * t, (1.0f - t) * v1.y + v2.y * t);
		}

	public:
		inline Vector2 operator+(Vector2 v);
		inline Vector2 operator= (Vector2 v);
		inline Vector2 operator-(Vector2 v);
		inline Vector2 operator*(float s);
		inline void operator+= (Vector2 v);
		inline void operator-= (Vector2 v);
		inline void operator*=(float s);
	}; 



	float Vector2::Dot(Vector2 v1)
	{
		return x * v1.x + y * v1.y;
	}

	Vector2 Vector2::Normalize()
	{
		float Distance = sqrt(x * x + y * y);
		Vector2 Result(x / Distance, y / Distance);
		return Result;
	}

	inline void Vector2::Scale(Vector2 v1)
	{
		x *= v1.x;
		y *= v1.y;
	}

	inline float Vector2::Distance(Vector2 v1)
	{
		Vector2 TempX = Vector2(x, y) - v1;
		return sqrt(abs(TempX.x * TempX.x + TempX.y * TempX.y));

	}



	inline Vector2 Vector2::operator+(Vector2 v)
	{
		Vector2 TempVec = v;
		TempVec.x += x;
		TempVec.y += y;
		return TempVec;
	}

	inline Vector2 Vector2::operator-(Vector2 v)
	{
		Vector2 TempVec = v;
		TempVec.x -= x;
		TempVec.y -= y;
		return TempVec;
	}

	inline Vector2 Vector2::operator*(float s)
	{
		return Vector2(x * s, y * s);
	}

	inline void Vector2::operator+=(Vector2 v)
	{
		x += v.x;
		y += v.y;		
	}

	inline void Vector2::operator-=(Vector2 v)
	{
		x -= v.x;
		y -= v.y;
	}

	inline void Vector2::operator*=(float s)
	{
		x *= s;
		y *= s;
	}

	inline Vector2 Vector2::operator= (Vector2 v)
	{
		x = v.x;
		y = v.y;
		return Vector2(x, y);
	}
	
}
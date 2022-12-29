#pragma once
#include <cmath>

namespace Vector
{

	class Vector2
	{	
		
	public :
		float x;
		float y;

	public:

		Vector2() = delete;
		Vector2(float _x, float _y) 
		{
			x = _x;
			y = _y;
		}
		
	public:
		inline float Dot(const Vector2 v1) const;
		inline Vector2 Normalize() const;
		inline void Scale(const Vector2 v1);
		inline float Distance(const Vector2 v1);


	public:
		static const float Dot(const Vector2 v1, const Vector2 v2)
		{
			return v1.x * v2.x + v1.y * v2.y;
		}

		static const Vector2 Normalize(const Vector2 v1)
		{

			float Distance = sqrt(v1.x * v1.x + v1.y * v1.y);
			Vector2 Result(v1.x / Distance, v1.y / Distance);
			return Result;
		}

		static const float Distance(const Vector2 v1, const Vector2 v2)
		{
			Vector2 TempX = v1 - v2;
			return sqrt(abs(TempX.x * TempX.x + TempX.y * TempX.y));
		}

		static const Vector2 Scale(const Vector2 v1, const Vector2 v2)
		{
			return Vector2(v1.x * v2.x, v1.y * v1.y);
		}

		static const Vector2 Lerp(const Vector2 v1, const Vector2 v2, float t)
		{
			if (t > 1.0f)
				t = 1.0f;
			else if (t < 0.0f)
				t = 0.0f;

			return Vector2((1.0f - t) * v1.x + v2.x * t, (1.0f - t) * v1.y + v2.y * t);
		}

		static const Vector2 GetZeroVector()
		{
			return Vector2(0.0f, 0.0f);
		}

	public:
		
		inline Vector2 operator+(const Vector2 & v) const;		
		inline Vector2 operator-(const Vector2 & v) const;
		inline Vector2 operator*(const float & s) const;
		inline void operator+= (const Vector2 & v);
		inline void operator-= (const Vector2 & v);
		inline void operator*=(const float & s);
		inline void operator= (const Vector2 & v);
	};





	inline float Vector2::Dot(const Vector2 v1) const
	{	
		return x * v1.x + y * v1.y;
	}

	inline Vector2 Vector2::Normalize() const
	{
		float Distance = sqrt(x * x + y * y);
		Vector2 Result(x / Distance, y / Distance);
		return Result;
	}

	inline void Vector2::Scale(const Vector2 v1) 
	{
		x *= v1.x;
		y *= v1.y;
	}

	inline float Vector2::Distance(const Vector2 v1)
	{
		Vector2 TempX = Vector2(x, y) - v1;
		return sqrt(abs(TempX.x * TempX.x + TempX.y * TempX.y));

	}





	inline Vector2 Vector2::operator+(const Vector2 & v) const
	{		
		return Vector2(x + v.x, y + v.y);
	}

	inline Vector2 Vector2::operator-(const Vector2 & v) const
	{			
		return Vector2(x - v.x, y - v.y);
	}

	inline Vector2 Vector2::operator*(const float & s) const
	{
		return Vector2(x * s, y * s);
	}

	inline void Vector2::operator+=(const Vector2 & v)
	{
		x += v.x;
		y += v.y;
	}

	inline void Vector2::operator-=(const Vector2 &v)
	{
		x -= v.x;
		y -= v.y;
	}

	inline void Vector2::operator*=(const float & s)
	{		
		x *= s;
		y *= s;
	}

	inline void Vector2::operator= (const Vector2 & v)
	{
		x = v.x;
		y = v.y;		
	}


}
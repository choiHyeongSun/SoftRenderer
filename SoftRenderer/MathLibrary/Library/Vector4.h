#pragma once
#include <cmath>

namespace Vector
{
	class Vector4
	{
	public:
		Vector4() = delete;
		Vector4(float _x, float _y, float _z, float _w)
		{
			x = _x;
			y = _y;
			z = _z;
			w = _w;
		}

		float x;
		float y;
		float z;
		float w;


	public:
		inline float Dot(const Vector4 v1) const;
		inline float Distance(const Vector4 v1) const;
		inline void Scale(const Vector4 v1);
		inline Vector4 Normalize() const;


	public:

		static const float Dot(const Vector4 v1, const Vector4 v2)
		{
			return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
		}
		static const Vector4 Normalize(const Vector4 v1)
		{
			float Distance = sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z + v1.w * v1.w);
			return Vector4(v1.x / Distance, v1.y / Distance, v1.z / Distance, v1.w / Distance);
		}
		static const float Distance(const Vector4 v1, const Vector4 v2)
		{
			Vector4 Temp = Vector4(abs(v1.x - v2.x), abs(v1.y - v2.y), abs(v1.z - v2.z), abs(v1.w - v2.w));
			float dist = sqrt(Temp.x * Temp.x + Temp.y * Temp.y + Temp.z * Temp.z + Temp.w * Temp.w);
			return dist;
		}
		static const Vector4 Scale(const Vector4 v1, const Vector4 v2) 
		{
			return Vector4(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w);
		}
		static const Vector4 Lerp(const Vector4 v1, const Vector4 v2, float t)
		{

			if (t > 1.0f)
			{
				t = 1.0f;
			}
			else if (t < 0.0f)
			{
				t = 0.0f;
			}
			return Vector4((1.0f - t) * v1.x + t * v2.x,
				(1.0f - t) * v1.y + t * v2.y,
				(1.0f - t) * v1.z + t * v2.z,
				(1.0f - t) * v1.w + t * v2.w);
		}
		static Vector4 zeroVector()
		{
			return Vector4(0, 0, 0, 0);
		}

	public:
		inline Vector4 operator+ (const Vector4 & v1) const;
		inline Vector4 operator- (const Vector4 & v1) const;
		inline void operator= (const Vector4 & v1);
		inline Vector4 operator*(const float & s) const;
		inline void operator+= (const Vector4 & v);
		inline void operator-= (const Vector4 & v);
		inline void operator*=(const float & s);


	};

	inline float Vector4::Dot(const Vector4 v1) const
	{
		return (x * v1.x) + (y * v1.y) + (z * v1.z) + (w * v1.w);
	}

	inline float Vector4::Distance(const Vector4 v1)const
	{
		Vector4 Temp = Vector4(x, y, z, w) - v1;
		float Dist = sqrt(Temp.x * Temp.x + Temp.y * Temp.y + Temp.z * Temp.z);
		return Dist;
	}

	inline void Vector4::Scale(const Vector4 v1)
	{
		x *= v1.x;
		y *= v1.y;
		z *= v1.z;
	}

	inline Vector4 Vector4::Normalize() const
	{
		float Distance = sqrt(x * x + y * y + z * z + w * w);
		return Vector4(x / Distance, y / Distance, z / Distance, w / Distance);
	}

	inline Vector4 Vector4::operator+(const Vector4 & v1) const
	{
		return Vector4(x + v1.x, y + v1.y, z + v1.z, w + v1.w);
	}

	inline Vector4 Vector4::operator-(const Vector4 & v1) const
	{
		return Vector4(x - v1.x, y - v1.y, z - v1.z, w - v1.w);
	}

	inline void Vector4::operator=(const Vector4 & v1)
	{
		x = v1.x;
		y = v1.y;
		z = v1.z;
		w = v1.w;
	}

	inline Vector4 Vector4::operator*(const float & s) const
	{
		return Vector4(x * s, y * s, z * s, w * s);
	}

	inline void Vector4::operator+=(const Vector4 & v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;
	}

	inline void Vector4::operator-=(const Vector4 & v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;
	}

	inline void Vector4::operator*=(const float & s)
	{
		x *= s;
		y *= s;
		z *= s;
		w *= s;
	}

}

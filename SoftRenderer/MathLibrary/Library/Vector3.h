#pragma once
#include <cmath>
namespace Vector
{
	
	class Vector3
	{
	public:
		Vector3() = delete;
		Vector3(float _x, float _y, float _z)
		{
			x = _x;
			y = _y;
			z = _z;
		}
		float x;
		float y;
		float z;

	public:
		inline float Dot(const Vector3 v1);
		inline Vector3 Cross(const Vector3 v1) const;
		inline float Distance(const Vector3 v1) const;
		inline inline void Scale(const Vector3 v1);
		inline Vector3 Normalize();

	public:
		static const float Dot(const Vector3 & v1, const Vector3 & v2)
		{
			return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
		}

		static const Vector3 Normalize(const Vector3 & v1)
		{
			float Distance = sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
			return Vector3(v1.x / Distance, v1.y / Distance, v1.z / Distance);
		}

		static const float Distance(const Vector3 & v1, const Vector3 & v2)
		{
			Vector3 Temp = Vector3(abs(v1.x - v2.x), abs(v1.y - v2.y), abs(v1.z - v2.z));
			float dist = sqrt(Temp.x * Temp.x + Temp.y * Temp.y + Temp.z * Temp.z);
			return dist;
		}

		static const Vector3 Scale(const Vector3 & v1, const Vector3 & v2)
		{			
			return Vector3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
		}

		static const Vector3 Lerp(const Vector3 & v1, const Vector3 & v2, float t)
		{
			if (t < 1.0f)
				t = 1.0f;
			else if (t > 0.0f)
				t = 0.0f;

			return Vector3((1.0f - t) * v1.x + t * v2.x,
						   (1.0f - t) * v1.y + t * v2.y,
						   (1.0f - t) * v1.z + t * v2.z);
		}

		static const Vector3 ZeroVector()
		{
			return Vector3(0, 0, 0);
		}

	public:
		inline Vector3 operator+ (const Vector3 & v1) const;
		inline Vector3 operator- (const Vector3 & v1) const;		
		inline Vector3 operator*(const float & s) const;

		inline void operator+= (const Vector3 & v);
		inline void operator-= (const Vector3 & v);
		inline void operator*=(const float & s);
		inline void operator= (const Vector3 & v1);
	};

	inline float Vector3::Dot(const Vector3 v1)
	{
		return x * v1.x + y * v1.y + z * v1.z;
	}

	inline Vector3 Vector3::Cross(const Vector3 v1) const
	{
		Vector3 Result = ZeroVector();
		float CrossX = y * v1.z - z * v1.y;
		float CrossY = x * v1.z - z * v1.x;
		float CrossZ = x * v1.y - y * v1.x;
		
		return Vector3(CrossX, CrossY , CrossZ);
	}

	inline float Vector3::Distance(const Vector3 v1) const
	{
		Vector3 Temp = Vector3(x, y, z) - v1;
		float Dist = sqrt(Temp.x * Temp.x + Temp.y * Temp.y + Temp.z * Temp.z);
		return Dist;
	}

	inline void Vector3::Scale(const Vector3 v1)
	{
		x *= v1.x;
		y *= v1.y;
		z *= v1.z;
	}

	inline Vector3 Vector3::Normalize()
	{
		float Distance = sqrt(x * x + y * y + z * z);
		return Vector3(x / Distance, y / Distance, z / Distance);
	}

	inline Vector3 Vector3::operator+(const Vector3 & v1) const
	{
		return Vector3(x + v1.x, y + v1.y, z + v1.z);
	}

	inline Vector3 Vector3::operator-(const Vector3 & v1) const
	{
		return Vector3(x - v1.x, y - v1.y, z - v1.z);
	}

	inline void Vector3::operator=(const Vector3 & v1) 
	{
		x = v1.x;
		y = v1.y;
		z = v1.z;
	}

	inline Vector3 Vector3::operator*(const float & s) const
	{
		return Vector3(x * s, y * s, z * s);
	}

	inline void Vector3::operator+=(const Vector3 & v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
	}

	inline void Vector3::operator-=(const Vector3 & v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}

	inline void Vector3::operator*=(const float & s)
	{
		x *= s;
		y *= s;
		z *= s;
	}
}


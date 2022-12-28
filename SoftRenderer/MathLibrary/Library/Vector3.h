#pragma once
#include <cmath>
namespace Vector
{
	
	class Vector3
	{
	public:
		Vector3() = default;
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
		inline float Dot(Vector3 v1);
		inline Vector3 Cross(Vector3 v1);
		inline float Distance(Vector3 v1);
		inline void Scale(Vector3 v1);
		inline Vector3 Normalize();

	public:
		static float Dot(Vector3 v1, Vector3 v2)
		{
			return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
		}
		static Vector3 Normalize(Vector3 v1)
		{
			float Distance = sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
			return Vector3(v1.x / Distance, v1.y / Distance, v1.z / Distance);
		}
		static float Distance(Vector3 v1, Vector3 v2)
		{
			Vector3 Temp = Vector3(abs(v1.x - v2.x), abs(v1.y - v2.y), abs(v1.z - v2.z));
			float dist = sqrt(Temp.x * Temp.x + Temp.y * Temp.y + Temp.z * Temp.z);
			return dist;
		}
		static Vector3 Scale(Vector3 v1, Vector3 v2)
		{
			return Vector3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
		}
		static Vector3 Lerp(Vector3 v1, Vector3 v2, float t)
		{
			
			return Vector3((1.0f - t) * v1.x + t * v2.x,
						   (1.0f - t) * v1.y + t * v2.y,
						   (1.0f - t) * v1.z + t * v2.z);
		}
		static Vector3 ZeroVector()
		{
			return Vector3(0, 0, 0);
		}

	public:
		inline Vector3 operator+ (Vector3 v1);
		inline Vector3 operator- (Vector3 v1);
		inline void operator= (Vector3 v1);
		inline Vector3 operator*(float s);
		inline void operator+= (Vector3 v);
		inline void operator-= (Vector3 v);
		inline void operator*=(float s);
	};

	float Vector3::Dot(Vector3 v1)
	{
		return x * v1.x + y * v1.y + z * v1.z;
	}

	inline Vector3 Vector3::Cross(Vector3 v1)
	{
		Vector3 Result = ZeroVector();
		float CrossX = y * v1.z - z * v1.y;
		float CrossY = x * v1.z - z * v1.x;
		float CrossZ = x * v1.y - y * v1.x;
		
		return Vector3(CrossX, CrossY , CrossZ);
	}

	inline float Vector3::Distance(Vector3 v1)
	{
		Vector3 Temp = Vector3(x, y, z) - v1;
		float Dist = sqrt(Temp.x * Temp.x + Temp.y * Temp.y + Temp.z * Temp.z);
		return Dist;
	}

	inline void Vector3::Scale(Vector3 v1)
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

	inline Vector3 Vector3::operator+(Vector3 v1)
	{
		return Vector3(x + v1.x, y + v1.y, z + v1.z);
	}

	inline Vector3 Vector3::operator-(Vector3 v1)
	{
		return Vector3(x - v1.x, y - v1.y, z - v1.z);
	}

	inline void Vector3::operator=(Vector3 v1)
	{
		x = v1.x;
		y = v1.y;
		z = v1.z;
	}

	inline Vector3 Vector3::operator*(float s)
	{
		return Vector3(x * s, y * s, z * s);
	}

	inline void Vector3::operator+=(Vector3 v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
	}

	inline void Vector3::operator-=(Vector3 v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}

	inline void Vector3::operator*=(float s)
	{
		x *= s;
		y *= s;
		z *= s;
	}
}


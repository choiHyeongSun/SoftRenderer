#pragma once
#include "Vector3.h"
#include <iostream>



namespace Matrix
{
	using namespace Vector;

	class Matrix3x3
	{
	private:

		Matrix3x3(float _11, float _12, float _13, float _21, float _22, float _23, float _31, float _32, float _33)
		{
			this->_11 = _11;
			this->_12 = _12;
			this->_13 = _13;
			this->_21 = _21;
			this->_22 = _22;
			this->_23 = _23;
			this->_31 = _31;
			this->_32 = _32;
			this->_33 = _33;
		}
		float _11;	float _12;	float _13;
		float _21;	float _22;	float _23;
		float _31;	float _32;	float _33;

	public:

		Matrix3x3(Vector3 v1, Vector3 v2, Vector3 v3)
		{
			_11 = v1.x;
			_12 = v1.y;
			_13 = v1.z;

			_21 = v2.x;
			_22 = v2.y;
			_23 = v2.z;

			_31 = v3.x;
			_32 = v3.y;
			_33 = v3.z;

		}

	public:

		inline const void TransPosed();

	public:

		static const Matrix3x3 IdentityMatrix()
		{
			return (Matrix3x3(1, 0, 0, 0, 1, 0, 0, 0, 1));
		}
		static const Matrix3x3 Transposed(const Matrix3x3 & _Mat);
		static const Matrix3x3 ZeroMatrix();

	public:

		inline Matrix3x3 operator+ (const Matrix3x3 & mat1) const;
		inline Matrix3x3 operator- (const Matrix3x3 & mat1) const;
		inline Matrix3x3 operator* (const Matrix3x3 & mat1) const;
		inline Matrix3x3 operator* (const float & s) const;
		inline Vector3 operator* (const Vector3 & v) const;
		inline void operator= (const Matrix3x3 & mat1);


		void ShowMatrix()
		{
			std::cout << _11 << " " << _12 << " " << _13 << std::endl;
			std::cout << _21 << " " << _22 << " " << _23 << std::endl;
			std::cout << _31 << " " << _32 << " " << _33 << std::endl;

			std::cout << std::endl;

		}
	};

	inline const void Matrix3x3::TransPosed()
	{
		const Matrix3x3 mat = *this;

		_11 = mat._11;	_12 = mat._21;	_13 = mat._31;
		_21 = mat._12;	_22 = mat._22;	_23 = mat._32;
		_31 = mat._13;	_32 = mat._23;	_33 = mat._33;
	}

	inline const Matrix3x3 Matrix3x3::Transposed(const Matrix3x3 & _Mat)
	{


		float _T11 = _Mat._11; 	float _T12 = _Mat._21;	float _T13 = _Mat._31;
		float _T21 = _Mat._12;	float _T22 = _Mat._22;	float _T23 = _Mat._32;
		float _T31 = _Mat._13;	float _T32 = _Mat._23;	float _T33 = _Mat._33;

		return Matrix3x3(_T11, _T12, _T13, _T21, _T22, _T23, _T31, _T32, _T33);

	}

	inline const Matrix3x3 Matrix3x3::ZeroMatrix()
	{
		return Matrix3x3(0, 0, 0, 0, 0, 0, 0, 0, 0);
	}

	inline Matrix3x3 Matrix3x3::operator+(const Matrix3x3 & mat1) const
	{
		float _T11 = _11 + mat1._11;
		float _T12 = _12 + mat1._12;
		float _T13 = _13 + mat1._13;
		float _T21 = _21 + mat1._21;
		float _T22 = _22 + mat1._22;
		float _T23 = _23 + mat1._23;
		float _T31 = _31 + mat1._31;
		float _T32 = _32 + mat1._32;
		float _T33 = _33 + mat1._33;

		return Matrix3x3(_T11, _T12, _T13, _T21, _T22, _T23, _T31, _T32, _T33);
	}

	inline void Matrix3x3::operator=(const Matrix3x3 & mat1)
	{
		_11 = mat1._11;
		_12 = mat1._12;
		_13 = mat1._13;
		_21 = mat1._21;
		_22 = mat1._22;
		_23 = mat1._23;
		_31 = mat1._31;
		_32 = mat1._32;
		_33 = mat1._33;
	}

	inline Matrix3x3 Matrix3x3::operator*(const Matrix3x3 & mat1) const
	{
		float e1 = _11 * mat1._11 + _12 * mat1._21 + _13 * mat1._31;
		float e2 = _11 * mat1._12 + _12 * mat1._22 + _13 * mat1._32;
		float e3 = _11 * mat1._13 + _12 * mat1._23 + _13 * mat1._33;

		float e4 = _21 * mat1._11 + _22 * mat1._21 + _23 * mat1._31;
		float e5 = _21 * mat1._12 + _22 * mat1._22 + _23 * mat1._32;
		float e6 = _21 * mat1._13 + _22 * mat1._23 + _23 * mat1._33;

		float e7 = _31 * mat1._11 + _32 * mat1._21 + _33 * mat1._31;
		float e8 = _31 * mat1._12 + _32 * mat1._22 + _33 * mat1._32;
		float e9 = _31 * mat1._13 + _32 * mat1._23 + _33 * mat1._33;


		return Matrix3x3(e1, e2, e3, e4, e5, e6, e7, e8, e9);
	}

	inline Matrix3x3 Matrix3x3::operator-(const Matrix3x3 & mat1) const
	{

		float _T11 = _11 - mat1._11;
		float _T12 = _12 - mat1._12;
		float _T13 = _13 - mat1._13;
		float _T21 = _21 - mat1._21;
		float _T22 = _22 - mat1._22;
		float _T23 = _23 - mat1._23;
		float _T31 = _31 - mat1._31;
		float _T32 = _32 - mat1._32;
		float _T33 = _33 - mat1._33;

		return Matrix3x3(_T11, _T12, _T13, _T21, _T22, _T23, _T31, _T32, _T33);

	}

	inline Matrix3x3 Matrix3x3::operator*(const float & s) const
	{


		float _T11 = _11 * s;
		float _T12 = _12 * s;
		float _T13 = _13 * s;
		float _T21 = _21 * s;
		float _T22 = _22 * s;
		float _T23 = _23 * s;
		float _T31 = _31 * s;
		float _T32 = _32 * s;
		float _T33 = _33 * s;

		return Matrix3x3(_T11, _T12, _T13, _T21, _T22, _T23, _T31, _T32, _T33);

	}

	inline Vector3 Matrix3x3::operator*(const Vector3 & v) const
	{
		float ResultX = v.x * _11 + v.y * _12 + v.z * _13;
		float ResultY = v.x * _21 + v.y * _22 + v.z * _23;
		float ResultZ = v.x * _31 + v.y * _32 + v.z * _33;

		return Vector3(ResultX, ResultY, ResultZ);
	}


}
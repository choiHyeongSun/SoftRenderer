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

		inline void TransPosed();

	public:

		static Matrix3x3 IdentityMatrix()
		{
			return (Matrix3x3(1, 0, 0, 0, 1, 0, 0, 0, 1));
		}
		static Matrix3x3 Transposed(Matrix3x3 _Mat);
		static Matrix3x3 ZeroMatrix();

	public:

		inline Matrix3x3 operator+ (Matrix3x3 mat1);
		inline Matrix3x3 operator- (Matrix3x3 mat1);
		inline Matrix3x3 operator= (Matrix3x3 mat1);
		inline Matrix3x3 operator* (Matrix3x3 mat1);
		inline Matrix3x3 operator* (float s);
		inline Vector3 operator* (Vector3 v);


		void ShowMatrix()
		{
			std::cout << _11 << " " << _12 << " " << _13 << std::endl;
			std::cout << _21 << " " << _22 << " " << _23 << std::endl;
			std::cout << _31 << " " << _32 << " " << _33 << std::endl;

			std::cout << std::endl;

		}
	};

	inline void Matrix3x3::TransPosed()
	{
		Matrix3x3 mat = ZeroMatrix();

		_11 = _11;
		_12 = _21;
		_13 = _31;
		_21 = _12;
		_22 = _22;
		_23 = _32;
		_31 = _13;
		_32 = _23;
		_33 = _33;
	}

	inline Matrix3x3 Matrix3x3::Transposed(Matrix3x3 _Mat)
	{		
		auto Mat = _Mat;
		Mat._11 = Mat._11;
		Mat._12 = Mat._21;
		Mat._13 = Mat._31;
		Mat._21 = Mat._12;
		Mat._22 = Mat._22;
		Mat._23 = Mat._32;
		Mat._31 = Mat._13;
		Mat._32 = Mat._23;
		Mat._33 = Mat._33;

		return Mat;
	}

	inline Matrix3x3 Matrix3x3::ZeroMatrix()
	{
		return Matrix3x3(0, 0, 0, 0, 0, 0, 0, 0, 0);
	}

	inline Matrix3x3 Matrix3x3::operator+(Matrix3x3 mat1)
	{
		Matrix3x3 Mat = ZeroMatrix();

		Mat._11 = _11 + mat1._11;
		Mat._12 = _12 + mat1._12;
		Mat._13 = _13 + mat1._13;
		Mat._21 = _21 + mat1._21;
		Mat._22 = _22 + mat1._22;
		Mat._23 = _23 + mat1._23;
		Mat._31 = _31 + mat1._31;
		Mat._32 = _32 + mat1._32;
		Mat._33 = _33 + mat1._33;

		return Mat;
	}

	inline Matrix3x3 Matrix3x3::operator=(Matrix3x3 mat1)
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

		return Matrix3x3(_11, _12, _13, _21, _22, _23, _31, _32, _33);
	}

	inline Matrix3x3 Matrix3x3::operator*(Matrix3x3 mat1)
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

	inline Matrix3x3 Matrix3x3::operator-(Matrix3x3 mat1)
	{

		Matrix3x3 Mat = ZeroMatrix();

		Mat._11 = _11 - mat1._11;
		Mat._12 = _12 - mat1._12;
		Mat._13 = _13 - mat1._13;
		Mat._21 = _21 - mat1._21;
		Mat._22 = _22 - mat1._22;
		Mat._23 = _23 - mat1._23;
		Mat._31 = _31 - mat1._31;
		Mat._32 = _32 - mat1._32;
		Mat._33 = _33 - mat1._33;

		return Mat;
	}

	inline Matrix3x3 Matrix3x3::operator*(float s)
	{
		Matrix3x3 Mat = ZeroMatrix();

		Mat._11 = _11 * s;
		Mat._12 = _12 * s;
		Mat._13 = _13 * s;
		Mat._21 = _21 * s;
		Mat._22 = _22 * s;
		Mat._23 = _23 * s;
		Mat._31 = _31 * s;
		Mat._32 = _32 * s;
		Mat._33 = _33 * s;

		return Mat;

	}

	inline Vector3 Matrix3x3::operator*(Vector3 v)
	{
		Vector3 Result = Vector3::zeroVector();
		Result.x = v.x * _11 + v.y * _12 + v.z * _13;
		Result.y = v.x * _21 + v.y * _22 + v.z * _23;
		Result.z = v.x * _31 + v.y * _32 + v.z * _33;

		return Result;
	}
	

}
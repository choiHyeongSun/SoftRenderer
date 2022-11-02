#pragma once
#include "Vector4.h"
#include <iostream>

namespace Matrix
{
	using namespace Vector;

	class Matrix4x4
	{
	private:
		Matrix4x4(float _11, float _12, float _13 , float _14, float _21, float _22, float _23 , float _24, float _31, float _32, float _33 , float _34 , float _41, float _42, float _43, float _44)
		{
			this->_11 = _11; this->_21 = _21; this->_31 = _31; this->_41 = _41;
			this->_12 = _12; this->_22 = _22; this->_32 = _32; this->_42 = _42;
			this->_13 = _13; this->_23 = _23; this->_33 = _33; this->_43 = _43;
			this->_14 = _14; this->_24 = _24; this->_34 = _34; this->_44 = _44;			
		}


		float _11;	float _12;	float _13; float _14;
		float _21;	float _22;	float _23; float _24;
		float _31;	float _32;	float _33; float _34;
		float _41;	float _42;	float _43; float _44;


	public:

		Matrix4x4(Vector4 v1, Vector4 v2, Vector4 v3, Vector4 v4)
		{
			_11 = v1.x; _21 = v2.x; _31 = v3.x; _41 = v4.x;
			_12 = v1.y; _22 = v2.y; _32 = v3.y; _42 = v4.y;
			_13 = v1.z; _23 = v2.z; _33 = v3.z; _43 = v4.z;
			_14 = v1.w; _24 = v2.w; _34 = v3.w; _44 = v4.w;
		}


	public:
		inline void TransPosed();

	public :
		static Matrix4x4 IdentityMatrix()
		{
			return (Matrix4x4(1, 0, 0 ,0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0));
		}
		static Matrix4x4 Transposed(Matrix4x4 _Mat);
		static Matrix4x4 ZeroMatrix();


	public:
		inline Matrix4x4 operator+ (Matrix4x4 mat1);
		inline Matrix4x4 operator- (Matrix4x4 mat1);
		inline Matrix4x4 operator= (Matrix4x4 mat1);
		inline Matrix4x4 operator* (Matrix4x4 mat1);
		inline Matrix4x4 operator* (float s);
		inline Vector4 operator* (Vector4 v);


	};


	inline void Matrix4x4::TransPosed()
	{
		_11 = _11;  _21 = _12; _31 = _13; _41 = _14;
		_12 = _21;  _22 = _22; _32 = _23; _42 = _24;
		_13 = _31;  _23 = _32; _33 = _33; _43 = _34;
		_14 = _41;  _24 = _42; _34 = _43; _44 = _44;		
	}

	

	inline Matrix4x4 Matrix4x4::Transposed(Matrix4x4 _Mat)
	{
		auto Mat = _Mat;
		Mat._11 = Mat._11;  Mat._21 = Mat._12; Mat._31 = Mat._13; Mat._41 = Mat._14;
		Mat._12 = Mat._21;  Mat._22 = Mat._22; Mat._32 = Mat._23; Mat._42 = Mat._24;
		Mat._13 = Mat._31;  Mat._23 = Mat._32; Mat._33 = Mat._33; Mat._43 = Mat._34;
		Mat._14 = Mat._41;  Mat._24 = Mat._42; Mat._34 = Mat._43; Mat._44 = Mat._44;

		return Mat;
	}

	inline Matrix4x4 Matrix4x4::ZeroMatrix()
	{
		return Matrix4x4(0,0,0,0
						,0,0,0,0
						,0,0,0,0
						,0,0,0,0);
	}



	inline Matrix4x4 Matrix4x4::operator+(Matrix4x4 mat1)
	{
		Matrix4x4 Mat = ZeroMatrix();

		Mat._11 = _11 + mat1._11;
		Mat._12 = _12 + mat1._12;
		Mat._13 = _13 + mat1._13;
		Mat._14 = _14 + mat1._14;

		Mat._21 = _21 + mat1._21;
		Mat._22 = _22 + mat1._22;
		Mat._23 = _23 + mat1._23;
		Mat._24 = _24 + mat1._24;

		Mat._31 = _31 + mat1._31;
		Mat._32 = _32 + mat1._32;
		Mat._33 = _33 + mat1._33;
		Mat._34 = _34 + mat1._34;

		Mat._41 = _41 + mat1._41;
		Mat._42 = _42 + mat1._42;
		Mat._43 = _43 + mat1._43;
		Mat._44 = _44 + mat1._44;

		return Mat;
	}

	inline Matrix4x4 Matrix4x4::operator=(Matrix4x4 mat1)
	{
		_11 = mat1._11;
		_12 = mat1._12;
		_13 = mat1._13;
		_14 = mat1._14;
		_21 = mat1._21;
		_22 = mat1._22;
		_23 = mat1._23;
		_24 = mat1._24;
		_31 = mat1._31;
		_32 = mat1._32;
		_33 = mat1._33;
		_34 = mat1._34;
		_41 = mat1._41;
		_42 = mat1._42;
		_43 = mat1._43;
		_44 = mat1._44;

		return Matrix4x4(_11, _12, _13, _14,
						 _21, _22, _23, _24,
						 _31, _32, _33, _34,
						 _41, _42, _43, _44);
	}

	inline Matrix4x4 Matrix4x4::operator*(Matrix4x4 mat1)
	{
		float e1 = _11 * mat1._11 + _12 * mat1._21 + _13 * mat1._31 + _14 * mat1._41;
		float e2 = _11 * mat1._12 + _12 * mat1._22 + _13 * mat1._32 + _14 * mat1._42;
		float e3 = _11 * mat1._13 + _12 * mat1._23 + _13 * mat1._33 + _14 * mat1._43;
		float e4 = _11 * mat1._14 + _12 * mat1._24 + _13 * mat1._34 + _14 * mat1._44;

		float e5 = _21 * mat1._11 + _22 * mat1._21 + _23 * mat1._31 + _24 * mat1._41;
		float e6 = _21 * mat1._12 + _22 * mat1._22 + _23 * mat1._32 + _24 * mat1._42;
		float e7 = _21 * mat1._13 + _22 * mat1._23 + _23 * mat1._33 + _24 * mat1._43;
		float e8 = _21 * mat1._14 + _22 * mat1._24 + _23 * mat1._34 + _24 * mat1._44;



		float e9  = _31 * mat1._11 + _32 * mat1._21 + _33 * mat1._31 + _34 * mat1._41;
		float e10 = _31 * mat1._12 + _32 * mat1._22 + _33 * mat1._32 + _34 * mat1._42;
		float e11 = _31 * mat1._13 + _32 * mat1._23 + _33 * mat1._33 + _34 * mat1._43;
		float e12 = _31 * mat1._14 + _32 * mat1._24 + _33 * mat1._34 + _34 * mat1._44;

		float e13 = _41 * mat1._11 + _42 * mat1._21 + _43 * mat1._31 + _44 * mat1._41;
		float e14 = _41 * mat1._12 + _42 * mat1._22 + _43 * mat1._32 + _44 * mat1._42;
		float e15 = _41 * mat1._13 + _42 * mat1._23 + _43 * mat1._33 + _44 * mat1._43;
		float e16 = _41 * mat1._14 + _42 * mat1._24 + _43 * mat1._34 + _44 * mat1._44;


		return Matrix4x4(e1, e2, e3, e4
						,e5, e6, e7, e8
						,e9 ,e10,e11,e12
						,e13,e14,e15,e16);
	}

	inline Matrix4x4 Matrix4x4::operator-(Matrix4x4 mat1)
	{

		Matrix4x4 Mat = ZeroMatrix();

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

	inline Matrix4x4 Matrix4x4::operator*(float s)
	{
		Matrix4x4 Mat = ZeroMatrix();

		Mat._11 = _11 * s; Mat._21 = _21 * s; Mat._31 = _31 * s; Mat._41 = _41 * s;
		Mat._12 = _12 * s; Mat._22 = _22 * s; Mat._32 = _32 * s; Mat._42 = _42 * s;
		Mat._13 = _13 * s; Mat._23 = _23 * s; Mat._33 = _33 * s; Mat._43 = _43 * s;
		Mat._14 = _14 * s; Mat._24 = _24 * s; Mat._34 = _34 * s; Mat._44 = _44 * s;

		return Mat;

	}

	inline Vector4 Matrix4x4::operator*(Vector4 v)
	{
		Vector4 Result = Vector4::zeroVector();
		Result.x = v.x * _11 + v.y * _12 + v.z * _13 + v.w * _14;
		Result.y = v.x * _21 + v.y * _22 + v.z * _23 + v.w * _24;
		Result.z = v.x * _31 + v.y * _32 + v.z * _33 + v.w * _34;
		Result.w = v.x * _41 + v.y * _42 + v.z * _43 + v.w * _44;
		return Result;
	}

}
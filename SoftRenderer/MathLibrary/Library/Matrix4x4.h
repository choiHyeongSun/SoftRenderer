#pragma once
#include "Vector4.h"

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
		inline const void TransPosed();

	public :
		static const Matrix4x4 IdentityMatrix()
		{
			return (Matrix4x4(1, 0, 0 ,0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0));
		}
		static const Matrix4x4 Transposed(const Matrix4x4 & _Mat);
		static const Matrix4x4 ZeroMatrix();


	public:
		inline  Matrix4x4 operator+ (const Matrix4x4 & mat1) const;
		inline  Matrix4x4 operator- (const Matrix4x4 & mat1) const;
		inline  Matrix4x4 operator* (const Matrix4x4 & mat1) const;
		inline  Matrix4x4 operator* (const float & s) const;
		inline  Vector4 operator* (const Vector4 & v) const;
		inline void operator= (const Matrix4x4 & mat1);


	};


	inline void const Matrix4x4::TransPosed()
	{

		const Matrix4x4 Mat = *this;
		_11 = Mat._11;  _12 = Mat._21; _13 = Mat._31; _14 = Mat._41;
		_21 = Mat._12;  _22 = Mat._22; _23 = Mat._32; _24 = Mat._42;
		_31 = Mat._13;  _32 = Mat._23; _33 = Mat._33; _34 = Mat._43;
		_41 = Mat._14;  _42 = Mat._24; _43 = Mat._34; _44 = Mat._44;
	}

	

	inline const  Matrix4x4 Matrix4x4::Transposed(const Matrix4x4 & _Mat)
	{


		const float _T11 = _Mat._11; const float _T12 = _Mat._21; const float _T13 = _Mat._31; const float _T14 = _Mat._41;
		const float _T21 = _Mat._12; const float _T22 = _Mat._22; const float _T23 = _Mat._32; const float _T24 = _Mat._42;
		const float _T31 = _Mat._13; const float _T32 = _Mat._23; const float _T33 = _Mat._33; const float _T34 = _Mat._43;
		const float _T41 = _Mat._14; const float _T42 = _Mat._24; const float _T43 = _Mat._34; const float _T44 = _Mat._44;

		return Matrix4x4(
			_T11, _T12, _T13, _T14,
			_T21, _T22, _T23, _T24,
			_T31, _T32, _T33, _T34, 
			_T41, _T42, _T43, _T44);
	}

	inline const Matrix4x4 Matrix4x4::ZeroMatrix()
	{
		return Matrix4x4(0,0,0,0
						,0,0,0,0
						,0,0,0,0
						,0,0,0,0);
	}



	inline Matrix4x4 Matrix4x4::operator+(const Matrix4x4 & mat1) const
	{
		Matrix4x4 Mat = ZeroMatrix();

		const float _T11 = _11 + mat1._11;
		const float _T12 = _12 + mat1._12;
		const float _T13 = _13 + mat1._13;
		const float _T14 = _14 + mat1._14;

		const float _T21 = _21 + mat1._21;
		const float _T22 = _22 + mat1._22;
		const float _T23 = _23 + mat1._23;
		const float _T24 = _24 + mat1._24;

		const float _T31 = _31 + mat1._31;
		const float _T32 = _32 + mat1._32;
		const float _T33 = _33 + mat1._33;
		const float _T34 = _34 + mat1._34;

		const float _T41 = _41 + mat1._41;
		const float _T42 = _42 + mat1._42;
		const float _T43 = _43 + mat1._43;
		const float _T44 = _44 + mat1._44;

		return Matrix4x4(
			_T11, _T12, _T13, _T14,
			_T21, _T22, _T23, _T24,
			_T31, _T32, _T33, _T34,
			_T41, _T42, _T43, _T44);
	}

	inline void Matrix4x4::operator=(const Matrix4x4 & mat1)
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

	}

	inline Matrix4x4 Matrix4x4::operator*(const Matrix4x4 & mat1) const
	{
		const float e1 = _11 * mat1._11 + _12 * mat1._21 + _13 * mat1._31 + _14 * mat1._41;
		const float e2 = _11 * mat1._12 + _12 * mat1._22 + _13 * mat1._32 + _14 * mat1._42;
		const float e3 = _11 * mat1._13 + _12 * mat1._23 + _13 * mat1._33 + _14 * mat1._43;
		const float e4 = _11 * mat1._14 + _12 * mat1._24 + _13 * mat1._34 + _14 * mat1._44;

		const float e5 = _21 * mat1._11 + _22 * mat1._21 + _23 * mat1._31 + _24 * mat1._41;
		const float e6 = _21 * mat1._12 + _22 * mat1._22 + _23 * mat1._32 + _24 * mat1._42;
		const float e7 = _21 * mat1._13 + _22 * mat1._23 + _23 * mat1._33 + _24 * mat1._43;
		const float e8 = _21 * mat1._14 + _22 * mat1._24 + _23 * mat1._34 + _24 * mat1._44;

		const float e9  = _31 * mat1._11 + _32 * mat1._21 + _33 * mat1._31 + _34 * mat1._41;
		const float e10 = _31 * mat1._12 + _32 * mat1._22 + _33 * mat1._32 + _34 * mat1._42;
		const float e11 = _31 * mat1._13 + _32 * mat1._23 + _33 * mat1._33 + _34 * mat1._43;
		const float e12 = _31 * mat1._14 + _32 * mat1._24 + _33 * mat1._34 + _34 * mat1._44;

		const float e13 = _41 * mat1._11 + _42 * mat1._21 + _43 * mat1._31 + _44 * mat1._41;
		const float e14 = _41 * mat1._12 + _42 * mat1._22 + _43 * mat1._32 + _44 * mat1._42;
		const float e15 = _41 * mat1._13 + _42 * mat1._23 + _43 * mat1._33 + _44 * mat1._43;
		const float e16 = _41 * mat1._14 + _42 * mat1._24 + _43 * mat1._34 + _44 * mat1._44;


		return Matrix4x4(e1, e2, e3, e4
						,e5, e6, e7, e8
						,e9 ,e10,e11,e12
						,e13,e14,e15,e16);
	}

	inline Matrix4x4 Matrix4x4::operator-(const Matrix4x4 & mat1) const
	{
		const float _T11 = _11 - mat1._11;
		const float _T12 = _12 - mat1._12;
		const float _T13 = _13 - mat1._13;
		const float _T14 = _14 - mat1._14;

		const float _T21 = _21 - mat1._21;
		const float _T22 = _22 - mat1._22;
		const float _T23 = _23 - mat1._23;
		const float _T24 = _24 - mat1._24;

		const float _T31 = _31 - mat1._31;
		const float _T32 = _32 - mat1._32;
		const float _T33 = _33 - mat1._33;
		const float _T34 = _34 - mat1._34;

		const float _T41 = _41 - mat1._41;
		const float _T42 = _42 - mat1._42;
		const float _T43 = _43 - mat1._43;
		const float _T44 = _44 - mat1._44;

		return Matrix4x4(
			_T11, _T12, _T13, _T14,
			_T21, _T22, _T23, _T24,
			_T31, _T32, _T33, _T34,
			_T41, _T42, _T43, _T44);
	}

	inline Matrix4x4 Matrix4x4::operator*(const float & s) const
	{	

		const float _T11 = _11 * s; const float _T21 = _21 * s; const float _T31 = _31 * s; const float _T41 = _41 * s;
		const float _T12 = _12 * s; const float _T22 = _22 * s; const float _T32 = _32 * s; const float _T42 = _42 * s;
		const float _T13 = _13 * s; const float _T23 = _23 * s; const float _T33 = _33 * s; const float _T43 = _43 * s;
		const float _T14 = _14 * s; const float _T24 = _24 * s; const float _T34 = _34 * s; const float _T44 = _44 * s;

		return Matrix4x4(
			_T11, _T12, _T13, _T14,
			_T21, _T22, _T23, _T24,
			_T31, _T32, _T33, _T34,
			_T41, _T42, _T43, _T44 );

	}

	inline Vector4 Matrix4x4::operator*(const Vector4 & v) const
	{		
		const float ResultX = v.x * _11 + v.y * _12 + v.z * _13 + v.w * _14;
		const float ResultY = v.x * _21 + v.y * _22 + v.z * _23 + v.w * _24;
		const float ResultZ = v.x * _31 + v.y * _32 + v.z * _33 + v.w * _34;
		const float ResultW = v.x * _41 + v.y * _42 + v.z * _43 + v.w * _44;

		return Vector4(ResultX, ResultY, ResultZ, ResultW);
	}

}
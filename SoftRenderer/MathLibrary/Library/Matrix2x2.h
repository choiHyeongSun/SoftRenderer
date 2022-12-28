#pragma once
#include "Vector2.h"


namespace Matrix
{
	using namespace Vector;
	class Matrix2x2
	{
	private:
		Matrix2x2(float _11, float _12, float _21, float _22)
		{
			this->_11 = _11;
			this->_12 = _12;
			this->_21 = _21;
			this->_22 = _22;
		}

		float _11;	float _12;
		float _21;	float _22;		

	protected:

		Matrix2x2(Vector::Vector2 v1, Vector::Vector2 v2)
		{
			this->_11 = v1.x;
			this->_12 = v1.y;
			this->_21 = v2.x;
			this->_22 = v2.y;
		}

	public:

		inline void TransPosed();

	public:

		static Matrix2x2 IdentityMatrix();	
		static Matrix2x2 Transposed(Matrix2x2 _Mat);
		static Matrix2x2 ZeroMatrix();

	public:

		inline Matrix2x2 operator+ (Matrix2x2 mat1);
		inline Matrix2x2 operator- (Matrix2x2 mat1);
		inline Matrix2x2 operator= (Matrix2x2 mat1);
		inline Matrix2x2 operator* (Matrix2x2 mat1);
		inline Matrix2x2 operator* (float s);
		inline Vector2 operator* (Vector2 v);



	};

	inline Matrix2x2 Matrix2x2::ZeroMatrix()
	{
		return Matrix2x2(0, 0, 0, 0);
	}

	inline Matrix2x2 Matrix2x2::operator+(Matrix2x2 mat1)
	{
		Matrix2x2 Mat = ZeroMatrix();

		Mat._11 = _11 + mat1._11;
		Mat._12 = _12 + mat1._12;
		Mat._21 = _21 + mat1._21;
		Mat._22 = _22 + mat1._22;

		return Mat;
	}

	inline Matrix2x2 Matrix2x2::operator-(Matrix2x2 mat1)
	{
		Matrix2x2 Mat = ZeroMatrix();

		Mat._11 = _11 - mat1._11;
		Mat._12 = _12 - mat1._12;
		Mat._21 = _21 - mat1._21;
		Mat._22 = _22 - mat1._22;

		return Mat;
	}

	inline Matrix2x2 Matrix2x2::operator=(Matrix2x2 mat1)
	{
		_11 = mat1._11;
		_12 = mat1._12;		
		_21 = mat1._21;
		_22 = mat1._22;		

		return Matrix2x2(_11, _12, _21, _22);
	}

	inline Matrix2x2 Matrix2x2::operator*(Matrix2x2 mat1)
	{
		float e1 = _11 * mat1._11 + _12 * mat1._21;
		float e2 = _11 * mat1._12 + _12 * mat1._22;	

		float e4 = _21 * mat1._11 + _22 * mat1._21;
		float e5 = _21 * mat1._12 + _22 * mat1._22;				

		return Matrix2x2(e1, e2,  e4, e5);
	}

	inline Matrix2x2 Matrix2x2::operator*(float s)
	{
		Matrix2x2 Mat = ZeroMatrix();

		Mat._11 = _11 * s;
		Mat._12 = _12 * s;		
		Mat._21 = _21 * s;
		Mat._22 = _22 * s;		
		return Mat; 
	}

	inline Vector2 Matrix2x2::operator*(Vector2 v)
	{
		Vector2 Result = Vector2::ZeroVector();
		Result.x = v.x * _11 + v.y * _12;
		Result.y = v.x * _21 + v.y * _22;
		

		return Result;
	}





	inline void Matrix2x2::TransPosed()
	{
		Matrix2x2 Mat = *this;

		_21 = Mat._12;
		_12 = Mat._21;
	}

	inline Matrix2x2 Matrix2x2::IdentityMatrix()
	{
		return (Matrix2x2(1, 0, 0, 1));
	}

	inline Matrix2x2 Matrix2x2::Transposed(Matrix2x2 _Mat)
	{
		Matrix2x2 Mat = ZeroMatrix();
		Mat._12 = _Mat._22;
		Mat._22 = _Mat._12;
		return Mat;
	}
}
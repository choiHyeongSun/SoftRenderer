#pragma once
#include "Vector2.h"

namespace Matrix
{	
	class Matrix2x2
	{		
	private:

	private:
		Matrix2x2() = delete;
		Matrix2x2(float _11, float _12, float _21, float _22)
		{
			
			this->_11 = _11;
			this->_12 = _12;
			this->_21 = _21;
			this->_22 = _22;
		}

		float _11;	float _12;
		float _21;	float _22;		

	public:

		
		Matrix2x2(Vector::Vector2 v1, Vector::Vector2 v2)
		{
			this->_11 = v1.x;
			this->_12 = v1.y;
			this->_21 = v2.x;
			this->_22 = v2.y;
		}

	public:

		inline Matrix2x2 Transposed();

	public:

		inline static const Matrix2x2 IdentityMatrix();	
		inline static const Matrix2x2 Transposed(const Matrix2x2 & _Mat);
		inline static const Matrix2x2 GetZeroMatrix();
		
	public:

		inline Matrix2x2 operator+ (const Matrix2x2 & mat1) const;
		inline Matrix2x2 operator- (const Matrix2x2 & mat1) const;		
		inline Matrix2x2 operator* (const Matrix2x2 & mat1) const;
		inline Matrix2x2 operator* (const float & s) const;
		inline Vector::Vector2 operator* (const Vector::Vector2 & v) const;
		inline void operator= (Matrix2x2 mat1);



	};

	inline const Matrix2x2 Matrix2x2::IdentityMatrix() 
	{
		return Matrix2x2(1, 0, 0, 1);
	}


	inline const Matrix2x2 Matrix2x2::GetZeroMatrix()
	{		
		return Matrix2x2(0.0f, 0.0f, 0.0f, 0.0f);
	}

	inline Matrix2x2 Matrix2x2::operator+(const Matrix2x2 & mat1) const
	{

		const float _T11 = _11 + mat1._11;
		const float _T12 = _12 + mat1._12;
		const float _T21 = _21 + mat1._21;
		const float _T22 = _22 + mat1._22;

		return Matrix2x2(_T11, _T12, _T21, _T22);
	}

	inline Matrix2x2 Matrix2x2::operator-(const Matrix2x2 & mat1) const
	{

		const float _T11 = _11 - mat1._11;
		const float _T12 = _12 - mat1._12;
		const float _T21 = _21 - mat1._21;
		const float _T22 = _22 - mat1._22;

		return Matrix2x2(_T11, _T12, _T21, _T22);
	}

	inline void Matrix2x2::operator=(const Matrix2x2 mat1)
	{
		_11 = mat1._11;
		_12 = mat1._12;		
		_21 = mat1._21;
		_22 = mat1._22;				
	}

	inline Matrix2x2 Matrix2x2::operator*(const Matrix2x2 & mat1) const
	{
		const float e1 = _11 * mat1._11 + _12 * mat1._21;
		const float e2 = _11 * mat1._12 + _12 * mat1._22;	
		const float e4 = _21 * mat1._11 + _22 * mat1._21;
		const float e5 = _21 * mat1._12 + _22 * mat1._22;				

		return Matrix2x2(e1, e2,  e4, e5);
	}

	inline Matrix2x2 Matrix2x2::operator*(const float& s) const
	{
		const float _T11 = _11 * s;
		const float _T12 = _12 * s;		
		const float _T21 = _21 * s;
		const float _T22 = _22 * s;		

		return Matrix2x2(_T11, _T12, _T21, _T22);
	}


	inline Vector::Vector2 Matrix2x2::operator*(const Vector::Vector2& v) const
	{		
		const float ResultX = v.x * _11 + v.y * _12;
		const float ResultY = v.x * _21 + v.y * _22;

		return Vector::Vector2(ResultX, ResultY);
	}

	inline Matrix2x2 Matrix2x2::Transposed() 
	{
		const Matrix2x2 Mat = *this;

		_21 = Mat._12;
		_12 = Mat._21;
			
		return *this;
	}


	inline const Matrix2x2 Matrix2x2::Transposed(const Matrix2x2 & _Mat)
	{			
		return Matrix2x2(_Mat._11 , _Mat._21 , _Mat._12 , _Mat._22);
	}	
}


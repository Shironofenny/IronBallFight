#ifndef __QUATERNION_H__
#define __QUATERNION_H__

#include "Vector.h"

class Quaternion
{
	public:
		
		// Default constructor
		Quaternion();

		// Construct from existing quaternion
		Quaternion( const Quaternion & q );

		// Construct with specified real (s) and imaginary (v) components
		Quaternion( float s, float vi, float vj, float vk );

		// Construct with specified real (s) and imaginary (v) components
		Quaternion( float s, const Vector& v );

		// Get reference to the specified component (0-based indexing: r, i, j, k)
		float & operator[]( int index );

		// Addition
		Quaternion operator+( const Quaternion& q ) const;

		// Subtraction
		Quaternion operator-( const Quaternion& q ) const;

		// Negation
		Quaternion operator-( void ) const;

		// Right scalar multiplication
		Quaternion operator*( float c ) const;

		// Scalar division
		Quaternion operator/( float c ) const;

		// Hamilton product
		Quaternion operator*( const Quaternion& q ) const;

	protected:
		// scalar (float) part
		float m_Scalar;

		// vector (imaginary) part
		Vector m_Vector;
};

#endif




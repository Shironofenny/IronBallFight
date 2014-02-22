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
		Quaternion( double s, double vi, double vj, double vk );

		// Construct with specified real (s) and imaginary (v) components
		Quaternion( double s, const Vector& v );

		// Get reference to the specified component (0-based indexing: r, i, j, k)
		double & operator[]( int index );

		// Addition
		Quaternion operator+( const Quaternion& q ) const;

		// Subtraction
		Quaternion operator-( const Quaternion& q ) const;

		// Negation
		Quaternion operator-( void ) const;

		// Right scalar multiplication
		Quaternion operator*( double c ) const;

		// Scalar division
		Quaternion operator/( double c ) const;

		// Hamilton product
		Quaternion operator*( const Quaternion& q ) const;

	protected:
		// scalar (double) part
		double m_Scalar;

		// vector (imaginary) part
		Vector m_Vector;
};

#endif




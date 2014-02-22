#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "../../GLHeader.h"

class Vector
{
	public:

		// Default constructor
		Vector();

		// Constructor with initial values
		Vector(double, double, double);

		// Destructor
		~Vector();

		// Get value using indicies
		double & operator[] (int _index);
		double const & operator[] (int _index) const;

		// Addition
		Vector operator + (Vector const & _v) const;

		// Addition and assign
		Vector & operator += (Vector const & _v);
		
		// Negate
		Vector operator - () const;

		// Substract
		Vector operator - (Vector const & _v) const;

		// Substract and assign
		Vector & operator -= (Vector const & _v);

		// Scalar multiplication
		Vector operator * (double const _c) const;

	private:

		// Value of x, y, z
		double m_Position[3]; 
};

// Dot product of two vectors
double dot(Vector const & _v1, Vector const & _v2);

// Cross product of two vectors
Vector cross(Vector const & _v1, Vector const & _v2);

// Override gltranslate function:
void glTranslatev(Vector const & v);

#endif

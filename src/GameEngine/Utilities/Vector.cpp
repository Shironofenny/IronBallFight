#include "Vector.h"

Vector::Vector()
{
	m_Position[0] = 0.0;
	m_Position[1] = 0.0;
	m_Position[2] = 0.0;
}

Vector::Vector(double x, double y, double z)
{
	m_Position[0] = x;
	m_Position[1] = y;
	m_Position[2] = z;
}

Vector::~Vector()
{

}

double & Vector::operator[](int _index)
{
	return m_Position[_index];
}

double const & Vector::operator[](int _index) const
{
	return m_Position[_index];
}

Vector Vector::operator + (Vector const & _v) const
{
	return Vector(m_Position[0]+_v.m_Position[0],\
		 	m_Position[1]+_v.m_Position[1], m_Position[2]+_v.m_Position[2]);
}

Vector Vector::operator - () const
{
	return Vector(-m_Position[0], -m_Position[1], -m_Position[2]);
}

Vector Vector::operator - (Vector const & _v) const
{
	return Vector(m_Position[0]-_v.m_Position[0],\
		 	m_Position[1]-_v.m_Position[1], m_Position[2]-_v.m_Position[2]);
}

Vector & Vector::operator += (Vector const & _v)
{
	m_Position[0] += _v.m_Position[0];
	m_Position[1] += _v.m_Position[1];
	m_Position[2] += _v.m_Position[2];
	return * this;
}

Vector & Vector::operator -= (Vector const & _v)
{ 
	m_Position[0] -= _v.m_Position[0];
	m_Position[1] -= _v.m_Position[1];
	m_Position[2] -= _v.m_Position[2];
	return * this;
}

Vector Vector::operator * (double const _c) const
{
	return Vector(m_Position[0] * _c, m_Position[1] * _c, m_Position[2] * _c);
}

double dot(Vector const & _v1, Vector const & _v2)
{
	return (_v1[0] * _v2[0] + _v1[1] * _v2[1] + _v1[2] * _v2[2]);
}

Vector cross(Vector const & _v1, Vector const & _v2)
{
	return Vector(_v1[1] * _v2[2] - _v1[2] * _v2[1],\
								_v1[2] * _v2[0] - _v1[0] * _v2[2],\
								_v1[0] * _v2[1] - _v1[1] * _v2[0]);
}

void glTranslatev(Vector const & v)
{
	glTranslatef(v[0], v[1], v[2]);
}

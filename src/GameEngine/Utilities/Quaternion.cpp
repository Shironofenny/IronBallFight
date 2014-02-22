#include "Quaternion.h"

Quaternion::Quaternion()
:m_Scalar( 0. ),
 m_Vector( 0., 0., 0. )
{

}
   
Quaternion::Quaternion( const Quaternion& q )
:m_Scalar( q.m_Scalar ),
 m_Vector( q.m_Vector )
{

}

Quaternion::Quaternion( float _s, float _vi, float _vj, float _vk )
:m_Scalar( _s ),
 m_Vector( _vi, _vj, _vk )
{

}

Quaternion::Quaternion( float _s, const Vector & _v )
:m_Scalar( _s),
 m_Vector( _v )
{

}

float & Quaternion::operator[]( int index )
{
	return ( &m_Scalar )[ index ];
}

Quaternion Quaternion::operator+( Quaternion const & q ) const
{
	return Quaternion( m_Scalar+q.m_Scalar, m_Vector+q.m_Vector );
}

Quaternion Quaternion::operator-( const Quaternion& q ) const
{
	return Quaternion( m_Scalar-q.m_Scalar, m_Vector-q.m_Vector );
}

Quaternion Quaternion::operator-() const
{
	return Quaternion( -m_Scalar, -m_Vector );
}

Quaternion Quaternion::operator*( float c ) const
{
	return Quaternion( m_Scalar*c, m_Vector*c );
}

Quaternion Quaternion::operator*( const Quaternion& q ) const
{
	const float & m_Scalar1( m_Scalar );
	const float & m_Scalar2( q.m_Scalar );
	const Vector & m_Vector1( m_Vector );
	const Vector & m_Vector2( q.m_Vector );

	return Quaternion( m_Scalar1*m_Scalar2 - dot(m_Vector1,m_Vector2), m_Vector2*m_Scalar1 + m_Vector1*m_Scalar2 + cross(m_Vector1,m_Vector2) );
}

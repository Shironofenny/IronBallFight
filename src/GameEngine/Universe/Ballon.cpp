#include "Ballon.h"

Ballon::Ballon():
	Sprite()
{
	m_Radius = 1.0;
}

Ballon::Ballon(Vector const & _position):
	Sprite(_position)
{
	m_Radius = 1.0;
}

Ballon::Ballon(double _radius, Vector const & _position):
	Sprite(_position), 
	m_Radius(_radius)
{
	
}

Ballon::~Ballon()
{

}

void Ballon::update(double dt)
{

}

void Ballon::render()
{
	glPushMatrix();
		
		glTranslatev(m_Position);
		glutSolidSphere(1.0, 20, 20);

	glPopMatrix();
}

#include "Planet.h"

Planet::Planet():
	Sprite()
{
	m_Radius = 1.0;
}

Planet::Planet(Vector const & _position):
	Sprite(_position)
{
	m_Radius = 1.0;
}

Planet::Planet(double _radius, Vector const & _position):
	Sprite(_position), 
	m_Radius(_radius)
{
	
}

Planet::~Planet()
{

}

void Planet::update(double dt)
{

}

void Planet::render()
{
	glPushMatrix();
		
		glTranslatev(m_Position);
		glutSolidSphere(1.0, 20, 20);

	glPopMatrix();
}

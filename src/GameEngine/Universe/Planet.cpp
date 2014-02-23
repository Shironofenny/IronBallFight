#include "Planet.h"

Planet::Planet():
	Sprite()
{

}

Planet::Planet(Vector const & _position):
	Sprite(_position)
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
		glutSolidCube(1.0);

	glPopMatrix();
}

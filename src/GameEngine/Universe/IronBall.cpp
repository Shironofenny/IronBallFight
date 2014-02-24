#include "IronBall.h"

IronBall::IronBall():
	Sprite(ConstantHandler::getInstance().ironBallPosition)
{

}

IronBall::IronBall(Vector const & _position):
	Sprite(_position)
{

}

IronBall::~IronBall()
{

}

void IronBall::initialize()
{
	m_TextureNumber = OBJLoader::getInstance().loadOBJ("./obj/IronBall.obj");
}

void IronBall::update(double dt)
{

}

void IronBall::render()
{
	// This render does a transformation that reserved for later:
	glTranslatev(m_Position);

	glPushMatrix();
		glColor3f(0.5, 0.5, 0.5);
		glRotated(90, 0., -1., 0.);
		glCallList(m_TextureNumber);
	glPopMatrix();
}

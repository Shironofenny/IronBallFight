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
	m_Body = OBJLoader::getInstance().loadOBJ("./obj/IronBall.obj");
	m_Ears = OBJLoader::getInstance().loadOBJ("./obj/Ears.obj");
	m_Motor = OBJLoader::getInstance().loadOBJ("./obj/Motor.obj");
}

void IronBall::update(double dt)
{

}

void IronBall::setRotationCenter()
{
	// This method does a transformation that reserved for later:
	glTranslatev(m_Position);
}

void IronBall::render()
{
	glPushMatrix();
		glColor3f(0.5, 0.5, 0.5);
		glRotated(90, 0., -1., 0.);
		glCallList(m_Body);
		glCallList(m_Ears);
		glCallList(m_Motor);
	glPopMatrix();
}

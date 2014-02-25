#include "Scene3D.h"

Scene3D::Scene3D():
	Scene(), 
	m_IronBall(), 
	m_LightSource(ConstantHandler::getInstance().lightSource)
{
}

Scene3D::~Scene3D()
{
}

void Scene3D::createScene()
{
	m_IronBall.initialize();
	double radius = 10;
	for(int i = 0; i <= 11; i++)
	{
		Vector ballonPosition(radius * cos(M_PI / 6 * i + M_PI / 12), 0., radius * sin(M_PI / 6 * i + M_PI / 12));
		Ballon ballonTemp(ballonPosition);
		m_Ballons.push_back(ballonTemp);
	}
	for(int i = 0; i <= 11; i++)
	{
		Vector ballonPosition(0., radius * cos(M_PI / 6 * i + M_PI / 12), radius * sin(M_PI / 6 * i + M_PI / 12));
		Ballon ballonTemp(ballonPosition);
		m_Ballons.push_back(ballonTemp);
	}
	for(int i = 0; i <= 11; i++)
	{
		Vector ballonPosition(radius * cos(M_PI / 6 * i + M_PI / 12), radius * sin(M_PI / 6 * i + M_PI / 12), 0.);
		Ballon ballonTemp(ballonPosition);
		m_Ballons.push_back(ballonTemp);
	}
}

Camera & Scene3D::getCamera()
{
	return m_Camera;
}

vector <Ballon> & Scene3D::getBallons()
{
	return m_Ballons;
}

IronBall & Scene3D::getIronBall()
{
	return m_IronBall;
}

Vector & Scene3D::getLightPosition()
{
	return m_LightSource;
}

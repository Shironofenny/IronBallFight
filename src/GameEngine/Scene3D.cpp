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
	
	// The color of the ballons
	GLfloat colorFirst[] = {1., 0., 0., 1.}; 
	GLfloat colorSecond[] = {0, 1., 0., 1.}; 
	GLfloat colorThird[] = {0, 0., 1., 1.};

	for(int i = 0; i <= 11; i++)
	{
		Vector ballonPosition(radius * cos(M_PI / 6 * i + M_PI / 12), 0., radius * sin(M_PI / 6 * i + M_PI / 12));
		Ballon ballonTemp(ballonPosition);
		ballonTemp.setColor(colorFirst);
		m_Ballons.push_back(ballonTemp);
	}
	for(int i = 0; i <= 11; i++)
	{
		Vector ballonPosition(0., radius * cos(M_PI / 6 * i + M_PI / 12), radius * sin(M_PI / 6 * i + M_PI / 12));
		Ballon ballonTemp(ballonPosition);
		ballonTemp.setColor(colorSecond);
		m_Ballons.push_back(ballonTemp);
	}
	for(int i = 0; i <= 11; i++)
	{
		Vector ballonPosition(radius * cos(M_PI / 6 * i + M_PI / 12), radius * sin(M_PI / 6 * i + M_PI / 12), 0.);
		Ballon ballonTemp(ballonPosition);
		ballonTemp.setColor(colorThird);
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

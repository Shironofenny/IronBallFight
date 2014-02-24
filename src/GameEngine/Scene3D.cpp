#include "Scene3D.h"

Scene3D::Scene3D():
	Scene(), 
	m_IronBall()
{
}

Scene3D::~Scene3D()
{
}

void Scene3D::createScene()
{
	m_IronBall.initialize();
	double radius = 10;
	for(int i = 0; i <= 9; i++)
	{
		Vector planetPosition(radius * cos(M_PI / 5 * i), 0., radius * sin(M_PI / 5 * i));
		Planet planetTemp(planetPosition);
		m_Planets.push_back(planetTemp);
	}
	for(int i = 0; i <= 9; i++)
	{
		Vector planetPosition(0., radius * cos(M_PI / 5 * i), radius * sin(M_PI / 5 * i));
		Planet planetTemp(planetPosition);
		m_Planets.push_back(planetTemp);
	}
}

Camera & Scene3D::getCamera()
{
	return m_Camera;
}

vector <Planet> & Scene3D::getPlanets()
{
	return m_Planets;
}

IronBall & Scene3D::getIronBall()
{
	return m_IronBall;
}

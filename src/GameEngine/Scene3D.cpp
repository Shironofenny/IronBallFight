#include "Scene3D.h"

Scene3D::Scene3D():
	Scene()
{
}

Scene3D::~Scene3D()
{
}

void Scene3D::createScene()
{
	double radius = 10;
	for(int i = 0; i <= 9; i++)
	{
		Vector planetPosition(radius * cos(M_PI / 5 * i), 0., radius * sin(M_PI / 5 * i));
		Planet planetTemp(planetPosition);
		m_Planets.push_back(planetTemp);
	}
}

vector <Planet> & Scene3D::getPlanets()
{
	return m_Planets;
}

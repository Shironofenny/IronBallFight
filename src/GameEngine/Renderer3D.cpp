#include "Renderer3D.h"

#include <iostream>
using namespace std;

Renderer3D::Renderer3D(Scene3D & _scene) :
	Renderer(), 
	m_Scene(_scene)
{
	assert( _scene.getDimension() == 3 );
	assert( _scene.getDimension() == this->getDimension() );
}

Renderer3D::~Renderer3D()
{
}

void Renderer3D::Render()
{
	vector <Planet> & planets = m_Scene.getPlanets();

	for(vector <Planet>::size_type i = 0; i < planets.size(); i++)
	{
		planets[i].render();
	}
}

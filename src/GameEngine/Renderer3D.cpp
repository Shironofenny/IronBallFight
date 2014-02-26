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
	Camera & camera = m_Scene.getCamera();
	IronBall & ironBall = m_Scene.getIronBall();
	vector <Ballon> & ballons = m_Scene.getBallons();
	Planet & earth = m_Scene.getEarth();
	Planet & moon = m_Scene.getMoon();

	// In order to trace the iron ball, we need to set this as the rotation center
	ironBall.setRotationCenter();
	
	glPushMatrix();
		
		// Then set up camera
		camera.setup();

		earth.render();
		moon.render();

		for(vector <Ballon>::size_type i = 0; i < ballons.size(); i++)
		{
			Shader::getInstance().attributeVec3("lightSource",\
														-(m_Scene.getLightPosition() + camera.getCameraPosition()).projection(\
														camera.getCameraCoordinateX(), \
														camera.getCameraCoordinateY(), \
														camera.getCameraCoordinateZ()));

			ballons[i].render();
		}

	glPopMatrix();
	
	ironBall.render();
}

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
	vector <Planet> & planets = m_Scene.getPlanets();

	// In order to trace the iron ball, we need to set this as the rotation center
	ironBall.setRotationCenter();
	
	glPushMatrix();
		
		// Then set up camera
		camera.setup();
		
		// Draw all the planets
		GLfloat colorFirst[] = {0.5, 0.5, 0., 1.}; 
		GLfloat colorSecond[] = {0, 0.5, 0.5, 1.}; 

		for(vector <Planet>::size_type i = 0; i < planets.size(); i++)
		{
			//glMaterialfv(GL_FRONT, GL_DIFFUSE, selectedColor);
			if(i <= 9) 
			{
				glColor4fv(colorFirst);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, colorFirst);
			}
			else 
			{
				glColor4fv(colorSecond);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, colorSecond);
			}

			Shader::getInstance().attributeVec3("lightSource",\
														-(m_Scene.getLightPosition() + camera.getCameraPosition()).projection(\
														camera.getCameraCoordinateX(), \
														camera.getCameraCoordinateY(), \
														camera.getCameraCoordinateZ()));

			planets[i].render();
		}

	glPopMatrix();
	
	ironBall.render();
}

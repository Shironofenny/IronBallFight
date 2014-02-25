#include "Updater3D.h"

Updater3D::Updater3D(Scene3D & _scene) :
	Updater(), 
	m_Scene(_scene)
{
}

void Updater3D::Update(double dt)
{
	Camera & camera = m_Scene.getCamera();
	vector <Ballon> & ballons = m_Scene.getBallons();

	camera.update(dt);
	for (vector <Ballon>::size_type i = 0; i < ballons.size(); i++)
	{
		ballons[i].calculateRayCollision(camera.getCameraPosition() + camera.getCameraCoordinateY() * 0.7, -camera.getCameraCoordinateZ());
	}
}

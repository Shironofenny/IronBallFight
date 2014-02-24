#include "Updater3D.h"

Updater3D::Updater3D(Scene3D & _scene) :
	Updater(), 
	m_Scene(_scene)
{
}

void Updater3D::Update(double dt)
{
	Camera & camera = m_Scene.getCamera();
	camera.update(dt);
}

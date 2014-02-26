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
		ballons[i].update(dt);
		if(ballons[i].isDestroyed())
		{
			ballons.erase(ballons.begin()+i);
		}
	}

	if(Mouse::getInstance().isMouseLeftDown())
	{
		double distance;
		double collisionDistance = 0.0;
		int collisionNumber = -1;

		for (vector <Ballon>::size_type i = 0; i < ballons.size(); i++)
		{
			distance = ballons[i].calculateRayCollision(camera.getCameraPosition() + camera.getCameraCoordinateY() * 0.7, -camera.getCameraCoordinateZ());
			if(distance >= 0.0)
			{
				if(collisionNumber != -1)
				{
					// This means a previous collision is detected.
					// We need to determine which collision is nearer to the ray source
					if (distance < collisionDistance)
					{
						ballons[(vector <Ballon>::size_type)collisionNumber].getRayColliding() = false;
						collisionDistance = distance;
						collisionNumber = i;
					}
					else
					{ 
						ballons[i].getRayColliding() = false;
					}
				}
				else
				{
					collisionDistance = distance;
					collisionNumber = i;
				}
			}
		}
	}
}

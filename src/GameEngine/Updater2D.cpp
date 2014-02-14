#include "Updater2D.h"

Updater2D::Updater2D(Scene2D & _scene) :
	Updater(), 
	mScene(_scene)
{
}

void Updater2D::Update(double dt)
{
	this->physicsProcess(dt);
}

void Updater2D::physicsProcess(double dt)
{
	// Extract informations
	VectorXd & x = mScene.getPosition();
	VectorXd & v = mScene.getVelocity();
	VectorXd & m = mScene.getInertia();

	vector <bool> & isFixed = mScene.getFixed();

	VectorXd force(x.size());

	mScene.accumulateForce(force);

	VectorXd dv = (force*dt).array()/m.array();

	v += dv;

	for (vector <bool>::size_type i = 0; i<isFixed.size(); ++i)
	{
		if (isFixed[i])
		{
			v[i*2] = 0;
			v[i*2+1] = 0;
		}
	}

	x += v*dt;
}

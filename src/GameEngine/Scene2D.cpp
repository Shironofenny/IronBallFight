#include "Scene2D.h"

Scene2D::Scene2D():
	Scene(), 
	mGeneralPos(), 
	mGeneralVel(), 
	mGeneralIne()
{
	mDegreeOfFreedoms = 10;
}

Scene2D::~Scene2D()
{
	for (vector<Force *>::size_type i = 0; i<mForces.size(); ++i)
	{
		delete mForces[i];
	}
}

VectorXd & Scene2D::getPosition()
{
	return mGeneralPos;
}

VectorXd & Scene2D::getVelocity()
{
	return mGeneralVel;
}

VectorXd & Scene2D::getInertia()
{
	return mGeneralIne;
}

vector <bool> & Scene2D::getFixed()
{
	return mIsFixed;
}

vector <line> & Scene2D::getLine()
{
	return mLineList;
}

void Scene2D::createScene()
{
	mGeneralPos.resize(mDegreeOfFreedoms);
	mGeneralVel.resize(mDegreeOfFreedoms);
	mGeneralIne.resize(mDegreeOfFreedoms);

	mGeneralPos << 4, 6, 6, 6, 8, 6, 10, 6, 12, 6;
	mGeneralVel << 0, 0.1, 0, 0, 0, 0, 0, 0, 0, 0.1;
	mGeneralIne << 1, 1, 1, 1, 1, 1, 1, 1, 1, 1;

	mIsFixed.assign(5, false);
	mIsFixed[0] = true;
	mIsFixed[4] = true;

	mSpringList.push_back( make_tuple( make_pair(0, 1), gInitialLength, gKOfSpring));
	mSpringList.push_back( make_tuple( make_pair(1, 2), gInitialLength, gKOfSpring));
	mSpringList.push_back( make_tuple( make_pair(2, 3), gInitialLength, gKOfSpring));
	mSpringList.push_back( make_tuple( make_pair(3, 4), gInitialLength, gKOfSpring));

	Force * force = new SpringForce(mSpringList);
	mForces.push_back(force);
	Force * force2 = new Gravity(gGravityAcceleration);
	mForces.push_back(force2);
	Force * force3 = new AirFriction(gAirFrictionFactor);
	mForces.push_back(force3);

	mLineList.push_back(make_pair(0, 1));
	mLineList.push_back(make_pair(1, 2));
	mLineList.push_back(make_pair(2, 3));
	mLineList.push_back(make_pair(3, 4));
}

void Scene2D::accumulateForce(VectorXd & _force)
{
	// Reset the force
	_force.setZero();

	// Check if there is no force in the scene
	if (mForces.size() == 0) return;

	// Add forces
	for (vector<Force *>::size_type i = 0; i<mForces.size(); ++i)
	{
		mForces[i]->addToTotalForce(_force, mGeneralPos, mGeneralVel, mGeneralIne);
	}
}

#include "SpringForce.h"
#include <cmath>

SpringForce::SpringForce(vector<spring> & _config) :
	Force(), 
	mSpringList(_config)
{

}

SpringForce::~SpringForce()
{

}

void SpringForce::addToTotalForce(VectorXd & _force, VectorXd const & _generalPos,\
		 								 VectorXd const & _generalVel, VectorXd const & _generalIne) const 
{
	for (vector<spring>::size_type i = 0; i < mSpringList.size(); ++i)
	{
		// Get the two points that each spring ties with
		int firstNum = get<gSpringNodes>( mSpringList[i] ).first;
		int secondNum = get<gSpringNodes>( mSpringList[i] ).second;

		Vector2d x1 ( _generalPos[ firstNum* 2 ], _generalPos[ firstNum * 2 + 1 ]);
		Vector2d x2 ( _generalPos[ secondNum * 2 ], _generalPos[ secondNum * 2 + 1 ]);
		
		Vector2d nhat = x2 - x1;
		
		// Calculate the length and find the unit vector nhat = \hat{n} 
		double length = nhat.norm();
		assert(length != 0 && "Two points connected to the spring got coincide");
		nhat /= length;

		// Calculate the force and add to it
		nhat *= get<gSpringK>( mSpringList[i] ) * (length - get<gSpringLength>( mSpringList[i] ));
		_force[firstNum * 2] += nhat[0];
		_force[firstNum * 2 + 1] += nhat[1];
		_force[secondNum * 2 ] -= nhat[0];
		_force[secondNum * 2 +1] -= nhat[1];
	}
}

void SpringForce::addToTotalEnergy(VectorXd & _energy, VectorXd const & _generalPos, \
										  VectorXd const & _generalVel, VectorXd const & _generalIne) const
{
	
}

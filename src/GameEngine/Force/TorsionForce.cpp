#include "TorsionForce.h"

using namespace mathUtility;

TorsionForce::TorsionForce(vector <torque> & _config) :
	Force(), 
	mTorqueList(_config)
{}

TorsionForce::~TorsionForce()
{

}

void TorsionForce::addToTotalForce(VectorXd & _force, VectorXd const & _generalPos,\
		 													VectorXd const & _generalVel, VectorXd const & _generalIne) const
{
	for (vector<torque>::size_type i = 0; i<mTorqueList.size(); ++i)
	{
		int pPrev = get<gTorqueNodeBefore>(mTorqueList[i]);
		int pCurr = get<gTorqueNodeCenter>(mTorqueList[i]);
		int pAfte = get<gTorqueNodeAfter>(mTorqueList[i]);
		
		// Get all three point's position:
		Vector2d x1(_generalPos(pPrev * 2), _generalPos(pPrev *2 + 1));
		Vector2d x2(_generalPos(pCurr * 2), _generalPos(pCurr *2 + 1));
		Vector2d x3(_generalPos(pAfte * 2), _generalPos(pAfte *2 + 1));

		// Caluculate the angle between the two lines:
		Vector2d v1 = x2-x1;
		Vector2d v2 = x3-x2;
		//double a1 = gAtan(v1);
		//double a2 = gAtan(v2);
		//double diffAngle = a2-a1;
	}
}

void TorsionForce::addToTotalEnergy(VectorXd & _energy, VectorXd const & _generalPos, \
											  			VectorXd const & _generalVel, VectorXd const & _generalIne) const
{
	
}

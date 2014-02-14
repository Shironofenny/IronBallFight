#ifndef __TORSIONFORCE_H__
#define __TORSIONFORCE_H__

#include "Force.h"
#include "../../MathUtilities.h"

using namespace sceneUtility;
using namespace mathUtility;

class TorsionForce : public Force
{
	public:
		
		// Constructor
		TorsionForce(vector <torque> &);

		// Destructor
		~TorsionForce();

		// Override total force function
		void addToTotalForce(VectorXd & _force, VectorXd const & _generalPos,\
		 										VectorXd const & _generalVel, VectorXd const & _generalIne) const override;

		// Override total energy function
		void addToTotalEnergy(VectorXd & _energy, VectorXd const & _generalPos, \
											  VectorXd const & _generalVel, VectorXd const & _generalIne) const override;

	protected:

		// A private copy of all torques
		vector <torque> & mTorqueList;
};

#endif

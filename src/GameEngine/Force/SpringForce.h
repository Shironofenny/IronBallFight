#ifndef __SPRINGFORCE_H__
#define __SPRINGFORCE_H__

#include "Force.h"

using namespace sceneUtility;

class SpringForce : public Force
{
	public:

		// Constructor
		// <r> _config: Extra configuration that is required for the force
		// 							Spring force needs to know which two types are tighted
		// 							together with how big k is.
		SpringForce(vector<spring> & _config);

		// Destructor
		~SpringForce();

		// Override total force function
		void addToTotalForce(VectorXd & _force, VectorXd const & _generalPos,\
		 										VectorXd const & _generalVel, VectorXd const & _generalIne) const override;

		// Override total energy function
		void addToTotalEnergy(VectorXd & _energy, VectorXd const & _generalPos, \
											  VectorXd const & _generalVel, VectorXd const & _generalIne) const override;
		
	private:

		// A private copy of configuration
		vector<spring> & mSpringList;
};

#endif

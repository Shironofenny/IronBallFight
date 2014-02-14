#ifndef __SCENE2D_H__
#define __SCENE2D_H__

#include <Eigen/StdList>
#include <vector>

#include "Scene.h"
#include "SceneUtilities.h"
#include "Force/SpringForce.h"
#include "Force/Gravity.h"
#include "Force/AirFriction.h"

using namespace Eigen;

// Class name: Scene2D -- A collection of all stuff that a scene needs
// Description: This is in fact a transparent class, you could get all
// 		datas you need directly and modify them freely. However, the main
// 		reason for this class to exist is that it offers easy access for
// 		all datas to other blocks like (class) Updater and (class) Renderer.
class Scene2D : public Scene
{
	public:

		// Construction function
		Scene2D();

		// Destruction function
		~Scene2D();

		// Assign the dimension information.
		int getDimension() const override { return 2; }

		// Get all the general positions.
		VectorXd & getPosition();

		// Get all the general velocities.
		VectorXd & getVelocity();

		// Get all the general inertia.
		VectorXd & getInertia();

		// Get fixed information of the scene.
		vector <bool> & getFixed();

		// Get all line information
		vector <line> & getLine();

		// TBR
		// Initialize a scene.
		void createScene();

		// Calculate the total force appling on it
		// Params:
		// <r> _force : The output force vector, each component will apply on
		// 							the corresponding DOF
		void accumulateForce(VectorXd & _force);

		// I don't know what this mean exactly, but as it is required in
		// Eigen's documentation, I added it here.
		// Don't mind unless it gets bugs.
		EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	protected:

		// The degree of freedom this scene holds
		int mDegreeOfFreedoms;

		// All general positions in a scene
		VectorXd mGeneralPos;

		// All general velocitys in a scene
		VectorXd mGeneralVel;

		// All general inertia in a scene
		VectorXd mGeneralIne;

		// Set which positions are fixed:
		vector <bool> mIsFixed;

		// All the lines that should be rendered
		vector <line> mLineList;

		// All springs:
		vector <spring> mSpringList;

		// All torques:
		vector <torque> mTorqueList;
		
		// All the forces acting inside the scene
		vector <Force *> mForces;
};

#endif

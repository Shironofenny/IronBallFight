#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "./Interaction/Keyboard.h"
#include "./Utilities/Vector.h"
#include "./Utilities/Quaternion.h"
#include "./Utilities/ConstantHandler.h"
#include "../GLHeader.h"

class Camera
{
	public:

		// Default constructor
		Camera();

		// Construct with initial position only
		Camera(Vector const & _initPos);
		
		// Construct with initial rotation only
		Camera(Quaternion const & _initRot);

		// Construct with initial position and rotation
		Camera(Vector const & _initPos, Quaternion const & _initRot);

		// Destructor
		~Camera();

		// Update function, called before setup
		void update(double dt);

		// Set up function.
		// Note: This function will apply a series change of model view
		// matrix. Be sure to push the matrix stack before calling this
		// method.
		void setup();

	protected:

		// The position of camera
		Vector m_Position;

		// The rotation of camera
		Quaternion m_Rotation;
};

#endif

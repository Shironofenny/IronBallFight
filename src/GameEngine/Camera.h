#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "./Interaction/Keyboard.h"
#include "./Interaction/Mouse.h"
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
		Camera(double const & _initRotX, double const & _initRotY);

		// Construct with initial position and rotation
		Camera(Vector const & _initPos, double const & _initRotX, double const & _initRotY);

		// Destructor
		~Camera();

		// Update function, called before setup
		void update(double dt);

		// Set up function.
		// Note: This function will apply a series change of model view
		// matrix. Be sure to push the matrix stack before calling this
		// method.
		void setup();

		// Draw the reference axes of the camera
		void drawAxes() const;

	protected:

		// Pointwise rotate update function. May not preserve with mouse location
		void pointwiseRotation(double dt);

		// Global rotate update function. Not mathematically true
		void globalRotation(double dt);

		// The position of camera
		Vector m_Position;

		// The X rotation of camera
		double m_RotationX;

		// The Y rotation of camera
		double m_RotationY;

		// The coordinate transformation quaternion
		Quaternion m_Rotation;
		
		// The direction of the right hand of the camera, i.e. X direction
		Vector m_CameraDirectionX;
		
		// The direction of the head of the camera, i.e. Y direction
		Vector m_CameraDirectionY;

		// The direction of the back of the camera, i.e. Z direction
		Vector m_CameraDirectionZ;

		// The accumulative mouse move X
		int m_AccumulateX;

		// The accumulative mouse move Y
		int m_AccumulateY;
};

#endif

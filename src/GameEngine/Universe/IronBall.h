#ifndef __IRONBALL_H__
#define __IRONBALL_H__

#include "../Utilities/ConstantHandler.h"
#include "../Utilities/OBJLoader.h"
#include "../Sprite.h"
#include "../Shader/Shader.h"

class IronBall : public Sprite
{
	public:

		// Constructor
		IronBall();
		
		// Construct with original point
		IronBall(Vector const & _position);

		// Destructor
		~IronBall();
		
		// Initialize the iron ball
		void initialize();

		// Update function
		void update(double dt);

		// Set the rotation center to be around this iron ball
		// Called before camera is set.
		void setRotationCenter();

		// Render function
		void render();

	private:

		// The shape handle of body
		GLuint m_Body;

		// The shape handle of ear
		GLuint m_Ears;

		// The shape handle of motor
		GLuint m_Motor;
};

#endif

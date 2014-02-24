#ifndef __IRONBALL_H__
#define __IRONBALL_H__

#include "../Utilities/ConstantHandler.h"
#include "../Utilities/OBJLoader.h"
#include "../Sprite.h"

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

		// Render function
		void render();

	private:

		GLuint m_TextureNumber;
};

#endif

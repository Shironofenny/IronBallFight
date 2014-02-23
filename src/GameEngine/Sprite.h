#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "./Utilities/Vector.h"

class Sprite
{
	public:

		// Constructor.
		Sprite();
		
		// Constructor.
		Sprite(Vector const & _position);

		// Virtual destructor.
		virtual ~Sprite();

		// Updater, this function should be called per frame, and elapsed time should be
		// passed as the updating function should always depend on that.
		virtual void update(double dt);

		// Render function. Simply call OpenGL to draw the sprite.
		virtual void render();

	protected:

		Vector m_Position;
};

#endif

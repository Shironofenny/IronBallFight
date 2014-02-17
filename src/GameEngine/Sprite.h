#ifndef __SPRITE_H__
#define __SPRITE_H__

class Sprite
{
	public:

		// Constructor.
		Sprite();

		// Virtual destructor.
		virtual ~Sprite();

		// Updater, this function should be called per frame, and elapsed time should be
		// passed as the updating function should always depend on that.
		virtual void update(double dt);

		// Render function. Simply call OpenGL to draw the sprite.
		virtual void render();
};

#endif

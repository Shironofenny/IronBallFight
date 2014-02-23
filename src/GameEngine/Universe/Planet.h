#ifndef __PLANET_H__
#define __PLANET_H__

#include "../Sprite.h"

class Planet : public Sprite
{
	public:

		Planet();
		
		Planet(Vector const & _position);

		~Planet();

		void update(double dt);

		void render();
};

#endif

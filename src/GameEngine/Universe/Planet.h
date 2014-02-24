#ifndef __PLANET_H__
#define __PLANET_H__

#include "../Sprite.h"

class Planet : public Sprite
{
	public:

		// Constructor
		Planet();
		
		// Construct with original point
		Planet(Vector const & _position);

		// Construct with original point
		Planet(double _radius, Vector const & _position);

		// Destructor
		~Planet();

		// Update function
		void update(double dt);

		// Render function
		void render();

	protected:

		// The radius of the planet
		double m_Radius;
};

#endif

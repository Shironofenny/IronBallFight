#ifndef __BALLON_H__
#define __BALLON_H__

#include "../Sprite.h"

class Ballon : public Sprite
{
	public:

		// Constructor
		Ballon();
		
		// Construct with original point
		Ballon(Vector const & _position);

		// Construct with original point
		Ballon(double _radius, Vector const & _position);

		// Destructor
		~Ballon();

		// Update function
		void update(double dt);

		// Render function
		void render();

	protected:

		// The radius of the planet
		double m_Radius;
};

#endif

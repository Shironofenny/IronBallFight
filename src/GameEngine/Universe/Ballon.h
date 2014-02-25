#ifndef __BALLON_H__
#define __BALLON_H__

#include "../Sprite.h"
#include "../Utilities/ConstantHandler.h"
#include "../Shader/Shader.h"

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

		// Set the color of the ballon
		void setColor(GLfloat const _color[4]);

		// Update function
		void update(double dt);

		// Calculate the collision with a ray
		bool calculateRayCollision(Vector const & _source, Vector const & _direction);

		// Decrease the remaining life of this ballon
		void hurt(double dt);

		// Return whether the ballon is destroyed
		bool isDestroyed();

		// Render function
		void render();

	protected:

		// The radius of the planet
		double m_Radius;

		// The color of the ballon
		GLfloat color[4];

		// If this ballon is collided with an ray.
		bool m_IsRayColling;

		// The life of the ballon
		float m_RemainingLife;

		// If this ballon is destroyed
		bool m_IsDistroyed;
};

#endif

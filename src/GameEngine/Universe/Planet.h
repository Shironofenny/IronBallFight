#ifndef __PLANET_H__
#define __PLANET_H__

#include "../Sprite.h"
#include "../Utilities/TextureLoader.h"
#include "../Shader/Shader.h"

#include <queue>

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

		// Initialize the shape of the planet.
		// Write the shape handle into ms_Shape
		static void initializeShape();

		// Set the texture of the planet
		void setTexture(GLuint _texture);

		// Update function
		void update(double dt);

		// Render function
		void render();

	protected:

		// The radius of the planet
		double m_Radius;

		// The handle of the texture
		GLuint m_Texture;

		// The shape handle of the planet
		static GLuint ms_Shape;
};

// The triangle used to get the sphere mesh
struct Triangle
{
	int vertex[3];
};

#endif

#ifndef __RENDERER3D_H__
#define __RENDERER3D_H__

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "Renderer.h"
#include "Scene3D.h"

class Renderer3D : public Renderer
{
	public:

		// Construction function
		Renderer3D(Scene3D & _scene);

		// Destruction function (virtual)
		~Renderer3D();

		// Assign the dimension information
		int getDimension() const override { return 3; };

		void Render() override;

	private:

		// A private copy of the scene information
		Scene3D & m_Scene;
};

#endif

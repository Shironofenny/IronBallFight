#ifndef __RENDERER3D_H__
#define __RENDERER3D_H__

#include "Renderer.h"
#include "Scene3D.h"
#include "./Shader/Shader.h"

class Renderer3D : public Renderer
{
	public:

		// Construction function
		Renderer3D(Scene3D & _scene);

		// Destruction function (virtual)
		~Renderer3D();

		// Assign the dimension information
		int getDimension() const { return 3; };

		void Render();

	private:

		// A private copy of the scene information
		Scene3D & m_Scene;
};

#endif

#ifndef __SCENE3D_H__
#define __SCENE3D_H__

#include <vector>
#include <cmath>

#include "Scene.h"
#include "SceneUtilities.h"
#include "./Universe/Planet.h"

#define _USE_MATH_DEFINES

// Class name: Scene3D -- A collection of all stuff that a scene needs
// Description: This is in fact a transparent class, you could get all
// 		datas you need directly and modify them freely. However, the main
// 		reason for this class to exist is that it offers easy access for
// 		all datas to other blocks like (class) Updater and (class) Renderer.
class Scene3D : public Scene
{
	public:

		// Construction function
		Scene3D();

		// Destruction function
		~Scene3D();

		// Assign the dimension information.
		int getDimension() const { return 3; }

		// TBR
		// Initialize a scene.
		void createScene();

		// Get a copy of all the planets
		vector <Planet> & getPlanets();

	protected:

		vector <Planet> m_Planets;
};

#endif

#ifndef __ANIMATIONENGINE_H__
#define __ANIMATIONENGINE_H__

#include <vector>

#include <iostream>

#include "../GLHeader.h"
#include "Updater3D.h"
#include "Renderer3D.h"
#include "SceneUtilities.h"
#include "Utilities/FPSCounter.h"

using namespace std;

// This class is designed to handle the whole animation.
// It should be revised to the extend that simply calling (this.method) .Run()
// is enough for your (method) main function.
// 
// !! You should always starts from this class to modify any changes that
// 		you want to show in your animation clips.
class GameEngine
{
	public:
		
		// Construction function
		//
		// TODO: Always modify it and add describing comments below this line.
		//
		// Usr comments starts from the following line:
		GameEngine();

		// Destruction function
		//
		// TODO: Always remember to free any used pointers here to avoid memory leakage.
		//
		// Usr comments starts from the following line:
		~GameEngine();

		// Only use this function as external call for the whole physics engine.
		// This function serves as the call back function for OpenGL
		void run();

	private:

		// Update function
		void updateGame();

		// Render function
		void renderGame();

		// System level codes ends here
		//
		// TODO: Add any stuff you need to be private below this comment:
		//
		// Your code goes from here.
		
		// The scene class for the animation
		Scene3D * m_Scene;

		// The updater class for the animation
		Updater3D * m_Updater;

		// The renderer of the scene
		Renderer3D * m_Renderer;
	
};

#endif

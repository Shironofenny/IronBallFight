#ifndef __ANIMATIONENGINE_H__
#define __ANIMATIONENGINE_H__

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <vector>

#include <iostream>

#include "Updater2D.h"
#include "Renderer2D.h"
#include "../Color/ColorBoard.h"
#include "../Mouse.h"

using namespace std;

// This class is designed to handle the whole animation.
// It should be revised to the extend that simply calling (this.method) .Run()
// is enough for your (method) main function.
// 
// !! You should always starts from this class to modify any changes that
// 		you want to show in your animation clips.
class AnimationEngine
{
	public:
		
		// Construction function
		//
		// TODO: Always modify it and add describing comments below this line.
		//
		// Usr comments starts from the following line:
		AnimationEngine();

		// Destruction function
		//
		// TODO: Always remember to free any used pointers here to avoid memory leakage.
		//
		// Usr comments starts from the following line:
		~AnimationEngine();

		// Only use this function as external call for the whole physics engine.
		// This function serves as the call back function for OpenGL
		void run();

	private:

		// Update function
		void updateAnimation();

		// Render function
		void renderAnimation();

		// System level codes ends here
		//
		// TODO: Add any stuff you need to be private below this comment:
		//
		// Your code goes from here.
		
		// The scene class for the animation
		Scene2D * mScene;

		// The updater class for the animation
		Updater2D * mUpdater;

		// The renderer of the scene
		Renderer2D * mRenderer;
	
};

#endif

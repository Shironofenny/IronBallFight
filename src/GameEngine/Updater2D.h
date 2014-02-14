#ifndef __UPDATER2D_H__
#define __UPDATER2D_H__

#include "Updater.h"
#include "Scene2D.h"
#include <vector>

class Updater2D : public Updater
{
	public:

		// Construction function
		Updater2D(Scene2D & _scene);

		// Destroyer
		~Updater2D() {}
		
		// Main function, ie. the entrance of the class.
		void Update(double dt) override;

	protected:
		
		// A private copy of the scene. As it is a reference, 
		// it will always trace and report any modifications
		// made to the original scene.
		Scene2D & mScene;

		// Physics simulation should be proceeded here
		void physicsProcess(double dt);
};

#endif

#ifndef __GLUTCONFIG_H__
#define __GLUTCONFIG_H__

#include "GLHeader.h"
#include "./GameEngine/GameEngine.h"

#include <iostream>
using namespace std;

// Full Static class
// I HATE THIS PIECE OF CODE
namespace GLUTConfig
{
	// The initialization function.
	void g_InitializeEngine(int * _argcp, char ** _argv, int _wWidth, int _wHeight, int _wPosX, int _wPosY);

	// The call back function to fist display something (used in display)
	void g_InitializeDisplay();

	// The call back display function for glut (used in idle)
	void g_Display();

	// The run function
	void g_Run();

	// The error checking function
	bool g_CheckGLErrors();

	// Keyboard function
	void g_Keyboard( unsigned char key, int x, int y );

	// Mouse function
	void g_Mouse(int button, int state, int x, int y);

	// Mouse passive callback function
	void g_Passive();
}

#endif

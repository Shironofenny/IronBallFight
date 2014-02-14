#ifndef __GLUTCONFIG_H__
#define __GLUTCONFIG_H__

#if defined(__APPLE__) || defined(MACOSX)
#   include <GLUT/glut.h>
#else
#   include <GL/glut.h>
#endif

// Full Static class
// I HATE THIS PIECE OF CODE
namespace GLUTConfig
{
	// The initialization function.
	void gInitializeEngine(int * _argcp, char ** _argv, int _wWidth, int _wHeight, int _wPosX, int _wPosY);

	// The call back function for glut
	void gCallBack();

	// The run function
	void gRun();

	// The error checking function
	bool gCheckGLErrors();
}

#endif

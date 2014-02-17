#include "GLUTConfig.h"

extern char const * g_Name;
extern GameEngine g_Engine;

void GLUTConfig::g_InitializeEngine(int * _argcp, char ** _argv, int _wWidth, int _wHeight, int _wPosX, int _wPosY)
{
	// Init GLUT window.
	glutInit(_argcp, _argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(_wWidth, _wHeight);
	glutInitWindowPosition(_wPosX, _wPosY);
	
	// Name the animation window.
	glutCreateWindow(g_Name);
}

bool GLUTConfig::g_CheckGLErrors()
{
	GLenum errCode;
	const GLubyte *errString;
			  
	if ((errCode = glGetError()) != GL_NO_ERROR) 
	{
	  errString = gluErrorString(errCode);
	  cerr << "OpenGL Error:" <<errString<<endl;
	  fprintf(stderr,  " %s\n",  errString);
	  return false; 
	}
	return true;
}    

void GLUTConfig::g_InitializeDisplay()
{
	
}

void GLUTConfig::g_Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	g_Engine.run();
	glutSwapBuffers();
}

void GLUTConfig::g_Run()
{
	// Clear using black
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, 16./9, 1.0, 100.0);

	// Assign call back function
	glutDisplayFunc(g_InitializeDisplay);
	glutIdleFunc(g_Display);

	glutMainLoop();
}

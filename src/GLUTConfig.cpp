#include "GLUTConfig.h"

extern char const * gName;
extern AnimationEngine gEngine;

void GLUTConfig::gInitializeEngine(int * _argcp, char ** _argv, int _wWidth, int _wHeight, int _wPosX, int _wPosY)
{
	// Init GLUT window.
	glutInit(_argcp, _argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(_wWidth, _wHeight);
	glutInitWindowPosition(_wPosX, _wPosY);
	
	// Name the animation window.
	glutCreateWindow(gName);
}

bool GLUTConfig::gCheckGLErrors()
{
	GLenum errCode;
	const GLubyte *errString;
			  
	if ((errCode = glGetError()) != GL_NO_ERROR) 
	{
	  errString = gluErrorString(errCode);
	  std::cout << "OpenGL Error:" <<errString<<std::endl;
	  fprintf(stderr,  " %s\n",  errString);
	  return false; 
	}
	return true;
}    


void GLUTConfig::gCallBack()
{
	glClear(GL_COLOR_BUFFER_BIT);
	gEngine.run();

	GLUTConfig::gCheckGLErrors();
	glutSwapBuffers();
}

void GLUTConfig::gRun()
{
	// Clear using black
	glClearColor(ColorBoard::Instance().white);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 16.0, 0.0, 9.0, -1.0, 1.0);

	// Assign call back function
	glutDisplayFunc(gCallBack);
	glutIdleFunc(gCallBack);

	glutMainLoop();
}

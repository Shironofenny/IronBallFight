#include "GLUTConfig.h"
#include "./GameEngine/Camera.h"

extern char const * g_Name;
extern GameEngine g_Engine;

GLfloat camRotX, camRotY, camPosX, camPosY, camPosZ;
GLfloat ambient[] = {0.2, 0.2, 0.8, 1.0};
GLfloat position[] = {0.0, 0.0, 2.0, 1.0};
GLfloat mat_diffuse[] = {0.6, 0.6, 0.6, 1.0};
GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat mat_shininess[] = {50.0};

Camera camera(Vector(0, 0, 5.5));

void GLUTConfig::g_InitializeEngine(int * _argcp, char ** _argv, int _wWidth, int _wHeight, int _wPosX, int _wPosY)
{
	// Init GLUT window.
	glutInit(_argcp, _argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(_wWidth, _wHeight);
	glutInitWindowPosition(_wPosX, _wPosY);

	// Name the animation window.
	glutCreateWindow(g_Name);

	// Set the cursor to invisible
	glutSetCursor(GLUT_CURSOR_NONE);	
   
  // <TBD>
	camRotX = 20.0f;
	camRotY = 680.0f;
	camPosX = 0.0f;
	camPosY = 0.0f;
	camPosZ = -5.5f;
	
	glEnable( GL_DEPTH_TEST );
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	/*
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	// </TBD>
	// */
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

void GLUTConfig::g_Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	if(Keyboard::getInstance().isKeyDown('f'))
		glutFullScreen();
	if(Keyboard::getInstance().isKeyDown('r'))
	{
		glutReshapeWindow(960, 540);
		glutPositionWindow(150, 100);
	}
	if(Keyboard::getInstance().isKeyDown(27))
		exit(0);
	
	FPSCounter::getInstance().update();	
	camera.update(FPSCounter::getInstance().getTimeInterval());
	
	glPushMatrix();

		camera.setup();

		GLfloat selectedColor[] = {0, 1, 0, 1};
		glColor4fv(selectedColor);
		//glMaterialfv(GL_FRONT, GL_DIFFUSE, selectedColor);
		
		glutSolidCube(1.0);
		glColor3d(1., 0., 0.);
		glPushMatrix();
			glTranslated(1., 0., -1.);
			glutSolidCube(1.0);
		glPopMatrix();
		glColor3d(0., 0., 1.);
		glPushMatrix();
			glTranslated(1., 1., -5.);
			glutSolidCube(1.0);
		glPopMatrix();
		
		g_Engine.run();

	glPopMatrix();
	
	glFlush();
	glutSwapBuffers();
}

void GLUTConfig::g_Reshape(int w,  int h)
{
	glViewport(0, 0, w, h);

	ConstantHandler::getInstance().restoreWindowSize(w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	// Set the clipping volume
	gluPerspective(60.0f, (GLfloat)w / (GLfloat)h, 1.0f, 100.0f);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void GLUTConfig::g_KeyboardPressed( unsigned char key, int x, int y )
{
	Keyboard::getInstance().updatePress(key);
}

void GLUTConfig::g_KeyboardReleased( unsigned char key, int x, int y )
{
	Keyboard::getInstance().updateRelease(key);
}

void GLUTConfig::g_MousePassive(int x, int y)
{
	Mouse::getInstance().updatePassive(x, y);
	if(Mouse::getInstance().isOnBoundary())
		glutWarpPointer(ConstantHandler::getInstance().mousePositionX, \
										ConstantHandler::getInstance().mousePositionY);
}

void GLUTConfig::g_Run()
{
	// Assign call back function
	glutDisplayFunc(g_Display);
	glutReshapeFunc(g_Reshape);
	glutIdleFunc(g_Display);
	glutKeyboardFunc(g_KeyboardPressed);
	glutKeyboardUpFunc(g_KeyboardReleased);
	glutPassiveMotionFunc(g_MousePassive);

	glutWarpPointer(ConstantHandler::getInstance().mousePositionX, \
									ConstantHandler::getInstance().mousePositionY);

	glutMainLoop();
}

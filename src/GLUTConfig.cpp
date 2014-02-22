#include "GLUTConfig.h"

extern char const * g_Name;
extern GameEngine g_Engine;

GLfloat camRotX, camRotY, camPosX, camPosY, camPosZ;
GLfloat ambient[] = {0.2, 0.2, 0.8, 1.0};
GLfloat position[] = {0.0, 0.0, 2.0, 1.0};
GLfloat mat_diffuse[] = {0.6, 0.6, 0.6, 1.0};
GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat mat_shininess[] = {50.0};

GLfloat m_Position[] = {0.5, 0.5, 0.5};
GLfloat m_Camera[] ={0.0, 0.0, 0.0};

void GLUTConfig::g_InitializeEngine(int * _argcp, char ** _argv, int _wWidth, int _wHeight, int _wPosX, int _wPosY)
{
	// Init GLUT window.
	glutInit(_argcp, _argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(_wWidth, _wHeight);
	glutInitWindowPosition(_wPosX, _wPosY);
	
	// Name the animation window.
	glutCreateWindow(g_Name);
   
  // <TBD>
	camRotX = 20.0f;
	camRotY = 680.0f;
	camPosX = 0.0f;
	camPosY = 0.0f;
	camPosZ = -5.5f;
	
	glEnable( GL_DEPTH_TEST );
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	
	//glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	//glLightfv(GL_LIGHT0, GL_POSITION, position);
	
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	// </TBD>
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
	//g_Engine.run();
	
	if(Keyboard::getInstance().isKeyDown('d'))
		m_Position[0] += 0.1;
	if(Keyboard::getInstance().isKeyDown('a'))
		m_Position[0] -= 0.1;

	if(Keyboard::getInstance().isKeyDown('w'))
		m_Camera[1] +=0.1;
	if(Keyboard::getInstance().isKeyDown('s'))
		m_Camera[1] -=0.1;

	glPushMatrix();
    glTranslatef(0, -0.5, camPosZ);
		glTranslatef(m_Position[0], m_Position[1], m_Position[2]);
    glRotatef(camRotX, 1, 0, 0);
    //glRotatef(camRotY, 0, 1, 0);
		GLfloat selectedColor[] = {0, 1, 0, 1};
		glColor4fv(selectedColor);
		//glMaterialfv(GL_FRONT, GL_DIFFUSE, selectedColor);
		glutSolidCube(1.0);
	glPopMatrix();
	
	glFlush();
	glutSwapBuffers();
}

void GLUTConfig::g_Reshape(int w,  int h)
{
	glViewport(0, 0, w, h);
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

void GLUTConfig::g_Run()
{
	// Assign call back function
	glutDisplayFunc(g_Display);
	glutReshapeFunc(g_Reshape);
	glutIdleFunc(g_Display);
	glutKeyboardFunc(g_KeyboardPressed);
	glutKeyboardUpFunc(g_KeyboardReleased);

	glutMainLoop();
}

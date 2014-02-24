#include "Camera.h"
#include <iostream>

Camera::Camera():
	m_Position(), 
	m_Rotation(1., 0., 0., 0.), 
	m_CameraDirectionX(1., 0., 0.), 
	m_CameraDirectionY(0., 1., 0.), 
	m_CameraDirectionZ(0., 0., -1.) 
	//m_RotationY(0., 0., 1., 0.)
{
	m_RotationX = 0.0;
	m_RotationY = 0.0;
	m_AccumulateX = 0;
	m_AccumulateY = 0;
}

Camera::Camera(Vector const & _initPos):
	m_Position(_initPos), 
	m_Rotation(1., 0., 0., 0.), 
	m_CameraDirectionX(1., 0., 0.), 
	m_CameraDirectionY(0., 1., 0.), 
	m_CameraDirectionZ(0., 0., -1.)
	//m_RotationY(0., 0., 1., 0.)
{
	m_RotationX = 0.0;
	m_RotationY = 0.0;
	m_AccumulateX = 0;
	m_AccumulateY = 0;
}

Camera::Camera(double const & _initRotX, double const & _initRotY):
	m_Position(), 
	m_RotationX(_initRotX),
 	m_RotationY(_initRotY), 
	m_Rotation(1., 0., 0., 0.), 
	m_CameraDirectionX(1., 0., 0.), 
	m_CameraDirectionY(0., 1., 0.), 
	m_CameraDirectionZ(0., 0., -1.)
{
	m_AccumulateX = 0;
	m_AccumulateY = 0;
}

Camera::Camera(Vector const & _initPos, double const & _initRotX, double const & _initRotY):
	m_Position(_initPos), 
	m_RotationX(_initRotX),
 	m_RotationY(_initRotY),
	m_Rotation(1., 0., 0., 0.), 
	m_CameraDirectionX(1., 0., 0.), 
	m_CameraDirectionY(0., 1., 0.), 
	m_CameraDirectionZ(0., 0., -1.)
{
	m_AccumulateX = 0;
	m_AccumulateY = 0;
}

Camera::~Camera()
{

}

void Camera::update(double dt)
{
	pointwiseRotation(dt);
	//globalRotation(dt);
}

void Camera::pointwiseRotation(double dt)
{
	// Rotate the base directions using previous rotation
	m_CameraDirectionX = ((m_Rotation*Quaternion(0., 1., 0., 0.))*m_Rotation.conj()).im();
	m_CameraDirectionY = ((m_Rotation*Quaternion(0., 0., 1., 0.))*m_Rotation.conj()).im();
	m_CameraDirectionZ = ((m_Rotation*Quaternion(0., 0., 0., 1.))*m_Rotation.conj()).im();

	// Make sure that they are normalized
	m_CameraDirectionX.normalize();
	m_CameraDirectionY.normalize();
	m_CameraDirectionZ.normalize();

	// Translate camera
	if(Keyboard::getInstance().isKeyDown('w'))
		m_Position += m_CameraDirectionY * ConstantHandler::getInstance().cameraSpeed * dt;
	if(Keyboard::getInstance().isKeyDown('s'))
		m_Position -= m_CameraDirectionY * ConstantHandler::getInstance().cameraSpeed * dt;
	if(Keyboard::getInstance().isKeyDown('a'))
		m_Position -= m_CameraDirectionX * ConstantHandler::getInstance().cameraSpeed * dt;
	if(Keyboard::getInstance().isKeyDown('d'))
		m_Position += m_CameraDirectionX * ConstantHandler::getInstance().cameraSpeed * dt;

	if(Keyboard::getInstance().isKeyDown(' '))
		m_Position -= m_CameraDirectionZ * ConstantHandler::getInstance().cameraSpeed * dt * 2;
	if(Keyboard::getInstance().isKeyDown('f'))
		m_Position += m_CameraDirectionZ * ConstantHandler::getInstance().cameraSpeed * dt;
	
	// Extra Z direction rotation if applicable
	if(Keyboard::getInstance().isKeyDown('e'))
	{
		Quaternion dqz = Quaternion(cos(ConstantHandler::getInstance().cameraRotateZ * dt / 2), \
										m_CameraDirectionZ * sin(ConstantHandler::getInstance().cameraRotateZ * dt / 2));
		m_Rotation = dqz * m_Rotation;
	}
	if(Keyboard::getInstance().isKeyDown('q'))
	{
		Quaternion dqz = Quaternion(cos(-ConstantHandler::getInstance().cameraRotateZ * dt / 2), \
										m_CameraDirectionZ * sin(-ConstantHandler::getInstance().cameraRotateZ * dt / 2));
		m_Rotation = dqz * m_Rotation;
	}

	// Calculate the difference in x and y direction
	double diffx = (double) Mouse::getInstance().getDifferenceX() / ConstantHandler::getInstance().windowSizeY;
	double diffy = -(double) Mouse::getInstance().getDifferenceY() / ConstantHandler::getInstance().windowSizeY;

	// If there is no move, stops here.
	if (diffx == 0 && diffy == 0) return;
	
	// Calculate the exact mouse move vector
	Vector mouseMove = m_CameraDirectionX * diffx + m_CameraDirectionY * diffy;

	// Calculate the direction that the rotation is about
	Vector rotateCenter = -cross(m_CameraDirectionZ, mouseMove);

	rotateCenter.normalize();

	// Calculate the rotation angle
	double angle = atan(sqrt(diffx * diffx + diffy * diffy) / ConstantHandler::getInstance().virtualRotationRadius);

	// Assembly the quaternion
	Quaternion dq = Quaternion(cos(angle/2), rotateCenter * sin(angle/2));

	// Be Cautious about the order!
	m_Rotation = dq * m_Rotation;
}

void Camera::globalRotation(double dt)
{
	m_AccumulateX += -Mouse::getInstance().getDifferenceX();
	m_AccumulateY += -Mouse::getInstance().getDifferenceY();

	std::cout<<m_AccumulateX<<'\t'<<m_AccumulateY<<std::endl;

	double angleX = m_AccumulateX / ConstantHandler::getInstance().virtualRotationRadius / ConstantHandler::getInstance().windowSizeX;
	double angleY = m_AccumulateY / ConstantHandler::getInstance().virtualRotationRadius / ConstantHandler::getInstance().windowSizeY;
	
	Quaternion dqx = Quaternion(cos(angleX/2), Vector(0., 1., 0.) * sin(angleX/2));

	m_CameraDirectionX = ((m_Rotation*Quaternion(0., 1., 0., 0.))*m_Rotation.conj()).im();
	m_CameraDirectionY = ((m_Rotation*Quaternion(0., 0., 1., 0.))*m_Rotation.conj()).im();
	m_CameraDirectionZ = ((m_Rotation*Quaternion(0., 0., 0., 1.))*m_Rotation.conj()).im();

	m_CameraDirectionX.normalize();
	m_CameraDirectionY.normalize();
	m_CameraDirectionZ.normalize();

	Quaternion dqy = Quaternion(cos(angleY/2), m_CameraDirectionX * sin(angleY/2));

	m_Rotation = dqy * dqx;
	
	if(Keyboard::getInstance().isKeyDown('w'))
		m_Position += m_CameraDirectionY * ConstantHandler::getInstance().cameraSpeed * dt;
	if(Keyboard::getInstance().isKeyDown('s'))
		m_Position -= m_CameraDirectionY * ConstantHandler::getInstance().cameraSpeed * dt;
	if(Keyboard::getInstance().isKeyDown('a'))
		m_Position -= m_CameraDirectionX * ConstantHandler::getInstance().cameraSpeed * dt;
	if(Keyboard::getInstance().isKeyDown('d'))
		m_Position += m_CameraDirectionX * ConstantHandler::getInstance().cameraSpeed * dt;

	if(Keyboard::getInstance().isKeyDown(' '))
		m_Position -= m_CameraDirectionZ * ConstantHandler::getInstance().cameraSpeed * dt * 2;
}

void Camera::setup()
{
	glRotated(-m_Rotation.getAngle() * 180/ M_PI, m_Rotation.getVector()[0],\
		 				m_Rotation.getVector()[1], m_Rotation.getVector()[2]);

	glTranslatev((-m_Position));
}

void Camera::drawAxes() const
{
	glPushMatrix();

	glTranslatef(0., 0., -4);
		glColor3d(1., 1., 1.);
		glutSolidSphere(0.05, 20, 20);
		glColor3d(1., 0., 0.);
		glBegin(GL_LINES);
			glVertex3f(0., 0., 0.);
			glVertex3f(m_CameraDirectionX[0], m_CameraDirectionX[1], m_CameraDirectionX[2]);
		glEnd();
		glColor3d(0., 1., 0.);
		glBegin(GL_LINES);
			glVertex3f(0., 0., 0.);
			glVertex3f(m_CameraDirectionY[0], m_CameraDirectionY[1], m_CameraDirectionY[2]);
		glEnd();
		glColor3d(0., 0., 1.);
		glBegin(GL_LINES);
			glVertex3f(0., 0., 0.);
			glVertex3f(m_CameraDirectionZ[0], m_CameraDirectionZ[1], m_CameraDirectionZ[2]);
		glEnd();
	glPopMatrix();
}

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

}

Camera::~Camera()
{

}

void Camera::update(double dt)
{
	/*
	double angleX = -(double) Mouse::getInstance().getDifferenceY() / ConstantHandler::getInstance().windowSizeY / ConstantHandler::getInstance().virtualRotationRadius;
	double angleY = -(double) Mouse::getInstance().getDifferenceX() / ConstantHandler::getInstance().windowSizeX / ConstantHandler::getInstance().virtualRotationRadius;

	m_RotationX += angleX;
	m_RotationY += angleY;

	m_RotationX = m_RotationX > 2 * M_PI ? m_RotationX - 2 * M_PI : m_RotationX;
	m_RotationY = m_RotationY > 2 * M_PI ? m_RotationY - 2 * M_PI : m_RotationY;

	m_CameraDirectionX[0] = cos(m_RotationY);
 	m_CameraDirectionX[1] =	0.;
 	m_CameraDirectionX[2] = -sin(m_RotationY);
	
	m_CameraDirectionZ[0] = -sin(m_RotationY) * cos(m_RotationX);
 	m_CameraDirectionZ[1] =	sin(m_RotationX);
 	m_CameraDirectionZ[2] = -cos(m_RotationY) * cos(m_RotationX);

	m_CameraDirectionY = cross(m_CameraDirectionX, m_CameraDirectionZ);
*/

	double diffx = (double) Mouse::getInstance().getDifferenceX() / ConstantHandler::getInstance().windowSizeY;
	double diffy = -(double) Mouse::getInstance().getDifferenceY() / ConstantHandler::getInstance().windowSizeY;

	m_CameraDirectionX = ((m_Rotation*Quaternion(0., 1., 0., 0.))*m_Rotation.conj()).im();
	m_CameraDirectionY = ((m_Rotation*Quaternion(0., 0., 1., 0.))*m_Rotation.conj()).im();
	m_CameraDirectionZ = ((m_Rotation*Quaternion(0., 0., 0., 1.))*m_Rotation.conj()).im();

	m_CameraDirectionX.normalize();
	m_CameraDirectionY.normalize();
	m_CameraDirectionZ.normalize();

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
	
	if (diffx == 0 && diffy == 0) return;
	
	Vector mouseMove = m_CameraDirectionX * diffx + m_CameraDirectionY * diffy;

	// Calculate the direction that the rotation is about
	Vector rotateCenter = -cross(m_CameraDirectionZ, mouseMove);

	std::cout<<"X direction: "<<m_CameraDirectionX<<std::endl;
	std::cout<<"Y direction: "<<m_CameraDirectionY<<std::endl;
	std::cout<<"Z direction: "<<m_CameraDirectionZ<<std::endl;

	rotateCenter.normalize();

	std::cout<<"Rotate Center: "<<rotateCenter<<std::endl<<std::endl;

	// Calculate the rotation angle
	double angle = atan(sqrt(diffx * diffx + diffy * diffy) / ConstantHandler::getInstance().virtualRotationRadius);

	// Assembly the quaternion
	Quaternion dq = Quaternion(cos(angle/2), rotateCenter * sin(angle/2));

	m_Rotation = dq * m_Rotation;

/*
	// Assembly the 3D mouse move vector in world corrdinate

	// Calculate the direction that the rotation is about
	Vector rotateCenter = -cross(m_BackDirection, mouseMove);
	rotateCenter.normalize();

	// Calculate the rotation angle
	double angle = atan(sqrt(diffx * diffx + diffy * diffy) / ConstantHandler::getInstance().virtualRotationRadius);

	// Assembly the quaternion
	Quaternion dq = Quaternion(cos(angle/2), rotateCenter * sin(angle/2));

	std::cout<<Mouse::getInstance().getPositionX()<<'\t'<<Mouse::getInstance().getPositionY()<<std::endl;

	// Update three base vectors in camera coordinate
	m_BackDirection = ((dq*Quaternion(0, m_BackDirection))*dq.conj()).im();
	m_HeadDirection = ((dq*Quaternion(0, m_HeadDirection))*dq.conj()).im();
	m_RightDirection = ((dq*Quaternion(0, m_RightDirection))*dq.conj()).im();


	// Update the rotation quaternion
	m_Rotation *= dq;
*/
}

void Camera::setup()
{
	//glTranslatev((-m_Position));
	drawAxes();

	//glRotated(-m_RotationX / M_PI * 180, 1., 0., 0.);
	//glRotated(-m_RotationY / M_PI * 180, 0., 1., 0.);
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

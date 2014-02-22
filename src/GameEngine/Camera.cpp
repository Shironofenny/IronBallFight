#include "Camera.h"
#include <iostream>

Camera::Camera():
	m_Position(), 
	m_Rotation()
{
}

Camera::Camera(Vector const & _initPos):
	m_Position(_initPos), 
	m_Rotation()
{

}

Camera::Camera(Quaternion const & _initRot):
	m_Position(), 
	m_Rotation(_initRot)
{

}

Camera::Camera(Vector const & _initPos, Quaternion const & _initRot):
	m_Position(_initPos), 
	m_Rotation(_initRot)
{

}

Camera::~Camera()
{

}

void Camera::update(double dt)
{
	if(Keyboard::getInstance().isKeyDown('w'))
		m_Position[1] += ConstantHandler::getInstance().cameraSpeed * dt;
	if(Keyboard::getInstance().isKeyDown('s'))
		m_Position[1] -= ConstantHandler::getInstance().cameraSpeed * dt;
	if(Keyboard::getInstance().isKeyDown('a'))
		m_Position[0] -= ConstantHandler::getInstance().cameraSpeed * dt;
	if(Keyboard::getInstance().isKeyDown('d'))
		m_Position[0] += ConstantHandler::getInstance().cameraSpeed * dt;
}

void Camera::setup()
{
	glTranslatev((-m_Position));
}

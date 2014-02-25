#include "Ballon.h"

Ballon::Ballon():
	Sprite()
{
	m_Radius = ConstantHandler::getInstance().ballonRadius;
	m_IsDistroyed = false;
	m_IsRayColling = false;
}

Ballon::Ballon(Vector const & _position):
	Sprite(_position)
{
	m_Radius = ConstantHandler::getInstance().ballonRadius;
	m_IsDistroyed = false;
	m_IsRayColling = false;
}

Ballon::Ballon(double _radius, Vector const & _position):
	Sprite(_position), 
	m_Radius(_radius)
{
	m_IsDistroyed = false;
	m_IsRayColling = false;
}

Ballon::~Ballon()
{

}

void Ballon::update(double dt)
{

}

bool Ballon::calculateRayCollision(Vector const & _position, Vector const & _direction)
{
	if (m_IsDistroyed) return false;

	Vector diff = m_Position - _position;
	double dotProduct = dot(diff, _direction);
	Vector residual = diff - (_direction * dotProduct);
	m_IsRayColling = (residual.norm() < m_Radius);

	if (m_IsRayColling) std::cout<<"Collided at "<<_direction<<std::endl;
	return m_IsRayColling;
}

void Ballon::hurt(double dt)
{
	m_RemainingLife -= dt * ConstantHandler::getInstance().ballonDamagePerSecond;
	if (m_RemainingLife <= 0.0) m_IsDistroyed = true;
}

bool Ballon::isDestroyed()
{
	return m_IsDistroyed;
}

void Ballon::render()
{
	if (m_IsDistroyed) return;

	glPushMatrix();
		
		Shader::getInstance().attributeInt("isCollided", (int)m_IsRayColling);
		Shader::getInstance().attributeVec3("raySource", Vector(0., 0., 0.));
		Shader::getInstance().attributeVec3("rayDirection", Vector(0., 0., -1.));
		glTranslatev(m_Position);
		glutSolidSphere(m_Radius, 20, 20);
		Shader::getInstance().attributeInt("isCollided", 0);

	glPopMatrix();
}

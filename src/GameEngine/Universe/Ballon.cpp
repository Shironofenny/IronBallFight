#include "Ballon.h"

Ballon::Ballon():
	Sprite()
{
	m_Radius = ConstantHandler::getInstance().ballonRadius;
	m_IsDistroyed = false;
	m_IsRayColliding = false;
	m_RemainingLife = 1.0;
	for (int i = 0; i <= 3; i++)
		m_Color[i] = 1.0;
}

Ballon::Ballon(Vector const & _position):
	Sprite(_position)
{
	m_Radius = ConstantHandler::getInstance().ballonRadius;
	m_IsDistroyed = false;
	m_IsRayColliding = false;
	m_RemainingLife = 1.0;
	for (int i = 0; i <= 3; i++)
		m_Color[i] = 1.0;
}

Ballon::Ballon(double _radius, Vector const & _position):
	Sprite(_position), 
	m_Radius(_radius)
{
	m_IsDistroyed = false;
	m_IsRayColliding = false;
	m_RemainingLife = 1.0;
	for (int i = 0; i <= 3; i++)
		m_Color[i] = 1.0;
}

Ballon::~Ballon()
{

}

void Ballon::setColor(GLfloat const _color[4])
{
	for (int i = 0; i <= 3; i++)
		m_Color[i] = _color[i];
}

void Ballon::update(double dt)
{
	if(m_IsRayColliding) hurt(dt);
	m_IsRayColliding = false;
}

double Ballon::calculateRayCollision(Vector const & _position, Vector const & _direction)
{
	if (m_IsDistroyed) return false;

	Vector diff = m_Position - _position;
	double dotProduct = dot(diff, _direction);
	
	// If the ballon is in the opposite way of the ray, return false
	if(dotProduct < 0.0) 
		return -1.0;

	Vector residual = diff - (_direction * dotProduct);
	m_IsRayColliding = (residual.norm() < m_Radius);

	return m_IsRayColliding ? diff.norm() : -1.0;
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

bool & Ballon::getRayColliding()
{
	return m_IsRayColliding;
}

bool const & Ballon::getRayColliding() const
{
	return m_IsRayColliding;
}

void Ballon::render()
{
	if (m_IsDistroyed) return;

	glColor4fv(m_Color);

	glPushMatrix();
		
		Shader::getInstance().attributeInt("isCollided", (int)m_IsRayColliding);
		Shader::getInstance().attributeVec3("raySource", Vector(0., 0., 0.));
		Shader::getInstance().attributeVec3("rayDirection", Vector(0., 0., -1.));
		glTranslatev(m_Position);
		glutSolidSphere(m_Radius, 20, 20);
		Shader::getInstance().attributeInt("isCollided", 0);

	glPopMatrix();
}

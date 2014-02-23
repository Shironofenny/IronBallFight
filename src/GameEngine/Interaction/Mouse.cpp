#include "Mouse.h"
#include <iostream>

Mouse::Mouse()
{
	m_IsFirstUpdate = true;
	m_XNow = 0;
	m_YNow = 0;
	m_XLast = 0;
	m_YLast = 0;
}

Mouse::~Mouse()
{

}

void Mouse::updatePassive(int _x, int _y)
{
	if(m_IsFirstUpdate)
	{
		m_IsFirstUpdate = false;
		m_XNow = _x;
		m_YNow = _y;
	}
	m_XLast = m_XNow;
	m_YLast = m_YNow;
	m_XNow = _x;
	m_YNow = _y;
}

bool Mouse::isOnBoundary()
{
	int xBoundary = ConstantHandler::getInstance().windowSizeX / 10;
	int yBoundary = ConstantHandler::getInstance().windowSizeY / 10;
	return (m_XNow <= xBoundary ||\
					m_XNow >= ConstantHandler::getInstance().windowSizeX - xBoundary ||\
		 			m_YNow <= yBoundary ||\
					m_YNow >= ConstantHandler::getInstance().windowSizeY - yBoundary);
}

int Mouse::getPositionX() const
{
	return m_XNow;
}

int Mouse::getPositionY() const
{
	return m_YNow;
}

int Mouse::getDifferenceX()
{
	int diff = m_XNow - m_XLast;
	m_XLast = m_XNow;
	return diff;
}

int Mouse::getDifferenceY()
{
	int diff = m_YNow - m_YLast;
	m_YLast = m_YNow;
	return diff;
}

int Mouse::getDeviationX() const
{
	return m_XNow - ConstantHandler::getInstance().mousePositionX;
}

int Mouse::getDeviationY() const
{
	return m_YNow - ConstantHandler::getInstance().mousePositionY;
}

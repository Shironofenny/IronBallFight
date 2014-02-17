#include "FPSCounter.h"

FPSCounter::FPSCounter()
{
	m_TotalElapsedTime = 0;
}

void FPSCounter::update()
{
	m_PreviousElapsedTime = m_TotalElapsedTime;
	m_TotalElapsedTime = glutGet(GLUT_ELAPSED_TIME);
	m_TimeInterval = m_TotalElapsedTime - m_PreviousElapsedTime;
}

double FPSCounter::getTotalElapsedTime()
{
	return ((double)m_PreviousElapsedTime/1000);
}

double FPSCounter::getTimeInterval()
{
	return ((double)m_TimeInterval/1000);
}

double FPSCounter::getFPS()
{
	return (1000/(double)m_TimeInterval);
}

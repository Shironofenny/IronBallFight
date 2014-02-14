#include "Renderer2D.h"

#include <iostream>
using namespace std;

Renderer2D::Renderer2D(Scene2D & _scene) :
	Renderer(), 
	mScene(_scene)
{
	assert( _scene.getDimension() == 2 );
	assert( _scene.getDimension() == this->getDimension() );
}

Renderer2D::~Renderer2D()
{
}

void Renderer2D::renderPoint(Vector2d const & x, double const radius) const
{
	// In order to get an integer n, we need to calculate n first.
	int n = (int) (2.0 * PI * radius / mathUtility::gPointPrecision);
	double dtheta = 2.0 * PI / ((double) n);

	// Start drawing the solid circle
	glColor4d(ColorBoard::Instance().black);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2d(x(0), x(1));
		for (int i = 0; i < n; ++i)
		{
			glVertex2d(x(0) + radius * cos((double)i * dtheta), \
				 x(1) + radius * sin((double)i * dtheta));
		}
		glVertex2d(x(0) + radius, x(1));
	glEnd();
}

void Renderer2D::renderLine(Vector2d & x0, Vector2d & x1) const
{
	glColor4d(ColorBoard::Instance().black);
	glBegin(GL_LINES);
		glVertex2d(x0(0), x0(1));
		glVertex2d(x1(0), x1(1));
	glEnd();
}

void Renderer2D::Render()
{
	VectorXd x = mScene.getPosition();
	assert(x.size() > 0);
	for(int i = 0; i < x.size(); i += 2)
	{
		Vector2d xd(x(i), x(i+1));
		renderPoint(xd, mathUtility::gPointRadius);
	}

	vector <line> & lines = mScene.getLine();
	for (vector <line>::size_type i = 0; i<lines.size(); ++i)
	{
		Vector2d xd1(x(lines[i].first * 2), x(lines[i].first * 2 + 1));
		Vector2d xd2(x(lines[i].second * 2), x(lines[i].second * 2 + 1));
		renderLine(xd1, xd2);
	}
}

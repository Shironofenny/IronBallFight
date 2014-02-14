#ifndef __RENDERER2D_H__
#define __RENDERER2D_H__

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <Eigen/StdVector>

#include "Renderer.h"
#include "Scene2D.h"
#include "../MathUtilities.h"
#include "../Color/ColorBoard.h"

using namespace Eigen;

class Renderer2D : public Renderer
{
	public:

		// Construction function
		Renderer2D(Scene2D & _scene);

		// Destruction function (virtual)
		~Renderer2D();

		// Assign the dimension information
		int getDimension() const override { return 2; };

		void Render() override;

		EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	private:

		// A private copy of the scene information
		Scene2D & mScene;

		// Render a point in the screen
		void renderPoint(Vector2d const & x, double const radius) const;

		// Render a line in the screen
		void renderLine(Vector2d & x0, Vector2d & x1) const;
};

#endif

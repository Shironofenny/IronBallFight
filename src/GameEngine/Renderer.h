#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <assert.h>

#include "Scene.h"
#include "../IDimension.h"

class Renderer : public IDimension
{
	public:

		Renderer();

		virtual ~Renderer();

		virtual void Render();
};

#endif

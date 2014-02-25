#include "ConstantHandler.h"

ConstantHandler::ConstantHandler():
	lightSource()
{
	cameraSpeed = 3.0;
	cameraRotateZ = 0.2;
	virtualRotationRadius = 0.2;
	windowSizeX = 960;
	windowSizeY = 480;
	mousePositionX = windowSizeX / 2;
	mousePositionY = windowSizeY / 2;

	vertexShader = "./shader/vertex.shader";
	fragmentShader = "./shader/fragment.shader";

	ironBallPosition[0] = 0;
	ironBallPosition[1] = -0.7;
	ironBallPosition[2] = -2.5;

	lightSource[0] = 0.0;
	lightSource[1] = 0.0;
	lightSource[2] = 0.0;

	ballonRadius = 1.0;
	ballonDamagePerSecond = 0.6;
}

void ConstantHandler::restoreWindowSize(int x, int y)
{
	windowSizeX = x;
	windowSizeY = y;
	mousePositionX = windowSizeX / 2;
	mousePositionY = windowSizeY / 2;
}

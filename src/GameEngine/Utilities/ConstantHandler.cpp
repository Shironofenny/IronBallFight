#include "ConstantHandler.h"

ConstantHandler::ConstantHandler()
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
}

void ConstantHandler::restoreWindowSize(int x, int y)
{
	windowSizeX = x;
	windowSizeY = y;
	mousePositionX = windowSizeX / 2;
	mousePositionY = windowSizeY / 2;
}

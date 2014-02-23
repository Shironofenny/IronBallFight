#include "ConstantHandler.h"

ConstantHandler::ConstantHandler()
{
	cameraSpeed = 3.0;
	virtualRotationRadius = 0.2;
	windowSizeX = 960;
	windowSizeY = 480;
	mousePositionX = windowSizeX / 2;
	mousePositionY = windowSizeY / 2;
}

void ConstantHandler::restoreWindowSize(int x, int y)
{
	windowSizeX = x;
	windowSizeY = y;
	mousePositionX = windowSizeX / 2;
	mousePositionY = windowSizeY / 2;
}

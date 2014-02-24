#ifndef __CONSTANTHANDLER_H__
#define __CONSTANTHANDLER_H__

#include <string>
#include "../Utilities/Vector.h"

// Class to handle all constant definition
class ConstantHandler
{
	public:

		// Singleton
		static ConstantHandler & getInstance()
		{
			static ConstantHandler instance;
			return instance;
		}

		// Parse configuration from file
		void parseConfiguration();

		// Refresh the window size information
		void restoreWindowSize(int x, int y);

		// The relative position of the iron ball
		Vector ironBallPosition;

		double cameraSpeed;

		double cameraRotateZ;

		int windowSizeX;

		int windowSizeY;

		int mousePositionX;

		int mousePositionY;

		double virtualRotationRadius;

		// Shader configs
		std::string vertexShader;

		std::string fragmentShader;

	private:

		// Private constructor
		ConstantHandler();

		// Prevent from external implementation
		ConstantHandler(ConstantHandler const &);
		void operator = (ConstantHandler const &);

};

#endif

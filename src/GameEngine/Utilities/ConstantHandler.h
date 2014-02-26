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

		// Camera configs
		double cameraSpeed;

		double cameraRotateZ;
		
		double virtualRotationRadius;

		// Window configs
		int windowSizeX;

		int windowSizeY;

		int mousePositionX;

		int mousePositionY;

		// Shader configs
		std::string vertexShader;

		std::string fragmentShader;

		// The position of the light source
		Vector lightSource;

		// Ballon configs
		double ballonRadius;

		float ballonDamagePerSecond;

		// The time that planet mesh shall be refined
		int planetMeshRefineTime;

	private:

		// Private constructor
		ConstantHandler();

		// Prevent from external implementation
		ConstantHandler(ConstantHandler const &);
		void operator = (ConstantHandler const &);

};

#endif

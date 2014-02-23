#ifndef __CONSTANTHANDLER_H__
#define __CONSTANTHANDLER_H__

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

		double cameraSpeed;

		int windowSizeX;

		int windowSizeY;

		int mousePositionX;

		int mousePositionY;

		double virtualRotationRadius;

	private:

		// Private constructor
		ConstantHandler();

		// Prevent from external implementation
		ConstantHandler(ConstantHandler const &);
		void operator = (ConstantHandler const &);

};

#endif

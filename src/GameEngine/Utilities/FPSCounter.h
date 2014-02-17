#ifndef __FPSCOUNTER_H__
#define __FPSCOUNTER_H__

#include "../../GLHeader.h"

// A singleton class used to manage the time flow in the whole game. 
class FPSCounter
{
	public:

		// Singleton. Return the only instance.
		static FPSCounter & getInstance()
		{
			static FPSCounter instance;
			return instance;
		}

		// This function should be called for every frame. During
		// update, this class will update all the datas needed for
		// time control in the game.
		void update();

		// Get total elapsed time in second.
		double getTotalElapsedTime();

		// Get time interval between two frames in second.
		double getTimeInterval();

		// Get frame per second.
		double getFPS();

	private:

		// Constructor
		FPSCounter();

		// Prevent from any sort of creation of objects.
		FPSCounter(FPSCounter const &);
		void operator = (FPSCounter const &);

		// Total elapsed time.
		int m_TotalElapsedTime;

		// Total elapsed time of the previous update.
		int m_PreviousElapsedTime;

		// The time interval between two frames.
		int m_TimeInterval;
};
#endif

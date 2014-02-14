#include "GameEngine/GameEngine.h"
#include "GLUTConfig.h"

using namespace std;
using namespace GLUTConfig;

// The name of the animation engin.
char const * gName = "Animation\0";
	
// The engin of the whole syste
AnimationEngine gEngine;

int main(int argc, char** argv)
{
	gInitializeEngine(&argc, argv, 960, 540, 150, 100);
	gRun();
	return 0;
}

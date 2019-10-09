#include "Screens/Gameplay.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif




void main()
{
	RlArkJB::Game::StartGame();
}

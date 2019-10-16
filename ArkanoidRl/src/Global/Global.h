#ifndef GLOBAL_H
#define GLOBAL_H

#include "raylib.h"
#include "Objects/Ball/Ball.h"
#include "Objects/Player/Player.h"

namespace RlArkJB
{
	typedef enum GameScreen { MENUSCREEN, GAMEPLAYSCREEN, GAMEOVERSCREEN, CREDITSSCREEN, ENDING } GameScreen;
	extern int screenWidth;
	extern int screenHeight;
	extern int currentScreen;


	static bool gameOver = false;
	static bool pause = false;

}


#endif
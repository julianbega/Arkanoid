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
	struct Vector2
	{
		double x;
		double y;
	};

	static bool gameOver = false;
	static bool pause = false;

	static Player player = Paleta::InitPlayer();
	static Ball ball = Pelota::InitPelota();
	static Brick brick[LINES_OF_BRICKS][BRICKS_PER_LINE] = { 0 };
	static Vector2 brickSize = { 0 };
}


#endif
#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "raylib.h"

#include "Menu.h"


namespace RlArkJB
{
	const int pointsToWin = 2;

	
		 void InitGame(Ball &ball, Player &player1, Player &player2);
		 void StartGame();
		 void UpdateGame(Ball &ball, Player &player1, Player &player2);
		 void UnloadGame(Ball &ball, Player &player1, Player &player2);
		

}

#endif
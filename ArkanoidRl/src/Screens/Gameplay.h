#ifndef PANTALLA_DE_JUEGO_H
#define PANTALLA_DE_JUEGO_H

#include "raylib.h"

#include "Menu.h"


namespace RlArkJB
{
	const int pointsToWin = 2;

	namespace Game
	{
		static void InitGame(void); 
		static void StartGame();
		static void UpdateGame(void);
		static void UnloadGame(void);
		
	}

}

#endif
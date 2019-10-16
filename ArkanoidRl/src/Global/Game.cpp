#include "Game.h"
#include "Screens/Credits.h"
#include "Screens/GameOver.h"
#include "Screens/Gameplay.h"
#include "Screens/Menu.h"

namespace RlArkJB
{

	void gameLoop()
	{
		InitWindow(screenWidth, screenHeight, "sample game: arkanoid");
		while (!WindowShouldClose())   
		{
			switch (currentScreen)
			{
			case MENUSCREEN:
				MainMenu();
				break;

			case GAMEPLAYSCREEN:
				StartGame();
				break;

			case GAMEOVERSCREEN:
				GameOver();
				break; 

			case CREDITSSCREEN:

				break; 

			case ENDING :
				CloseWindow();
				break;

			default:
				break;
			}
		}
	}
}
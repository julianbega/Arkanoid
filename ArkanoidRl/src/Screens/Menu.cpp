#include "Menu.h"
namespace RlArkJB
{

	void MainMenu() 
	{		
		UpdateMenu();
		DrawMenu();

	}

	void UpdateMenu()
	{
		if (IsKeyReleased(KEY_ESCAPE))
		{
			currentScreen = ENDING;
		}
		if (IsKeyReleased(KEY_ENTER))
		{
			currentScreen = GAMEPLAYSCREEN;

		}
	}

}

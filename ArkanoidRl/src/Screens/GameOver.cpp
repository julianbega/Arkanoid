#include "GameOver.h"

namespace RlArkJB
{
	void GameOver()
	{
		UpdateGameOver();
		DrawGameOver();

	}

	void UpdateGameOver()
	{
		if (IsKeyReleased(KEY_ESCAPE))
		{
			currentScreen = ENDING;
		}
		if (IsKeyReleased(KEY_ENTER))
		{
			currentScreen = MENUSCREEN;

		}
	}
}
#include "Draw.h"

namespace RlArkJB
{

	namespace Draw
	{
		void DrawGame(void)
		{
			BeginDrawing();

			ClearBackground(RAYWHITE);

			if (!gameOver)
			{
				// Draw player bar
				DrawRectangle(player.position.x - player.size.x / 2, player.position.y - player.size.y / 2, player.size.x, player.size.y, BLACK);

				// Draw player lives
				for (int i = 0; i < player.life; i++) DrawRectangle(20 + 40 * i, screenHeight - 30, 35, 10, LIGHTGRAY);

				// Draw ball
				DrawCircleV(ball.position, ball.radius, MAROON);

				// Draw bricks
				for (int i = 0; i < LINES_OF_BRICKS; i++)
				{
					for (int j = 0; j < BRICKS_PER_LINE; j++)
					{
						if (brick[i][j].active)
						{
							if ((i + j) % 2 == 0) DrawRectangle(brick[i][j].position.x - brickSize.x / 2, brick[i][j].position.y - brickSize.y / 2, brickSize.x, brickSize.y, GRAY);
							else DrawRectangle(brick[i][j].position.x - brickSize.x / 2, brick[i][j].position.y - brickSize.y / 2, brickSize.x, brickSize.y, DARKGRAY);
						}
					}
				}

				if (pause) DrawText("GAME PAUSED", screenWidth / 2 - MeasureText("GAME PAUSED", 40) / 2, screenHeight / 2 - 40, 40, GRAY);
			}
			else DrawText("PRESS [ENTER] TO PLAY AGAIN", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2, GetScreenHeight() / 2 - 50, 20, GRAY);

			EndDrawing();
		}

		void UpdateDrawFrame(void)
		{
			Game::UpdateGame();
			DrawGame();
		}
	}
}
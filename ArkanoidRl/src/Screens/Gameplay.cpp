#include "Gameplay.h"

namespace RlArkJB
{
	int screenHeight = 450;
	int screenWidth = 800;
	namespace Game
	{
		void StartGame()
		{
			InitWindow(screenWidth, screenHeight, "sample game: arkanoid"); 
			SetTargetFPS(60);
			Ball ball;
			Player player1;
			Player player2;
			int currentScreen = 1;
			InitGame(); //(player1, player2, ball, currentScreen)
			
			while (!WindowShouldClose())    // Detect window close button or ESC key
			{
				// Update and Draw
				//----------------------------------------------------------------------------------
				Draw::UpdateDrawFrame();
				//----------------------------------------------------------------------------------
			}
			UnloadGame();         // Unload loaded data (textures, sounds, models...)

			CloseWindow();
		}

		void InitGame(void)
		{
			brickSize.x = GetScreenWidth() / BRICKS_PER_LINE;
			brickSize.y = 40;

			// Initialize player
			player.position.x = screenWidth / 2;
			player.position.y =  screenHeight * 7 / 8;
			player.size.x = screenWidth / 10;
			player.size.y = 20;
			player.life = PLAYER_MAX_LIFE;

			// Initialize ball
			ball.position.x = screenWidth / 2;
			ball.position.y =  screenHeight * 7 / 8 - 30;
			ball.speed.x = 0;
			ball.speed.y = 0;
			ball.radius = 7;
			ball.active = false;

			// Initialize bricks
			int initialDownPosition = 50;

			for (int i = 0; i < LINES_OF_BRICKS; i++)
			{
				for (int j = 0; j < BRICKS_PER_LINE; j++)
				{
					brick[i][j].position = (Vector2) { j*brickSize.x + brickSize.x / 2, i*brickSize.y + initialDownPosition };
					brick[i][j].active = true;
				}
			}
		}

		void UpdateGame(void)
		{
			if (!gameOver)
			{
				if (IsKeyPressed('P')) pause = !pause;

				if (!pause)
				{
					// Player movement logic
					if (IsKeyDown(KEY_LEFT)) player.position.x -= 5;
					if ((player.position.x - player.size.x / 2) <= 0) player.position.x = player.size.x / 2;
					if (IsKeyDown(KEY_RIGHT)) player.position.x += 5;
					if ((player.position.x + player.size.x / 2) >= screenWidth) player.position.x = screenWidth - player.size.x / 2;

					// Ball launching logic
					if (!ball.active)
					{
						if (IsKeyPressed(KEY_SPACE))
						{
							ball.active = true;
							ball.speed = (Vector2) { 0, -5 };
						}
					}

					// Ball movement logic
					if (ball.active)
					{
						ball.position.x += ball.speed.x;
						ball.position.y += ball.speed.y;
					}
					else
					{
						ball.position = (Vector2) { player.position.x, screenHeight * 7 / 8 - 30 };
					}

					// Collision logic: ball vs walls 
					if (((ball.position.x + ball.radius) >= screenWidth) || ((ball.position.x - ball.radius) <= 0)) ball.speed.x *= -1;
					if ((ball.position.y - ball.radius) <= 0) ball.speed.y *= -1;
					if ((ball.position.y + ball.radius) >= screenHeight)
					{
						ball.speed = (Vector2) { 0, 0 };
						ball.active = false;

						player.life--;
					}

					// Collision logic: ball vs player
					if (CheckCollisionCircleRec(ball.position, ball.radius,
						(Rectangle) {
						player.position.x - player.size.x / 2, player.position.y - player.size.y / 2, player.size.x, player.size.y
					}))
					{
						if (ball.speed.y > 0)
						{
							ball.speed.y *= -1;
							ball.speed.x = (ball.position.x - player.position.x) / (player.size.x / 2) * 5;
						}
					}

						// Collision logic: ball vs bricks
						for (int i = 0; i < LINES_OF_BRICKS; i++)
						{
							for (int j = 0; j < BRICKS_PER_LINE; j++)
							{
								if (brick[i][j].active)
								{
									// Hit below
									if (((ball.position.y - ball.radius) <= (brick[i][j].position.y + brickSize.y / 2)) &&
										((ball.position.y - ball.radius) > (brick[i][j].position.y + brickSize.y / 2 + ball.speed.y)) &&
										((fabs(ball.position.x - brick[i][j].position.x)) < (brickSize.x / 2 + ball.radius * 2 / 3)) && (ball.speed.y < 0))
									{
										brick[i][j].active = false;
										ball.speed.y *= -1;
									}
									// Hit above
									else if (((ball.position.y + ball.radius) >= (brick[i][j].position.y - brickSize.y / 2)) &&
										((ball.position.y + ball.radius) < (brick[i][j].position.y - brickSize.y / 2 + ball.speed.y)) &&
										((fabs(ball.position.x - brick[i][j].position.x)) < (brickSize.x / 2 + ball.radius * 2 / 3)) && (ball.speed.y > 0))
									{
										brick[i][j].active = false;
										ball.speed.y *= -1;
									}
									// Hit left
									else if (((ball.position.x + ball.radius) >= (brick[i][j].position.x - brickSize.x / 2)) &&
										((ball.position.x + ball.radius) < (brick[i][j].position.x - brickSize.x / 2 + ball.speed.x)) &&
										((fabs(ball.position.y - brick[i][j].position.y)) < (brickSize.y / 2 + ball.radius * 2 / 3)) && (ball.speed.x > 0))
									{
										brick[i][j].active = false;
										ball.speed.x *= -1;
									}
									// Hit right
									else if (((ball.position.x - ball.radius) <= (brick[i][j].position.x + brickSize.x / 2)) &&
										((ball.position.x - ball.radius) > (brick[i][j].position.x + brickSize.x / 2 + ball.speed.x)) &&
										((fabs(ball.position.y - brick[i][j].position.y)) < (brickSize.y / 2 + ball.radius * 2 / 3)) && (ball.speed.x < 0))
									{
										brick[i][j].active = false;
										ball.speed.x *= -1;
									}
								}
							}
						}

						// Game over logic
						if (player.life <= 0) gameOver = true;
						else
						{
							gameOver = true;

							for (int i = 0; i < LINES_OF_BRICKS; i++)
							{
								for (int j = 0; j < BRICKS_PER_LINE; j++)
								{
									if (brick[i][j].active) gameOver = false;
								}
							}
						}
				}
			}
			else
			{
				if (IsKeyPressed(KEY_ENTER))
				{
					InitGame();
					gameOver = false;
				}
			}
		}

		void UnloadGame(void)
		{
			// TODO: Unload all dynamic loaded data (textures, sounds, models...)
		}
	}
}
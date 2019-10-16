#include "Gameplay.h"

#include "Objects/Brick/Brick.h"
#include "Objects/Player/Player.h"
#include "Global/Global.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


namespace RlArkJB
{
	
		void StartGame()
		{
			Ball ball;
			Player player1;
			Player player2;
			int currentScreen = 1;
			InitGame(ball, player1, player2); //(player1, player2, ball, currentScreen)
			
			while (!WindowShouldClose())    // Detect window close button or ESC key
			{
				// Update and Draw
				//----------------------------------------------------------------------------------
				UpdateDrawFrame(ball, player1, player2);
				//----------------------------------------------------------------------------------
			}
			//UnloadGame();         // Unload loaded data (textures, sounds, models...)

			CloseWindow();
		}

		void InitGame(Ball &ball, Player &player1, Player &player2)
		{
			brickSize.x = GetScreenWidth() / BRICKS_PER_LINE;
			brickSize.y = 40.0f;

			InitPlayer(screenWidth / 2.0f, screenHeight * 7.0f / 8.0f, screenWidth / 10.0f, 20.0f, player1);

			

			ball = InitBall(screenWidth / 2.0f, screenHeight * 7.0f / 8.0f - 30.0f, 7.0f);
			ball.speed.x = 0.0f;
			ball.speed.y = 0.0f;
			ball.active = false;

			// Initialize bricks
			int initialDownPosition = 50.0f;

			for (int i = 0; i < LINES_OF_BRICKS; i++)
			{
				for (int j = 0; j < BRICKS_PER_LINE; j++)
				{
					brick[i][j].position.x = j*brickSize.x + brickSize.x / 2;
					brick[i][j].position.y =  i*brickSize.y + initialDownPosition;
					brick[i][j].active = true;
				}
			}
		}

		void UpdateGame(Ball &ball, Player &player1, Player &player2)
		{
			if (!gameOver)
			{
				if (IsKeyPressed('P')) pause = !pause;

				if (!pause)
				{
					// Player movement logic
					if (IsKeyDown(KEY_LEFT)) player1.position.x -= player1.speed * GetFrameTime();
					if ((player1.position.x - player1.size.x / 2) <= 0) player1.position.x = player1.size.x / 2 ;
					if (IsKeyDown(KEY_RIGHT)) player1.position.x += player1.speed * GetFrameTime();
					if ((player1.position.x + player1.size.x / 2) >= screenWidth) player1.position.x = screenWidth - player1.size.x / 2 ;

					// Ball launching logic
					if (!ball.active)
					{
						if (IsKeyPressed(KEY_SPACE))
						{
							ball.active = true;
							ball.speed =  { 0, -5 };
						}
					}

					// Ball movement logic
					if (ball.active)
					{
						ball.position.x += ball.speed.x* 50 * GetFrameTime();
						ball.position.y += ball.speed.y* 50 * GetFrameTime();
					}
					else
					{
						ball.position.x =  player1.position.x ;
						ball.position.y = screenHeight * 7 / 8 - 30;
					}

					// Collision logic: ball vs walls 
					if (((ball.position.x + ball.radius) >= screenWidth) || ((ball.position.x - ball.radius) <= 0)) ball.speed.x *= -1;
					if ((ball.position.y - ball.radius) <= 0) ball.speed.y *= -1;
					if ((ball.position.y + ball.radius) >= screenHeight)
					{
						ball.speed = { 0, 0 };
						ball.active = false;

						player1.life--;
					}

					// Collision logic: ball vs player
					if (CheckCollisionCircleRec(ball.position, ball.radius,
						{player1.position.x - player1.size.x / 2, player1.position.y - player1.size.y / 2, player1.size.x, player1.size.y}
					))
					{
						if (ball.speed.y > 0)
						{
							ball.speed.y *= -1;
							ball.speed.x = (ball.position.x - player1.position.x) / (player1.size.x / 2) * 5;
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
						if (player1.life <= 0) gameOver = true;
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
					InitGame(ball, player1, player2);
					gameOver = false;
				}
			}
		}

		void UnloadGame()
		{
			// TODO: Unload all dynamic loaded data (textures, sounds, models...)
		}
	
}
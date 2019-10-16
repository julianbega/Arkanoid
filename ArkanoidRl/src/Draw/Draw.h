#ifndef Pantalla_gameplay
#define Pantalla_gameplay

#include "raylib.h"

#include "Objects/Ball/Ball.h"
#include "Objects/Player/Player.h"


namespace RlArkJB
{
	void DrawMenu();
	void DrawGame(Ball &ball, Player &player1, Player &player2);
	void UpdateDrawFrame(Ball &ball, Player &player1, Player &player2);
	void DrawGameOver();

}
#endif

#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "Global/Global.h"

namespace RlArkJB
{


	struct Player {
		Vector2 position;
		Vector2 size;
		int life;
		const int maxLife = 5;
		float speed = 200;
	} ;
		
	void InitPlayer(int posX, int posY, int width, int height, Player &player);
}
#endif
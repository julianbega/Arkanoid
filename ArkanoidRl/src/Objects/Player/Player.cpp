#include "Player.h"

namespace RlArkJB
{

		void InitPlayer(int posX, int posY, int width, int height, Player &player)
		{
			player.position.x = posX;
			player.position.y = posY;
			player.size.x = width;
			player.size.y = height;
			player.life = player.maxLife;
		}

}
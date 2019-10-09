#include "Player.h"

namespace RlArkJB
{
	namespace Paleta
	{

		Player InitPlayer(int posX, int posY, int width, int height)
		{
			Player player;
			player.position.x = posX;
			player.position.y = posY;
			player.size.x = width;
			player.size.y = height;
			player.life = PLAYER_MAX_LIFE;
			return player;
		}

	}
}
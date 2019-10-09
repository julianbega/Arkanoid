#ifndef BALL_H
#define BALL_H

#include <string>

#include "Global/Global.h"
#include "Objects/Player/Player.h"

namespace RlArkJB
{
	typedef struct Ball {
		Vector2 position;
		Vector2 speed;
		int radius;
		bool active;
	} Ball;

	namespace Pelota
	{
		Ball InitPelota(float posX, float posY, float radius);
	}
}
#endif

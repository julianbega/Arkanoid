#ifndef BALL_H
#define BALL_H

#include <string>

#include "Global/Global.h"
#include "Objects/Player/Player.h"

namespace RlArkJB
{
	struct Ball {
		Vector2 position;
		Vector2 speed;
		int radius;
		bool active;
	};

	
		Ball InitBall(float posX, float posY, float radius);
	
}
#endif

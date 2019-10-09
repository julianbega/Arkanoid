#ifndef BRICK_H
#define BRICK_H

#include <string>

#include "Global/Global.h"
#include "Objects/Player/Player.h"

namespace RlArkJB
{
#define LINES_OF_BRICKS         5
#define BRICKS_PER_LINE        20

	typedef struct Brick {
		Vector2 position;
		bool active;
	} Brick;

	namespace Brick
	{
		
	}
}
#endif

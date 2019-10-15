#ifndef BRICK_H
#define BRICK_H

#include <string>

#include "Global/Global.h"
#include "Objects/Player/Player.h"

namespace RlArkJB

{
#define LINES_OF_BRICKS         5
#define BRICKS_PER_LINE        20

	struct Brick {
		Vector2 position;
		bool active;
	};

	extern Brick brick[LINES_OF_BRICKS][BRICKS_PER_LINE];
	extern Vector2 brickSize;
}
#endif

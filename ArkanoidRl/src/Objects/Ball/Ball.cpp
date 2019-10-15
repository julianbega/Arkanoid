#include "Ball.h"
namespace RlArkJB
{
	
		Ball InitBall(float posX, float posY, float radius)
		{
			Ball Pelota;
			Pelota.position.x = posX;
			Pelota.position.y = posY;
			Pelota.radius = radius;
			Pelota.active = true;
			return Pelota;
		}
}
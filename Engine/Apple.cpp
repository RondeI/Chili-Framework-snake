#include <stdlib.h>
#include "Apple.h"
void Apple::draw(Graphics& gfx) const
{
	gfx.drawbox(ax, ay, 16, 255, 0, 0);
}
void Apple::applespawn() {
	//random generated apple spawn
	ax = rand() % 50;
	ax *= 16;
	ay = rand() % 50;
	ay *= 16;
	__appleSpawned = 1;
}
void Apple::applecollision(Snake& snek) {
	//snek touch apple = snek grow and new apple
	if (ax == snek.xvsize() && ay == snek.yvsize()) {
		__appleSpawned = 0;
		snek.addSnakeSize(1);
	}
}
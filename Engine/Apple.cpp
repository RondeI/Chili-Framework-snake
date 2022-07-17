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
}
void Apple::applecollision(Snake& snek) {
	//snek touch apple = snek grow and new apple
	if (ax == snek.xvsize() && ay == snek.yvsize()) {
		__appleSpawned = 0;
		snek.addSnakeSize(1);
	}
}
void Apple::applecolcheck(Snake& snek) {
	bool temp = 0;
	for (int i = 0; i < snek.xvsize() - 1; i++) {
		if (ax==snek.xxget(i) && ay == snek.yyget(i)) {
			temp = 1;
		}
	}
	if(temp==0){
	__appleSpawned = 1;
	}
}
#pragma once
#include "Graphics.h"
#include "Snake.h"
class Apple {
private:
	int ax = 0, ay = 0;
public:
	void applecollision(Snake& snek);
	void applespawn();
	void draw(Graphics& gfx) const;
public: 
	bool __appleSpawned = 0;
};
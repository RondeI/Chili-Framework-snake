#include "Snake.h"
#include "Box.h"
void Snake::velocity()
{
	//updating player position based on direction
	if (dir == "UP") {
		y -= 16;
	}
	else if (dir == "DOWN") {
		y += 16;
	}
	else if (dir == "LEFT") {
		x -= 16;
	}
	else if (dir == "RIGHT") {
		x += 16;
	}
	
}
void Snake::snekcollision(bool& __appleSpawned)
{
	//snek touch snek body = ouchie :(
	for (int i = 0; i < xx.size() - 1; i++) {
		if (xx[xx.size() - 1] == xx[i] && yy[yy.size() - 1] == yy[i]) {
			x = 320;
			y = 320;
			dir = " ";
			maxsize = 5;
			__appleSpawned = 0;
		}
	}
}

void Snake::draw(Graphics& gfx)const
{
	for (int i = 0; i < xx.size(); i++) {
		gfx.drawbox(xx[i], yy[i], 16, 0, 255, 0);
	}
}
void Snake::movement(MainWindow& wnd)
{
	//player 4way movement
	if (wnd.kbd.KeyIsPressed('A') && dir != "RIGHT") {
		dir = "LEFT";
	}
	if (wnd.kbd.KeyIsPressed('D') && dir != "LEFT") {
		dir = "RIGHT";
	}
	if (wnd.kbd.KeyIsPressed('W') && dir != "DOWN") {
		dir = "UP";
	}
	if (wnd.kbd.KeyIsPressed('S') && dir != "UP") {
		dir = "DOWN";
	}
	
}
void Snake::PosUpdate(float& time) {
	if (time > 125.f - maxsize) {
		velocity();
		Box::loopScreen(x,y, 16, 16);
		time = 0.f;
		xx.push_back(x);
		yy.push_back(y);
	}
	LenUpdate();
}
void Snake::LenUpdate() {
	if (xx.size() > maxsize + 1) {
		xx.erase(xx.begin());
		yy.erase(yy.begin());
	}
}
bool Snake::__GameStart() {
	return dir != " ";
}

int Snake::xvsize()
{
	return xx[xx.size() - 1];
}
int Snake::yvsize()
{
	return yy[yy.size() - 1];
}

void Snake::addSnakeSize(int amount)
{
	maxsize += amount;
}

int Snake::xxget(int index) const
{
	return xx[index];
}

int Snake::yyget(int index) const
{
	return yy[index];
}

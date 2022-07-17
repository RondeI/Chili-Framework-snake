#pragma once
#include <vector>
#include <string>
#include "Graphics.h"
#include "MainWindow.h"
#include "Keyboard.h"
class Snake {
public:
	void snekcollision(bool& __appleSpawned);
	void draw(Graphics& gfx) const;
	void movement(MainWindow& wnd);
	void PosUpdate(float& time);
	bool __GameStart();
	int xvsize();
	int yvsize();
	void addSnakeSize(int amount);
	int xxget(int index) const;
	int yyget(int index) const;
private:
	void velocity();
	void LenUpdate();
private:
	std::vector<int> xx;
	std::vector<int> yy;
	int maxsize = 5;
	int x = 320, y = 320;
	std::string dir = " ";
};
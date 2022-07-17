#include "Box.h"
#include "Graphics.h"
void Box::loopScreen(int& x, int& y, int sizex, int sizey) {
	if (x >Graphics::ScreenWidth-3) {
		x = 0;
	}
	if (x < 0) {
		x = Graphics::ScreenWidth-sizex-1;
	}
	if (y > Graphics::ScreenWidth - 3) {
		y = 0;
	}
	if (y < 0) {
		y = Graphics::ScreenHeight - sizey - 1;
	}
}



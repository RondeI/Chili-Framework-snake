/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "Game.h"
#include "MainWindow.h"
Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	srand(time(0));
}

void Game::Go()
{
	dt = clock();
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
	dt = clock() - dt;
	t += dt;
}

void Game::UpdateModel()
{

	snek.movement(wnd);
	snek.PosUpdate(t);
	if (apple.__appleSpawned) {
		apple.applecollision(snek);
	}
	if (snek.__GameStart()) {
		if (!apple.__appleSpawned) {
			apple.applespawn();
			apple.applecolcheck(snek);
		}
		snek.snekcollision(apple.__appleSpawned);
	}
}

void Game::ComposeFrame()
{
	
	//drawing snek
	snek.draw(gfx);
	//drawing apple
	if (snek.__GameStart()) {
		apple.draw(gfx);
	}
}

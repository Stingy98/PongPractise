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
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	paddleP1(30, ((gfx.ScreenHeight) / 2)),
	paddleP2(gfx.ScreenWidth - 30, ((gfx.ScreenHeight) / 2)),
	ball(350,250)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (isGameStart && !isGameOver)
	{
		ball.Update();
		ball.BoundaryCheck(gfx);
		ball.IsColliding(paddleP1);
		ball.IsColliding(paddleP2);
		paddleP2.BoundaryCheck(gfx);
		paddleP2.UpdateP2(wnd);
		paddleP1.BoundaryCheck(gfx);
		paddleP1.UpdateP1(wnd);
	}
}

void Game::ComposeFrame()
{
	if (isGameStart)
	{
		if (ball.GetX() >= 1 && ball.GetX() + ball.GetWidth() <= gfx.ScreenWidth - 1)
		{
			ball.Draw(gfx);
		}
		else
		{
			if (ball.GetX() <= 1)
			{
				score2++;
			}
			else if(ball.GetX() + ball.GetWidth() >= gfx.ScreenWidth - 1)
			{
				score1++;
			}

			ball.Respawn(gfx);
		}

		paddleP1.Draw(gfx);
		paddleP2.Draw(gfx);
	}
	else if (wnd.kbd.KeyIsPressed(VK_RETURN))
	{
		isGameStart = true;
	}

	if (score1 == 5 || score2 == 5)
	{
		isGameOver = true;
	}
}

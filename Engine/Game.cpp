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
	dir(0,0),
	dt(0.0f)
{}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		dir = { -1,0 };
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		dir = { 1,0 };
	}
	else if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		dir = { 0,-1 };
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		dir = { 0,1 };
	}
	else
	{
		dir = { 0,0 };
	}

	dt = ft.Mark();

	while (!wnd.kbd.KeyIsEmpty())
	{
		const auto e = wnd.kbd.ReadKey();
		if (e.IsPress() && e.GetCode() == VK_SPACE)
		{
			link.ActivateEffect();
		}
	}

	link.Update(dt,dir);
}

void Game::ComposeFrame()
{
	//font.Draw({ wnd.mouse.GetPosX(),wnd.mouse.GetPosY() }, "Link\nist\nhier!", gfx);
	font.Draw({ 150,150 }, "Link\nist\nhier!", gfx);
	link.Draw(gfx);
}

#include "Paddle.h"

void Paddle::Update(MainWindow& wnd)
{
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y -= 3;
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y += 3;
	}
}

void Paddle::BoundaryCheck(Graphics& gfx)
{
	if (y <= 1)
	{
		y = 1;
	}
	if (y + height >= gfx.ScreenHeight - 1)
	{
		y = gfx.ScreenHeight - 1 - height;
	}
}

void Paddle::Draw(Graphics& gfx)
{
	for (int i = x; i < x + width; i++)
	{
		for (int j = y; j < y + height; j++)
		{
			gfx.PutPixel(i, j, Colors::White);
		}
	}
}

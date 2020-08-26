#include "Paddle.h"

void Paddle::UpdateP2(Keyboard& kbd)
{
	if (kbd.KeyIsPressed(VK_UP))
	{
		y -= speed;
	}
	else if (kbd.KeyIsPressed(VK_DOWN))
	{
		y += speed;
	}
}

void Paddle::UpdateP1(Keyboard& kbd)
{
	if (kbd.KeyIsPressed('W'))
	{
		y -= speed;
	}
	else if (kbd.KeyIsPressed('S'))
	{
		y += speed;
	}
}

void Paddle::BoundaryCheck(Graphics& gfx)
{
	if (y <= 3)
	{
		y = 3;
	}
	if (y + height >= gfx.ScreenHeight - 3)
	{
		y = gfx.ScreenHeight - 3 - height;
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

int Paddle::GetX()
{
	return x;
}

int Paddle::GetY()
{
	return y;
}

int Paddle::GetWidth()
{
	return width;
}

int Paddle::GetHeight()
{
	return height;
}

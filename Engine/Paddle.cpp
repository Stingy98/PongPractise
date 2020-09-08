#include "Paddle.h"

void Paddle::UpdateP2(Keyboard& kbd)
{
	if (kbd.KeyIsPressed(VK_UP))
	{
		paddlePos.y -= speed;
	}
	else if (kbd.KeyIsPressed(VK_DOWN))
	{
		paddlePos.y += speed;
	}
}

void Paddle::UpdateP1(Keyboard& kbd)
{
	if (kbd.KeyIsPressed('W'))
	{
		paddlePos.y -= speed;
	}
	else if (kbd.KeyIsPressed('S'))
	{
		paddlePos.y += speed;
	}
}

void Paddle::BoundaryCheck(Graphics& gfx)
{
	if (paddlePos.y <= 3)
	{
		paddlePos.y = 3;
	}
	if (paddlePos.y + height >= gfx.ScreenHeight - 3)
	{
		paddlePos.y = gfx.ScreenHeight - 3 - height;
	}
}

void Paddle::Draw(Graphics& gfx)
{
	for (int i = paddlePos.x; i < paddlePos.x + width; i++)
	{
		for (int j = paddlePos.y; j < paddlePos.y + height; j++)
		{
			gfx.PutPixel(i, j, Colors::White);
		}
	}
}

Vec2 Paddle::GetPos() const
{
	return paddlePos;
}

int Paddle::GetWidth() const
{
	return width;
}

int Paddle::GetHeight() const
{
	return height;
}

#include "Ball.h"

void Ball::Update()
{
	x += vx;
	y += vy;
}

void Ball::Draw(Graphics& gfx)
{
	for (int i = x; i < x + width; i++)
	{
		for (int j = y; j < y + height; j++)
		{
			gfx.PutPixel(i, j, Colors::Green);
		}
	}
	
}

void Ball::IsColliding(Paddle& paddle)
{
	if ((x == paddle.GetX() + paddle.GetWidth() && y > paddle.GetY() && y < paddle.GetY() + paddle.GetHeight())
		|| x + width == paddle.GetX() && y > paddle.GetY() && y < paddle.GetY() + paddle.GetHeight())
	{
		vx = -vx;
	}
}

void Ball::BoundaryCheck(Graphics& gfx)
{
	if (y + height >= gfx.ScreenHeight -1 || y <= 1)
	{
		vy = -vy;
	}

	//if (x + width >= gfx.ScreenWidth - 1 || x <= 1)
	//{
	//	vx = -vx;
	//}
}

void Ball::Respawn(Graphics& gfx)
{
	x = 350;
	y = 250;
	vx = 2;
	vy = 2;
	Draw(gfx);
}

int Ball::GetX()
{
	return x;
}

int Ball::GetWidth()
{
	return width;
}

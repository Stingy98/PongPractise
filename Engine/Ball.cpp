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


void Ball::IsColliding()
{

}

void Ball::BoundaryCheck(Graphics& gfx)
{
	if (y + height >= gfx.ScreenHeight -1 || y <= 1)
	{
		vy = -vy;
	}

	if (x + width >= gfx.ScreenWidth - 1 || x <= 1)
	{
		vx = -vx;
	}
}

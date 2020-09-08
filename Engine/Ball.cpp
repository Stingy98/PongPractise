#include "Ball.h"

void Ball::Update()
{
	ballPos.x += ballVel.x;
	ballPos.y += ballVel.y;
}

void Ball::Draw(Graphics& gfx)
{
	for (int i = ballPos.x; i < ballPos.x + width; i++)
	{
		for (int j = ballPos.y; j < ballPos.y + height; j++)
		{
			gfx.PutPixel(i, j, Colors::Green);
		}
	}

}

void Ball::IsColliding(Paddle& paddle)
{
	if ((ballPos.x == paddle.GetPos().x + paddle.GetWidth() &&
		ballPos.y > paddle.GetPos().y &&
		ballPos.y < paddle.GetPos().y + paddle.GetHeight()))
	{
		ballVel.x = -ballVel.x;
	}

	if (ballPos.x + width == paddle.GetPos().x &&
		ballPos.y > paddle.GetPos().y &&
		ballPos.y < paddle.GetPos().y + paddle.GetHeight())
	{
		ballVel.x = -ballVel.x;
	}
}

void Ball::BoundaryCheck(Graphics& gfx)
{
	if (ballPos.y + height >= gfx.ScreenHeight -1 || ballPos.y <= 1)
	{
		ballVel.y = -ballVel.y;
	}

	//if (x + width >= gfx.ScreenWidth - 1 || x <= 1)
	//{
	//	vx = -vx;
	//}
}

Vec2 Ball::GetPos() const
{
	return ballPos;
}

void Ball::Respawn(Graphics& gfx)
{
	ballPos.x = 350;
	ballPos.y = 250;
	ballVel.x = 2;
	ballVel.y = 2;
	Draw(gfx);
}


int Ball::GetWidth() const
{
	return width;
}

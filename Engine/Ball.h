#pragma once
#include "Graphics.h"
#include "Paddle.h"

class Ball
{
public:
	Ball(int x_pos, int y_pos)
		:
		x(x_pos),
		y(y_pos)
	{
	}

	void Update();
	void Draw(Graphics& gfx);
	void IsColliding(Paddle& paddle);
	void BoundaryCheck(Graphics& gfx);
	int GetX();
	int GetWidth();
	void Respawn(Graphics& gfx);

private:
	int x;
	int y;
	static constexpr int height = 10;
	static constexpr int width = 10;
	int vx = 2;
	int vy = 2;
};
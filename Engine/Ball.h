#pragma once
#include "Graphics.h"
#include "Paddle.h"
#include "Vec2.h"

class Ball
{
public:
	Ball(const Vec2& ballPos_in, const Vec2& ballVel_in)
		:
		ballPos(ballPos_in),
		ballVel(ballVel_in)
	{
	}

	void Update();
	void Draw(Graphics& gfx);
	void IsColliding(Paddle& paddle);
	void BoundaryCheck(Graphics& gfx);
	Vec2 GetPos() const;
	int GetWidth() const;
	void Respawn(Graphics& gfx);

private:
	Vec2 ballPos;
	Vec2 ballVel;
	static constexpr int height = 10;
	static constexpr int width = 10;
};
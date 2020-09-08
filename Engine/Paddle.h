#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Vec2.h"

class Paddle
{
public:
	Paddle(const Vec2& paddlePos_in)
		:
		paddlePos(paddlePos_in)
	{
	}

	void UpdateP1(Keyboard& kbd);
	void UpdateP2(Keyboard& kbd);
	void BoundaryCheck(Graphics& gfx);
	void Draw(Graphics& gfx);
	Vec2 GetPos() const;
	int GetWidth() const;
	int GetHeight() const;

private:
	Vec2 paddlePos;
	static constexpr int width = 10;
	static constexpr int height = 60;
	static constexpr int speed = 3;
};
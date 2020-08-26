#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class Paddle
{
public:
	Paddle(int x_pos, int y_pos)
		:
		x(x_pos),
		y(y_pos)	
	{
	}

	void UpdateP1(Keyboard& kbd);
	void UpdateP2(Keyboard& kbd);
	void BoundaryCheck(Graphics& gfx);
	void Draw(Graphics& gfx);
	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();

private:
	int x;
	int y;
	static constexpr int width = 10;
	static constexpr int height = 60;
	static constexpr int speed = 3;
};
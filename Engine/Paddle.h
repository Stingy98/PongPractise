#pragma once
#include "Graphics.h"
#include "MainWindow.h"

class Paddle
{
public:
	Paddle(int x_pos, int y_pos)
		:
		x(x_pos),
		y(y_pos)	
	{
	}

	void UpdateP1(MainWindow& wnd);
	void UpdateP2(MainWindow& wnd);
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
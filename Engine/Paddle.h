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

	void Update(MainWindow& wnd);
	void BoundaryCheck(Graphics& gfx);
	void Draw(Graphics& gfx);

private:
	int x;
	int y;
	static constexpr int width = 10;
	static constexpr int height = 60;
};
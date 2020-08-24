#pragma once

class Paddle
{
public:
	Paddle(int x_pos, int y_pos)
		:
		x(x_pos),
		y(y_pos)	
	{
	}

	void Update();
	void BoundaryCheck();
	void Draw();

private:
	int x;
	int y;
	static constexpr int width = 4;
	static constexpr int height = 40;
};
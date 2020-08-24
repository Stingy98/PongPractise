#pragma once

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
	void Draw();
	void IsColliding();
	void BoundaryCheck();

private:
	int x;
	int y;
	static constexpr int height = 10;
	static constexpr int width = 10;
};
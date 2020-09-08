#include "Vec2.h"
#include <cmath>

Vec2::Vec2(float in_x, float in_y)
	:
	x(in_x),
	y(in_y)
{
}

Vec2 Vec2::operator+(const Vec2& rhs) const
{
	return Vec2(x + rhs.x, y + rhs.y);
}

Vec2& Vec2::operator+=(const Vec2& rhs)
{
	return *this = *this + rhs;
}

Vec2 Vec2::operator-(const Vec2& rhs) const
{
	return Vec2(x - rhs.x, y - rhs.y);
}

Vec2& Vec2::operator-=(const Vec2& rhs)
{
	return *this = *this - rhs;
}

Vec2 Vec2::operator*(float rhs) const
{
	return Vec2(x * rhs, y * rhs);
}

Vec2& Vec2::operator*=(float rhs)
{
	return *this = *this * rhs;
}

float Vec2::GetLength() const
{
	return std::sqrt(GetLengthSq());
}

float Vec2::GetLengthSq() const
{
	return x * x + y * y;
}

Vec2& Vec2::Normalise()
{
	return *this = GetNormalised();
}

Vec2 Vec2::GetNormalised() const
{
	const float len = GetLength();

	if (len != 0.0f)
	{
		return *this * (1.0f / len);
	}
	return *this;	
}

#pragma once
#include "Vec2.h"

class RectF
{
public:
	RectF() = default;
	RectF(float top, float bottom, float left, float right);
	RectF(const Vec2& position, float width, float height);

	float top;
	float bottom;
	float left;
	float right;

	bool overlaps(const RectF rect) const;
};


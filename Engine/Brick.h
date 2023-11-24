#pragma once
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"

class Brick
{
public:
	Brick() = default;
	Brick(const RectF& rect, const Color& color);

	static constexpr int WIDTH = 75;
	static constexpr int HEIGHT = 25;

	RectF collisionBox;
	Color color;
	bool destroyed = false;

	void update();
	void draw(Graphics& gfx);
};


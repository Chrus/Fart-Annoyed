#include "Brick.h"

Brick::Brick(const RectF& rect, const Color& color)
	:
	collisionBox(rect),
	color(color)
{
}

void Brick::update()
{
}

void Brick::draw(Graphics& gfx)
{
	if (destroyed)
		return;

	for (int x = 0; x < Brick::WIDTH; x++)
	{
		for (int y = 0; y < Brick::HEIGHT; y++)
		{
			gfx.PutPixel(x + collisionBox.left, y + collisionBox.top, color);
		}
	}
}

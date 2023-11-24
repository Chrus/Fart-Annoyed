#include "RectF.h"
#include "assert.h"

/// <summary>
/// </summary>
/// <param name="top">: The Rectangle's top most value</param>
/// <param name="bottom">: The Rectangle's bottom most value</param>
/// <param name="left">: The Rectangle's left most value</param>
/// <param name="right">: The Rectangle's right most value</param>
RectF::RectF(float top, float bottom, float left, float right)
	:
	top(top), 
	bottom(bottom), 
	left(left), 
	right(right)
{
}

/// <summary>
/// </summary>
/// <param name="position">: The top left location of the Rectangle</param>
/// <param name="width">: The Rectangle's width</param>
/// <param name="height">: The Rectangle's height</param>
RectF::RectF(const Vec2& position, float width, float height)
	:
	RectF(position.y, position.y + height, position.x, position.x + width)
{
}

/// <summary>
/// Checks if two RectF objects intersects
/// </summary>
/// <param name="rect">The RectF to check against this</param>
/// <returns></returns>
bool RectF::overlaps(const RectF rect) const
{
	return right > rect.left && left < rect.right
		&& bottom > rect.top && top < rect.bottom;
}

float RectF::width() const
{
	assert(right < left);

	return right - left;
}

float RectF::height() const
{
	assert(bottom < top);

	return bottom - top;
}

#include "Ball.h"

Ball::Ball(Vec2& position)
	:
	position(position),
	velocity(Vec2(5, -5))
{
}

void Ball::update(const float delta)
{
	position += velocity * delta;

	checkBorderCollision();
}

void Ball::draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(Vec2(position.x + RADIUS, position.y + RADIUS), gfx);
}

RectF& Ball::getRect() const
{
	return RectF(position, RADIUS * 2, RADIUS * 2);
}

float Ball::getWidth() const
{
	return RADIUS * 2;
}

float Ball::getHeight() const
{
	return RADIUS * 2;
}

bool Ball::checkBorderCollision()
{
	RectF rect = getRect();
	bool wasCollision = false;

	if (rect.left < 0)
	{
		velocity.x *= -1;
		position.x = 0;
		wasCollision = true;
	}
	else if (rect.right > Graphics::ScreenWidth)
	{
		velocity.x *= -1;
		position.x = Graphics::ScreenWidth - getWidth();
		wasCollision = true;
	}

	if (rect.top < 0)
	{
		velocity.y *= -1;
		position.y = 0;
		wasCollision = true;
	}
	else if (rect.bottom > Graphics::ScreenHeight)
	{
		velocity.y *= -1;
		position.y = Graphics::ScreenHeight - getHeight();
		wasCollision = true;
	}

	return wasCollision;
}

#pragma once
#include "Vec2.h"
#include "RectF.h"
#include "Graphics.h"
#include "SpriteCodex.h"

class Ball
{
public:
	Ball() = default;
	Ball(Vec2& position);

	static constexpr float RADIUS = 7.0f;

	Vec2 position;
	Vec2 velocity;

	void update(const float delta);
	void draw(Graphics& gfx) const;
	RectF& getRect() const;
	float getWidth() const;
	float getHeight() const;

private:
	bool checkBorderCollision();
};


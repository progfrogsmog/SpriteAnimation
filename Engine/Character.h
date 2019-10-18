#pragma once
#include "Animation.h"
#include "Vec2.h"

class Character
{
private:
	enum AniState
	{
		WalkingLeft,
		WalkingRight,
		WalkingUp,
		WalkingDown,
		StandingLeft,
		StandingRight,
		StandingUp,
		StandingDown,
		Count
	};
public:
	Character(Vec2 pos, int x, int y, int spriteWidth, int spriteHeight, int amountFrames, const Surface& sprite);
	void Draw(Graphics& gfx);
	void Update(float dt, Vei2 dir);
	void ActivateEffect();
private:
	const Surface& sprite;
	AniState state = AniState::StandingDown;
	std::vector<Animation> animation;
	Vec2 pos;
	Vei2 dir = {0,1};
	float speed = 123.0f;
	float effectTime = 0.0f;
	static constexpr float effectDuration = 0.1f;
	bool isActiveEffect = false;
};
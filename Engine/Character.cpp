#include "Character.h"

Character::Character(Vec2 pos, int x, int y, int spriteWidth, int spriteHeight, int amountFrames, const Surface& sprite)
	:
	sprite(sprite),
	pos(pos)
{
	for (int i = AniState::WalkingLeft; i < AniState::StandingLeft; i++)
	{
		animation.emplace_back(x, y + spriteHeight * i, spriteWidth, spriteHeight, amountFrames, sprite);
	}
	for (int i = AniState::StandingLeft; i < AniState::Count; i++)
	{
		animation.emplace_back(0 , y + spriteHeight * (i-AniState::StandingLeft), spriteWidth, spriteHeight, 1, sprite);
	}
}

void Character::Draw(Graphics& gfx)
{
	if (isActiveEffect)
	{
		animation[int(state)].DrawMono(int(pos.x), int(pos.y), Colors::Red, gfx);
	}
	else
	{
		animation[int(state)].Draw(int(pos.x), int(pos.y), gfx, 0.5f);
	}
}

void Character::Update(float dt, Vei2 dir)
{
	animation[int(state)].Update(dt);
	
	if (dir.x == -1)
	{
		state = AniState::WalkingLeft;
	}
	else if (dir.x == 1)
	{
		state = AniState::WalkingRight;
	}
	else if (dir.y == -1)
	{
		state = AniState::WalkingUp;
	}
	else if (dir.y == 1)
	{
		state = AniState::WalkingDown;
	}
	else //IF ALL KEYS RELEASED
	{
		if (this->dir.x == -1)
		{
			state = AniState::StandingLeft;
		}
		else if (this->dir.x == 1)
		{
			state = AniState::StandingRight;
		}
		else if (this->dir.y == -1)
		{
			state = AniState::StandingUp;
		}
		else if (this->dir.y == 1)
		{
			state = AniState::StandingDown;
		}
	}
		this->dir = dir;
		pos.x += float(dir.x) * speed * dt;
		pos.y += float(dir.y) * speed * dt;

		effectTime += dt;
		if (effectTime >= effectDuration)
		{
			isActiveEffect = false;
		}
}

void Character::ActivateEffect()
{
	isActiveEffect = true;
	effectTime = 0.0f;
}
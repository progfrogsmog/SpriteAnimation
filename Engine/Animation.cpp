#include "Animation.h"
#include "SpriteEffect.h"

Animation::Animation(int x, int y, int width, int height, int amountFrames, const Surface& s)
	:
	sprite(s)
{
	frames.reserve(amountFrames);
	for (int i = 0; i < amountFrames; i++)
	{
		frames.emplace_back(x + width * i, x + width * (i + 1), y, y + height);
	}
}

void Animation::Draw(int x, int y, Graphics& gfx, float magnitude)
{
	gfx.DrawSprite(x, y, frames[curFrame], sprite, SpriteEffect::Ghost{ Colors::Magenta });
}

void Animation::DrawMono(int x, int y, Color mono, Graphics& gfx)
{
	gfx.DrawSprite(x, y, frames[curFrame], sprite, SpriteEffect::Substitution{ Colors::Magenta, Colors::Red });
}

void Animation::Update(float dt)
{
	elapsedTime += dt;
	if (elapsedTime >= holdtime)
	{
		elapsedTime -= holdtime;
		Advance();
	}
}

void Animation::Advance()
{
	if (++curFrame >= frames.size())
	{
		curFrame = 0;
	}
}

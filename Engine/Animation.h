#pragma once
#include "Surface.h"
#include "Graphics.h"
#include <vector>

class Animation
{
public:
	Animation(int x, int y, int width, int height, int amountFrames, const Surface& s);
	void Draw(int x, int y, Graphics& gfx, float magnitude = 1.0);
	void DrawMono(int x, int y, Color mono, Graphics& gfx);
	void Update(float dt);
private:
	void Advance();
private:
	const Surface& sprite;
	std::vector<RectI> frames;
	float holdtime = 0.16f;
	float elapsedTime = 0.0f;
	int curFrame = 0;
};
#pragma once
#include "Surface.h"
#include "Graphics.h"
#include <vector>

class Font
{
public:
	Font(int width, int height, const Surface& surface);
	void Draw(const Vei2& pos, std::string str, Graphics& gfx);
private:
private:
	const Surface& font;
	std::vector<RectI> character;
};
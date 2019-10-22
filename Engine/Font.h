#pragma once
#include "Surface.h"
#include "Graphics.h"
#include <vector>

class Font
{
public:
	Font(int widthGlyph, int heightGlyph, const Surface& surface);
	void Draw(const Vei2& pos, std::string str, Graphics& gfx);
private:
private:
	int widthGlyph;
	int heightGlyph;
	const Surface& font;
	std::vector<RectI> character;
};
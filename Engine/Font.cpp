#include "Font.h"
#include "SpriteEffect.h"

Font::Font(int widthGlyph, int heightGlyph, const Surface& surface)
	:
	font(surface),
	widthGlyph(widthGlyph),
	heightGlyph(heightGlyph)
{
	character.reserve((surface.GetHeight() / heightGlyph) * (surface.GetWidth() / widthGlyph));
	for (int i = 0; i < surface.GetHeight() / heightGlyph; i++)
	{
		for (int j = 0; j < surface.GetWidth() / widthGlyph; j++)
		{
			character.emplace_back(j * widthGlyph, (j + 1) * widthGlyph, i * heightGlyph, (i + 1) * heightGlyph);
		}
	}
}

void Font::Draw(const Vei2& pos, std::string str, Graphics& gfx)
{
	int enter = 0;
	int next = 0;
	for (int i = 0; i < str.length(); i++)
	{
		int charPos = str[i] - ' ';
		if (str[i] == '\n')
		{
			enter++;
			next = 0;
			continue;
		}
		gfx.DrawSprite(pos.x+(next* widthGlyph), pos.y+(enter*heightGlyph), character[charPos], font, SpriteEffect::Substitution{ Colors::White, Colors::Yellow });
		next++;
	}
}
#include "Font.h"

Font::Font(int width, int height, const Surface& surface)
	:
	font(surface)
{
	character.reserve((surface.GetHeight() / height) * (surface.GetWidth() / width));
	for (int i = 0; i < surface.GetHeight() / height; i++)
	{
		for (int j = 0; j < surface.GetWidth() / width; j++)
		{
			character.emplace_back(j * width, (j + 1) * width, i * height, (i + 1) * height);
		}
	}
}

void Font::Draw(const Vei2& pos, std::string str ,Graphics& gfx)
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
		gfx.DrawSpriteMono(pos.x+(next*16), pos.y+(enter*28), character[charPos], font, Colors::Yellow, Colors::White);
		next++;
	}
}
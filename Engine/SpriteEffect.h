#pragma once
#include "Graphics.h"
#include "Colors.h"
//...
namespace SpriteEffect
{
	class Chroma
	{
	public:
		Chroma(Color chroma)
			:
			chroma(chroma)
		{}
		void operator() ( Color src, int xDest, int yDest, Graphics& gfx) const
		{
			if (src != chroma)
			{
				gfx.PutPixel(xDest, yDest, src);
			}
		}
	private:
		Color chroma;
	};

	class Substitution
	{
	public:
		Substitution(Color c, Color s)
			:
			chroma(c),
			sub(s)
		{}
		void operator() (const Color& src, int xDist, int yDist, Graphics& gfx)
		{
			if (src != chroma)
			{
				gfx.PutPixel(xDist, yDist, sub);
			}
		}
	private:
		Color chroma;
		Color sub;
	};

	class Copy
	{
	public:
		void operator() (const Color& src, int xDist, int yDist, Graphics& gfx)
		{
			gfx.PutPixel(xDist, yDist, src);
		}
	};

	class Ghost
	{
	public:
		Ghost(Color c)
			:
			chroma(c)
		{}
		void operator() (const Color& src, int xDist, int yDist, Graphics& gfx)
		{
			if (src != chroma)
			{
				Color col = Colors::CalcAverage(gfx.GetScreenPixel(xDist, yDist), src, 0.5f);
				gfx.PutPixel(xDist, yDist, col);
			}
		}
	private:
		Color chroma;
	};
}
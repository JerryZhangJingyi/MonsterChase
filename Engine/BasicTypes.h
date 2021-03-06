#pragma once

#include <stdint.h>

namespace GLib
{
	struct Point2D
	{
		float			x;
		float			y;
	};

	struct UV
	{
		float			u, v;
	};

	struct RGBA
	{
		uint8_t			r, g, b, a;
	};

	typedef struct _SpriteEdges
	{
		float			Left;
		float			Top;
		float			Right;
		float			Bottom;
	} SpriteEdges;

	typedef struct _SpriteUVs
	{
		UV				TopLeft;
		UV				TopRight;
		UV				BottomLeft;
		UV				BottomRight;
	} SpriteUVs;
} // namespace GLib
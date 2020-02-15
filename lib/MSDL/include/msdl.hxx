#ifndef MSDL_BASE_H
#define MSDL_BASE_H

#include <SDL.h>

namespace MSDL
{

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
static constexpr unsigned int RMASK = 0xff000000u;
static constexpr unsigned int GMASK = 0x00ff0000u;
static constexpr unsigned int BMASK = 0x0000ff00u;
static constexpr unsigned int AMASK = 0x000000ffu;
#else
static constexpr unsigned int RMASK = 0x000000ffu;
static constexpr unsigned int GMASK = 0x0000ff00u;
static constexpr unsigned int BMASK = 0x00ff0000u;
static constexpr unsigned int AMASK = 0xff000000u;
#endif

enum class ColorDepth : int
{
	RGB = 24,
	RGBA = 32
};

}  // namespace MSDL

#endif

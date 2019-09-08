#ifndef MSDL_SURFACE_H
#define MSDL_SURFACE_H

#include <SDL.h>

#include <string>
using std::string;

#include "msdl_export.h"

struct MSDL_SurfaceDeleter
{
	void operator()(SDL_Surface * s)
	{
		SDL_FreeSurface(s);
	}
};

class MSDL_Surface
{
public:
	MSDL_EXPORT MSDL_Surface();
	MSDL_EXPORT virtual ~MSDL_Surface();
	MSDL_EXPORT MSDL_Surface(SDL_Surface * surface, bool dedicated = false);
	MSDL_EXPORT MSDL_Surface(const MSDL_Surface & copy);
	MSDL_EXPORT MSDL_Surface(MSDL_Surface && move);
	MSDL_EXPORT MSDL_Surface & operator=(const MSDL_Surface & copy);
	MSDL_EXPORT MSDL_Surface & operator=(MSDL_Surface && move);

	MSDL_EXPORT bool fill_rect(SDL_Rect * rect, Uint8 r, Uint8 g, Uint8 b);
	MSDL_EXPORT bool load_bmp(string file);
	MSDL_EXPORT bool blit_from(const MSDL_Surface & source, const SDL_Rect * src_rect, SDL_Rect * dst_rect);
	MSDL_EXPORT bool blit_from(string file, const SDL_Rect * src_rect, SDL_Rect * dst_rect);

	MSDL_EXPORT SDL_PixelFormat * get_format();

	MSDL_EXPORT void reset(SDL_Surface * surface = nullptr);
	MSDL_EXPORT bool is_empty();

protected:
	std::unique_ptr<SDL_Surface, MSDL_SurfaceDeleter> _surface;
	bool _dedicated;  // Whether or not the instance is dedicated to an SDL_Window.
};

#endif

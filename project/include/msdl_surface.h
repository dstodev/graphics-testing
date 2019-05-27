#ifndef MSDL_SURFACE_H
#define MSDL_SURFACE_H

#include <SDL.h>

#include <string>
using std::string;

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
	MSDL_Surface();
	virtual ~MSDL_Surface();
	MSDL_Surface(SDL_Surface * surface, bool dedicated = false);
	MSDL_Surface(const MSDL_Surface & copy);
	MSDL_Surface(MSDL_Surface && move);
	MSDL_Surface & operator=(const MSDL_Surface & copy);
	MSDL_Surface & operator=(MSDL_Surface && move);

	bool fill_rect(SDL_Rect * rect, Uint32 color);
	bool load_bmp(const string & file);
	bool blit_from(const MSDL_Surface & source, const SDL_Rect * src_rect, SDL_Rect * dst_rect);

	SDL_PixelFormat * get_format();

	void reset(SDL_Surface * surface);
	bool is_empty();

protected:
	std::unique_ptr<SDL_Surface, MSDL_SurfaceDeleter> _surface;
	bool _dedicated;  // Whether or not the instance is dedicated to an SDL_Window.
};

#endif

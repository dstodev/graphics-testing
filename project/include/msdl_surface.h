#ifndef MSDL_SURFACE_H
#define MSDL_SURFACE_H

#include <string>
using std::string;

#include <SDL.h>

class MSDL_Surface
{
public:
	MSDL_Surface();
	virtual ~MSDL_Surface();
	MSDL_Surface(SDL_Surface * surface);
	MSDL_Surface(const MSDL_Surface & copy);
	MSDL_Surface & operator=(const MSDL_Surface & copy);

	operator bool() const;

	bool fill_rect(SDL_Rect * rect, Uint32 color);
	bool load_bmp(const string & file);
	bool blit_from(const MSDL_Surface & source, const SDL_Rect * src_rect, SDL_Rect * dst_rect);

	SDL_PixelFormat * get_format();

protected:
	virtual void clear_surface();

	SDL_Surface * _surface;

private:
	void copy_surface(SDL_Surface * surface);
};

#endif

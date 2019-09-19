/*
        2019 Daniel Stotts
 */

#ifndef MSDL_SURFACE_H
#define MSDL_SURFACE_H

#include <SDL.h>

#include <memory>
#include <string>

#include "msdl_export.h"

extern void MSDL_SurfaceDeleter(SDL_Surface * surface);

class MSDL_Surface
{
public:
	MSDL_EXPORT MSDL_Surface();
	MSDL_EXPORT virtual ~MSDL_Surface();
	MSDL_EXPORT MSDL_Surface(SDL_Surface * surface);
	MSDL_EXPORT MSDL_Surface(const MSDL_Surface & copy);
	MSDL_EXPORT MSDL_Surface & operator=(MSDL_Surface other);

	MSDL_EXPORT friend void swap(MSDL_Surface & lhs, MSDL_Surface & rhs);

	MSDL_EXPORT bool fill_rect(SDL_Rect * rect, Uint8 r, Uint8 g, Uint8 b);
	MSDL_EXPORT bool load_bmp(std::string file);
	MSDL_EXPORT bool blit_from(const MSDL_Surface & source, const SDL_Rect * src_rect, SDL_Rect * dst_rect);
	MSDL_EXPORT bool blit_from(std::string file, const SDL_Rect * src_rect, SDL_Rect * dst_rect);

	MSDL_EXPORT SDL_PixelFormat * get_format();

	MSDL_EXPORT void reset(SDL_Surface * surface = nullptr);
	MSDL_EXPORT bool is_empty();

protected:
	std::shared_ptr<SDL_Surface> _surface;
};

#endif

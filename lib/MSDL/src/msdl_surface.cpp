/*
        2019 Daniel Stotts
 */

#include "msdl_surface.h"

using std::string;

#include <algorithm>

void MSDL_SurfaceDeleter(SDL_Surface * surface)
{
	SDL_FreeSurface(surface);
}

MSDL_Surface::MSDL_Surface() : _surface(nullptr, MSDL_SurfaceDeleter)
{}

MSDL_Surface::MSDL_Surface(SDL_Surface * surface) : _surface(surface, MSDL_SurfaceDeleter)
{}

MSDL_Surface::~MSDL_Surface()
{}

MSDL_Surface::MSDL_Surface(const MSDL_Surface & copy)
{
	_surface = copy._surface;
	// SDL_Surface * surface = copy._surface.get();
	// reset(SDL_ConvertSurface(surface, surface->format, 0));
}

MSDL_Surface & MSDL_Surface::operator=(MSDL_Surface other)
{
	swap(*this, other);
	return *this;
}

void swap(MSDL_Surface & lhs, MSDL_Surface & rhs)
{
	using std::swap;
	swap(lhs._surface, rhs._surface);
}

bool MSDL_Surface::fill_rect(SDL_Rect * rect, Uint8 r, Uint8 g, Uint8 b)
{
	return (SDL_FillRect(_surface.get(), rect, SDL_MapRGB(get_format(), r, g, b)) == 0);
}

bool MSDL_Surface::load_bmp(string file)
{
	reset(SDL_LoadBMP(file.c_str()));
	return !is_empty();
}

bool MSDL_Surface::blit_from(const MSDL_Surface & source, const SDL_Rect * src_rect, SDL_Rect * dst_rect)
{
	return (SDL_BlitSurface(source._surface.get(), src_rect, _surface.get(), dst_rect) == 0);
}

bool MSDL_Surface::blit_from(string file, const SDL_Rect * src_rect, SDL_Rect * dst_rect)
{
	SDL_Surface * source = SDL_LoadBMP(file.c_str());
	return (SDL_BlitSurface(source, src_rect, _surface.get(), dst_rect) == 0);
}

SDL_PixelFormat * MSDL_Surface::get_format()
{
	SDL_PixelFormat * format = nullptr;
	if (_surface) {
		format = _surface->format;
	}
	return format;
}

void MSDL_Surface::reset(SDL_Surface * surface)
{
	_surface.reset(surface, MSDL_SurfaceDeleter);
}

bool MSDL_Surface::is_empty()
{
	return (_surface == nullptr);
}

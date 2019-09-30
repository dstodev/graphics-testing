/*
        2019 Daniel Stotts
 */

#include "msdl_surface.h"

#include <string>
using std::string;

#include <algorithm>

namespace MSDL
{

void SurfaceDeleter(SDL_Surface * surface)
{
	SDL_FreeSurface(surface);
}

void NopDeleter(SDL_Surface * surface)
{}

Surface::Surface() : _surface(nullptr, SurfaceDeleter)
{}

Surface::Surface(SDL_Surface * surface, void (*deleter)(SDL_Surface *)) : _surface(surface, deleter)
{}

Surface::~Surface()
{}

Surface::Surface(const Surface & copy)
{
	_surface = copy._surface;
	// SDL_Surface * surface = copy._surface.get();
	// reset(SDL_ConvertSurface(surface, surface->format, 0));
}

Surface & Surface::operator=(Surface other)
{
	swap(*this, other);
	return *this;
}

void swap(Surface & lhs, Surface & rhs)
{
	using std::swap;
	swap(lhs._surface, rhs._surface);
}

bool Surface::fill_rect(SDL_Rect * rect, Uint8 r, Uint8 g, Uint8 b)
{
	return (SDL_FillRect(_surface.get(), rect, SDL_MapRGB(get_format(), r, g, b)) == 0);
}

bool Surface::load_bmp(string file)
{
	reset(SDL_LoadBMP(file.c_str()));
	return !is_empty();
}

bool Surface::blit_from(const Surface & source, const SDL_Rect * src_rect, SDL_Rect * dst_rect)
{
	return (SDL_BlitSurface(source._surface.get(), src_rect, _surface.get(), dst_rect) == 0);
}

bool Surface::blit_from(string file, const SDL_Rect * src_rect, SDL_Rect * dst_rect)
{
	SDL_Surface * source = SDL_LoadBMP(file.c_str());
	return (SDL_BlitSurface(source, src_rect, _surface.get(), dst_rect) == 0);
}

SDL_PixelFormat * Surface::get_format()
{
	SDL_PixelFormat * format = nullptr;
	if (_surface) {
		format = _surface->format;
	}
	return format;
}

void Surface::reset(SDL_Surface * surface)
{
	_surface.reset(surface, SurfaceDeleter);
}

bool Surface::is_empty()
{
	return (_surface == nullptr);
}

}  // namespace MSDL

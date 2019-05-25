#include "msdl_surface.h"

MSDL_Surface::MSDL_Surface() : _surface(nullptr)
{}

MSDL_Surface::MSDL_Surface(SDL_Surface * surface) : _surface(surface)
{}

MSDL_Surface::~MSDL_Surface()
{
	clear_surface();
}

MSDL_Surface::MSDL_Surface(const MSDL_Surface & copy)
{
	copy_surface(copy._surface);
}

MSDL_Surface & MSDL_Surface::operator=(const MSDL_Surface & copy)
{
	copy_surface(copy._surface);
	return *this;
}

MSDL_Surface::operator bool() const
{
	return _surface != nullptr;
}

void MSDL_Surface::clear_surface()
{
	SDL_FreeSurface(_surface);  // It is safe to pass nullptr to SDL_FreeSurface().
	_surface = nullptr;
}

void MSDL_Surface::copy_surface(SDL_Surface * surface)
{
	_surface = SDL_ConvertSurface(surface, surface->format, 0);
}

bool MSDL_Surface::fill_rect(SDL_Rect * rect, Uint32 color)
{
	return SDL_FillRect(_surface, rect, color) == 0;
}

bool MSDL_Surface::load_bmp(const string & file)
{
	// TODO: Cast this object into MSDL_Surface if it's a MSDL_WindowSurface.

	clear_surface();
	_surface = SDL_LoadBMP(file.c_str());

	return static_cast<bool>(*this);
}

bool MSDL_Surface::blit_from(const MSDL_Surface & source, const SDL_Rect * src_rect, SDL_Rect * dst_rect)
{
	return SDL_BlitSurface(source._surface, src_rect, _surface, dst_rect) == 0;
}

SDL_PixelFormat * MSDL_Surface::get_format()
{
	SDL_PixelFormat * format = nullptr;
	if (_surface) {
		format = _surface->format;
	}
	return format;
}

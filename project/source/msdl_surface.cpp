#include "msdl_surface.h"

#include <memory>
using std::make_unique;
using std::unique_ptr;

MSDL_Surface::MSDL_Surface() : _surface(nullptr)
{}

MSDL_Surface::MSDL_Surface(SDL_Surface * surface, bool dedicated) : _surface(surface), _dedicated(dedicated)
{}

MSDL_Surface::~MSDL_Surface()
{}

MSDL_Surface::MSDL_Surface(const MSDL_Surface & copy) : _surface(nullptr)
{
	*this = copy;
}

MSDL_Surface::MSDL_Surface(MSDL_Surface && move)
{
	*this = move;
}

MSDL_Surface & MSDL_Surface::operator=(const MSDL_Surface & copy)
{
	if (this != &copy) {
		SDL_Surface * surface = copy._surface.get();
		reset(SDL_ConvertSurface(surface, surface->format, 0));
		_dedicated = copy._dedicated;
	}
	return *this;
}

MSDL_Surface & MSDL_Surface::operator=(MSDL_Surface && move)
{
	_surface = std::move(move._surface);
	_dedicated = std::move(move._dedicated);
	return *this;
}

bool MSDL_Surface::fill_rect(SDL_Rect * rect, Uint32 color)
{
	return (SDL_FillRect(_surface.get(), rect, color) == 0);
}

bool MSDL_Surface::load_bmp(const string & file)
{
	reset(SDL_LoadBMP(file.c_str()));
	return (this->_surface != nullptr);
}

bool MSDL_Surface::blit_from(const MSDL_Surface & source, const SDL_Rect * src_rect, SDL_Rect * dst_rect)
{
	return (SDL_BlitSurface(source._surface.get(), src_rect, _surface.get(), dst_rect) == 0);
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
	if (_dedicated) {
		// If the surface belongs to an SDL_Window, let the window destroy the surface.
		_surface.release();
		_dedicated = false;
	}
	_surface.reset(surface);
}

bool MSDL_Surface::is_empty()
{
	return (_surface == nullptr);
}

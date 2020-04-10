/*
        2019 Daniel Stotts
 */
#include <msdl_surface.hxx>

#include <msdl.hxx>
using MSDL::ColorDepth;

#include <string>
using std::string;

#include <memory>
using std::unique_ptr;

#include <algorithm>


namespace MSDL
{

void swap(Surface & lhs, Surface & rhs)
{
	using std::swap;
	swap(lhs._surface, rhs._surface);
}

Surface::Surface() : _surface(nullptr)
{}

Surface::Surface(const Surface & copy)
{
	const surface_ptr & surface = copy._surface;
	if (surface) {
		_surface.reset(SDL_ConvertSurface(surface.get(), surface->format, 0));
	}
}

Surface & Surface::operator=(Surface copy)
{
	swap(*this, copy);
	return *this;
}

Surface::~Surface()
{}

Surface::Surface(SDL_Surface * surface) : _surface(surface)
{}

Surface::Surface(int width, int height, ColorDepth depth)
{
	create_rgb(width, height, depth);
}

Surface::operator bool() const
{
	return !is_empty();
}

bool Surface::operator==(const Surface & rhs) const
{
	bool equal = false;

	// Shallow evaluation
	if (_surface == rhs._surface) {
		equal = true;
	}

	return equal;
}

bool Surface::fill_rect(SDL_Rect * rect, Uint8 r, Uint8 g, Uint8 b)
{
	return (SDL_FillRect(_surface.get(), rect, SDL_MapRGB(get_format(), r, g, b)) == 0);
}

bool Surface::load_bmp(string file)
{
	return reset(SDL_LoadBMP(file.c_str()));
}

bool Surface::blit_from(const Surface & source, const SDL_Rect * src_rect, SDL_Rect * dst_rect)
{
	return (SDL_BlitSurface(source._surface.get(), src_rect, _surface.get(), dst_rect) == 0);
}

bool Surface::blit_from(const string file, const SDL_Rect * src_rect, SDL_Rect * dst_rect)
{
	SDL_Surface * source = SDL_LoadBMP(file.c_str());
	return (SDL_BlitSurface(source, src_rect, _surface.get(), dst_rect) == 0);
}

bool Surface::create_rgb(int width, int height, ColorDepth depth)
{
	bool success = false;
	SDL_Surface * surface =
	    SDL_CreateRGBSurface(0, width, height, static_cast<int>(depth), RMASK, GMASK, BMASK, AMASK);

	if (surface) {
		reset(surface);
		success = true;
	}
	return success;
}

SDL_PixelFormat * Surface::get_format() const
{
	SDL_PixelFormat * format = nullptr;

	if (_surface) {
		format = _surface->format;
	}

	return format;
}

bool Surface::reset(SDL_Surface * surface)
{
	_surface.reset(surface);
	return !is_empty();
}

bool Surface::is_empty() const
{
	return (_surface == nullptr);
}

}  // namespace MSDL

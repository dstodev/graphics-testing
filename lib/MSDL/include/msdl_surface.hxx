/*
        2019 Daniel Stotts
 */

#ifndef MSDL_SURFACE_H
#define MSDL_SURFACE_H

#include <SDL.h>

#include <memory>
#include <string>

#include <msdl_export.hxx>


namespace MSDL
{

struct SurfaceDeleter
{
	void operator()(SDL_Surface * surface)
	{
		SDL_FreeSurface(surface);
	}
};

using surface_ptr = std::unique_ptr<SDL_Surface, SurfaceDeleter>;


class Surface
{
	friend void swap(Surface & lhs, Surface & rhs);

public:
	MSDL_EXPORT Surface();
	MSDL_EXPORT Surface(const Surface & copy);
	MSDL_EXPORT Surface & operator=(Surface copy);
	MSDL_EXPORT virtual ~Surface();

	MSDL_EXPORT Surface(SDL_Surface * surface);

	MSDL_EXPORT operator bool() const;

	MSDL_EXPORT bool fill_rect(SDL_Rect * rect, Uint8 r, Uint8 g, Uint8 b);
	MSDL_EXPORT bool load_bmp(std::string file);
	MSDL_EXPORT bool blit_from(const Surface & source, const SDL_Rect * src_rect, SDL_Rect * dst_rect);
	MSDL_EXPORT bool blit_from(const std::string file, const SDL_Rect * src_rect, SDL_Rect * dst_rect);

	surface_ptr & get_surface() const;
	MSDL_EXPORT SDL_PixelFormat * get_format() const;

	MSDL_EXPORT bool reset(SDL_Surface * surface = nullptr);
	MSDL_EXPORT bool is_empty() const;

protected:
	mutable surface_ptr _surface;
};

}  // namespace MSDL

#endif

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

extern void SurfaceDeleter(SDL_Surface * surface);
extern void NopDeleter(SDL_Surface * surface);

class Surface
{
	friend void swap(Surface & lhs, Surface & rhs);

public:
	MSDL_EXPORT Surface();
	MSDL_EXPORT Surface(const Surface & copy);
	MSDL_EXPORT Surface & operator=(Surface copy);
	MSDL_EXPORT virtual ~Surface();

	MSDL_EXPORT Surface(SDL_Surface * surface, void (*deleter)(SDL_Surface *) = SurfaceDeleter);

	MSDL_EXPORT bool fill_rect(SDL_Rect * rect, Uint8 r, Uint8 g, Uint8 b);
	MSDL_EXPORT bool load_bmp(std::string file);
	MSDL_EXPORT bool blit_from(const Surface & source, const SDL_Rect * src_rect, SDL_Rect * dst_rect);
	MSDL_EXPORT bool blit_from(std::string file, const SDL_Rect * src_rect, SDL_Rect * dst_rect);

	MSDL_EXPORT SDL_PixelFormat * get_format();

	MSDL_EXPORT void reset(SDL_Surface * surface = nullptr);
	MSDL_EXPORT bool is_empty();

protected:
	std::shared_ptr<SDL_Surface> _surface;
};

}  // namespace MSDL

#endif

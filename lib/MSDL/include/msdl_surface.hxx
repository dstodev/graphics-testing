#ifndef MSDL_SURFACE_H
#define MSDL_SURFACE_H

#include <memory>
#include <string>

#include <SDL.h>

#include < msdl.hxx>
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
	// TODO: Should I even use the copy and swap idiom here? I don't exactly need exception safety here, or maybe
	//       anywhere. Should I even use exceptions in this codebase? Graphics are already slow, do I want to add
	//       overhead beyond using an object oriented design?
	friend void swap(Surface & lhs, Surface & rhs);

public:
	MSDL_EXPORT Surface();
	MSDL_EXPORT Surface(const Surface & copy);
	MSDL_EXPORT Surface & operator=(Surface copy);
	MSDL_EXPORT virtual ~Surface();

	MSDL_EXPORT Surface(SDL_Surface * surface);
	MSDL_EXPORT Surface::Surface(int width, int height, ColorDepth depth);


	MSDL_EXPORT operator bool() const;
	MSDL_EXPORT bool operator==(const Surface & rhs) const;

	MSDL_EXPORT bool fill_rect(SDL_Rect * rect, Uint8 r, Uint8 g, Uint8 b);
	MSDL_EXPORT bool load_bmp(std::string file);
	MSDL_EXPORT bool blit_from(const Surface & source, const SDL_Rect * src_rect, SDL_Rect * dst_rect);
	MSDL_EXPORT bool blit_from(const std::string file, const SDL_Rect * src_rect, SDL_Rect * dst_rect);
	MSDL_EXPORT bool create_rgb(int width, int height, ColorDepth depth);
	MSDL_EXPORT bool reset(SDL_Surface * surface = nullptr);
	MSDL_EXPORT bool is_empty() const;

	MSDL_EXPORT SDL_PixelFormat * get_format() const;

protected:
	surface_ptr _surface;
};

}  // namespace MSDL

#endif

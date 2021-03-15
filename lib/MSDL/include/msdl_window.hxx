#ifndef MSDL_WINDOW_H
#define MSDL_WINDOW_H

#include <memory>

#include <SDL.h>

#include "msdl_surface.hxx"
#include <msdl_export.hxx>

namespace MSDL {

struct WindowDeleter
{
	void operator()(SDL_Window * window)
	{
		SDL_DestroyWindow(window);
	}
};

using window_ptr = std::unique_ptr<SDL_Window, WindowDeleter>;


class Window : public Surface
{
public:
	MSDL_EXPORT Window(const char * title, int x, int y, int w, int h, unsigned int window_flags = 0);
	MSDL_EXPORT ~Window();

	MSDL_EXPORT bool update();
	MSDL_EXPORT bool reset(SDL_Surface * surface = nullptr);

private:
	window_ptr _window;
};

}  // namespace MSDL

#endif

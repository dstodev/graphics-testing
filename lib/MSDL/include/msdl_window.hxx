/*
        2019 Daniel Stotts
 */

#ifndef MSDL_WINDOW_H
#define MSDL_WINDOW_H

#include <SDL.h>

#include "msdl_surface.hxx"
#include <msdl_export.hxx>

namespace MSDL
{

class Window
{
public:
	MSDL_EXPORT Window(const char * title, int x, int y, int w, int h, unsigned int window_flags = 0);
	MSDL_EXPORT ~Window();

	MSDL_EXPORT Surface & get_surface();

	MSDL_EXPORT bool update();

private:
	SDL_Window * _window;
	Surface _surface;
};

}  // namespace MSDL

#endif

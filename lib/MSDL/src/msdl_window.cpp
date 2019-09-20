/*
        2019 Daniel Stotts
 */

#include "msdl_window.h"

#include <iostream>
using std::cout;
using std::endl;

namespace MSDL
{

Window::Window(const char * title, int x, int y, int w, int h, unsigned int window_flags)
{
	_window = SDL_CreateWindow(title, x, y, w, h, window_flags);
	_surface = Surface(SDL_GetWindowSurface(_window));
}

Window::~Window()
{
	if (_window) {
		SDL_DestroyWindow(_window);
	}
}

Surface Window::get_surface() const
{
	return _surface;
}

bool Window::update()
{
	return (SDL_UpdateWindowSurface(_window) == 0);
}

}  // namespace MSDL

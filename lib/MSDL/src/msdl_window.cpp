/*
        2019 Daniel Stotts
 */

#include "msdl_window.h"

#include <iostream>
using std::cout;
using std::endl;

MSDL_Window::MSDL_Window(const char * title, int x, int y, int w, int h, unsigned int window_flags)
{
	_window = SDL_CreateWindow(title, x, y, w, h, window_flags);
	_surface = MSDL_Surface(SDL_GetWindowSurface(_window));
}

MSDL_Window::~MSDL_Window()
{
	if (_window) {
		SDL_DestroyWindow(_window);
	}
}

MSDL_Surface MSDL_Window::get_surface() const
{
	return _surface;
}

bool MSDL_Window::update()
{
	return (SDL_UpdateWindowSurface(_window) == 0);
}

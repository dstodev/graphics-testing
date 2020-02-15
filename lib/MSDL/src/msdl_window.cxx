/*
        2019 Daniel Stotts
 */

#include <msdl_window.hxx>

#include <memory>
using std::make_unique;

#include <iostream>
using std::cout;
using std::endl;


namespace MSDL
{

Window::Window(const char * title, int x, int y, int w, int h, unsigned int window_flags)
{
	_window = window_ptr(SDL_CreateWindow(title, x, y, w, h, window_flags));
	_surface.reset(SDL_GetWindowSurface(_window.get()));
}

Window::~Window()
{
	if (_window) {
		// Do not let the surface delete the pointer, as SDL_DestroyWindow() will do that for us
		_surface.release();
	}
}

bool Window::update()
{
	return (SDL_UpdateWindowSurface(_window.get()) == 0);
}

bool Window::reset(SDL_Surface * surface)
{
	(void) surface;  // Parameter is unused

	// Do not let the window's surface be reset
	return false;
}

}  // namespace MSDL

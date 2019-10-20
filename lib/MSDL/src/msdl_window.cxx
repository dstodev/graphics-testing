/*
        2019 Daniel Stotts
 */

#include <msdl_window.hxx>

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
		// Do not let the surface delete the pointer, as SDL_DestroyWindow() will do that for us
		_surface.get_surface().release();
		SDL_DestroyWindow(_window);
	}
}

Surface & Window::get_surface()
{
	return _surface;
}

bool Window::update()
{
	return (SDL_UpdateWindowSurface(_window) == 0);
}

}  // namespace MSDL

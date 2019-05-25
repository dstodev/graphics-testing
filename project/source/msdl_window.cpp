#include "msdl_window.h"
#include "msdl_windowsurface.h"

#include <memory>
using std::make_unique;

#include <iostream>
using std::cout;
using std::endl;

MSDL_Window::MSDL_Window(const char * title, int x, int y, int w, int h, unsigned int window_flags)
{
	_window = SDL_CreateWindow(title, x, y, w, h, window_flags);
}

MSDL_Window::~MSDL_Window()
{
	if (_window) {
		SDL_DestroyWindow(_window);
	}
}

MSDL_Window::operator bool() const
{
	return _window != nullptr;
}

unique_ptr<MSDL_Surface> MSDL_Window::get_surface() const
{
	SDL_Surface * surface = nullptr;
	if (_window) {
		surface = SDL_GetWindowSurface(_window);
		return make_unique<MSDL_WindowSurface>(surface);
	} else {
		// An MSDL_Surface can be evaluated as a boolean to determine if it contains nullptr.
		return make_unique<MSDL_Surface>();
	}
}

bool MSDL_Window::update()
{
	return SDL_UpdateWindowSurface(_window) == 0;
}

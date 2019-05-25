#include "msdl_windowsurface.h"

MSDL_WindowSurface::MSDL_WindowSurface(SDL_Surface * surface) : MSDL_Surface(surface)
{}

MSDL_WindowSurface::~MSDL_WindowSurface()
{
	clear_surface();
}

void MSDL_WindowSurface::clear_surface()
{
	// Set _surface to nullptr so that SDL_FreeSurface() is not called on the surface when ~MSDL_Surface() is
	// invoked. This is because SDL_DestroyWindow() frees the window's surface.
	_surface = nullptr;
}

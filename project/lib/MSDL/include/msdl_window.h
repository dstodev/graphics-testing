#ifndef MSDL_WINDOW_H
#define MSDL_WINDOW_H

#include <memory>
using std::unique_ptr;

#include <SDL.h>

#include "msdl_export.h"
#include "msdl_surface.h"

class MSDL_Window
{
public:
	MSDL_EXPORT MSDL_Window(const char * title, int x, int y, int w, int h, unsigned int window_flags = 0);
	MSDL_EXPORT ~MSDL_Window();

	MSDL_EXPORT MSDL_Surface get_surface() const;

	MSDL_EXPORT bool update();

private:
	SDL_Window * _window;
};

#endif

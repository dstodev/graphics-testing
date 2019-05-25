#ifndef MSDL_WINDOWSURFACE_H
#define MSDL_WINDOWSURFACE_H

#include "msdl_surface.h"

class MSDL_WindowSurface : public MSDL_Surface
{
public:
	MSDL_WindowSurface(SDL_Surface * surface);
	virtual ~MSDL_WindowSurface() override;

protected:
	virtual void clear_surface() override;
};

#endif

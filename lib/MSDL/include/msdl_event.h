/*
        2019 Daniel Stotts
 */

#ifndef MSDL_EVENT_H
#define MSDL_EVENT_H

#include <SDL.h>

#include "msdl_export.h"

class MSDL_EventController
{
public:
	MSDL_EXPORT MSDL_EventController() = default;
	MSDL_EXPORT ~MSDL_EventController() = default;

	MSDL_EXPORT bool await_event(uint32_t type, uint32_t timeout_ms);

private:
};

#endif

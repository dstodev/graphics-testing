/*
        2019 Daniel Stotts
 */

#ifndef MSDL_EVENT_H
#define MSDL_EVENT_H

#include <SDL.h>

#include "msdl_export.h"

namespace MSDL
{

class EventController
{
public:
	MSDL_EXPORT EventController() = default;
	MSDL_EXPORT ~EventController() = default;

	MSDL_EXPORT bool await_event(uint32_t type, uint32_t timeout_ms);

private:
};

}  // namespace MSDL

#endif

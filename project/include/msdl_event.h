#ifndef MSDL_EVENT_H
#define MSDL_EVENT_H

#include <SDL.h>

class MSDL_EventController
{
public:
	MSDL_EventController() = default;
	~MSDL_EventController() = default;

	bool await_event(uint32_t type, uint32_t timeout_ms);

private:
};

#endif

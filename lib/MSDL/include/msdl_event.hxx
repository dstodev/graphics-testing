#ifndef MSDL_EVENT_H
#define MSDL_EVENT_H

#include <SDL.h>
#include <msdl_export.hxx>

namespace MSDL
{

class EventController
{
public:
	MSDL_EXPORT EventController();
	MSDL_EXPORT virtual ~EventController();
	MSDL_EXPORT EventController(const EventController & copy);
	MSDL_EXPORT EventController & operator=(EventController other);

	MSDL_EXPORT bool await_event(uint32_t type, uint32_t timeout_ms);

private:
};

}  // namespace MSDL

#endif

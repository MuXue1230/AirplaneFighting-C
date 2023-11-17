#include "Event.h"

Event::Event(SDL_Renderer* renderer)
{
	this->eventType = EVENT;
	this->renderer = renderer;
}

int Event::getEventType()
{
	return this->eventType;
}

#include "Event.h"

Event::Event(SDL_Renderer* renderer)
{
	this->eventType = EVENT;
	this->renderer = renderer;
}

void Event::getEventType()
{
}

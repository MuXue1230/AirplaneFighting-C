#pragma once
#include <SDL.h>
#include "EventType.h"

class Event
{
public:
	Event(SDL_Renderer* renderer);
	int getEventType();
private:
	int eventType;
	SDL_Renderer* renderer;
};

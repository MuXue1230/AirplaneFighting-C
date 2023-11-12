#pragma once
#include <SDL.h>
#include "EventType.h"

class Event
{
public:
	Event(SDL_Renderer* renderer);
	void getEventType();
private:
	int eventType;
	SDL_Renderer* renderer;
};

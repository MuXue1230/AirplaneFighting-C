#pragma once
#include "Event.h"

class Listener
{
public:
	Listener();
	virtual void handle(Event event);
};


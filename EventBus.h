#pragma once
#include "Listener.h"

class EventBus
{
public:
	EventBus();
private:
	Listener listeners[100][2];
};


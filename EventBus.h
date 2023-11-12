#pragma once
#include "Listener.h"
#include "EventType.h"
#include "Event.h"

class EventBus
{
public:
	EventBus();
	void addListener(int eventType, Listener listener);
	void addEvent(Event event);
private:
	ListenerList listeners[100];
	int listenerIndex = 0;
};


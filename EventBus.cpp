#include "EventBus.h"

EventBus::EventBus()
{
}

void EventBus::addListener(int eventType, Listener listener)
{
	this->listeners[this->listenerIndex] = { EVENT,listener };
	this->listenerIndex++;
}

void EventBus::addEvent(Event event)
{
	for (auto item : this->listeners) {
		if (item.ListenerType == event.getEventType()) {
			item.listener.handle(event);
		}
	}
}

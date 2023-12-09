#pragma once
#include <SDL.h>

enum BasicActorStatus {
	ACTIVE = 1,
	DIED,
	PAUSED,
};

class Actor
{
public:
	Actor();
	~Actor();
	virtual void UpdateActor();
	virtual void UpdateRenderer(SDL_Renderer* renderer);
private:
	BasicActorStatus status = ACTIVE;
};


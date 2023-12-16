#pragma once
#include <SDL.h>
#include <vector>
#include <memory>
#include <random>
#include "Actor.h"

enum BasicSceneStatus {
	S_ACTIVE=1,
	S_INACTIVE
};

class Scene
{
public:
	Scene();
	void UpdateActors();
	void UpdateEvent(SDL_Event event);
	virtual void UpdateScene();
	virtual void UpdateSceneEvent(SDL_Event event);
	void UpdateActorRenderers(SDL_Renderer* renderer);
	virtual void UpdateSceneRenderer(SDL_Renderer* renderer);
	template <typename ActorX>
	void AddActor(ActorX actor);

	bool operator==(Scene scene) const;

	BasicSceneStatus GetStatus() const;
	void SetStatus(BasicSceneStatus status);

	int sid;
private:
	std::vector<std::shared_ptr<Actor>> actors;
	int actorIndex = 0;
	BasicSceneStatus status = S_INACTIVE;
};

template <typename ActorX>
void Scene::AddActor(ActorX actor)
{
	this->actors.push_back(std::make_shared<ActorX>(actor));
	this->actorIndex++;
}


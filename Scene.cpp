#include "Scene.h"

Scene::Scene()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(1000000000, 9999999999);
	this->sid = distrib(gen);
}

void Scene::UpdateActors()
{
	for (auto actor : this->actors) {
		actor->UpdateActor();
	}
	this->UpdateScene();
}

void Scene::UpdateEvent(SDL_Event event)
{
	for (auto actor : this->actors) {
		actor->UpdateEvent(event);
	}
	this->UpdateSceneEvent(event);
}

void Scene::UpdateScene()
{
}

void Scene::UpdateSceneEvent(SDL_Event event)
{
}

void Scene::UpdateActorRenderers(SDL_Renderer* renderer)
{
	for (auto actor : this->actors) {
		actor->UpdateRenderer(renderer);
	}
	this->UpdateSceneRenderer(renderer);
}

void Scene::UpdateSceneRenderer(SDL_Renderer* renderer)
{
}

bool Scene::operator==(Scene scene) const
{
	return this->sid == scene.sid;
}

BasicSceneStatus Scene::GetStatus() const
{
	return this->status;
}

void Scene::SetStatus(BasicSceneStatus status)
{
	this->status = status;
}

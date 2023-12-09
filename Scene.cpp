#include "Scene.h"

Scene::Scene()
{
}

void Scene::UpdateActors()
{
	for (auto actor : this->actors) {
		actor->UpdateActor();
	}
	this->UpdateScene();
}

void Scene::UpdateScene()
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

BasicSceneStatus Scene::GetStatus()
{
	return this->status;
}

void Scene::SetStatus(BasicSceneStatus status)
{
	this->status = status;
}

#include "SceneBus.h"

SceneBus::SceneBus()
{
}

SceneBus::~SceneBus()
{
}

void SceneBus::UpdateScenes()
{
	for (auto item : this->scenes) {
		if (item.GetStatus() == ENABLED) {
			item.UpdateActors();
		}
	}
}

void SceneBus::UpdateRenderer(SDL_Renderer* renderer)
{
	for (auto item : this->scenes) {
		if (item.GetStatus() == ENABLED) {
			item.UpdateActorRenderers(renderer);
		}
	}
}

void SceneBus::AddSene(Scene scene)
{
	this->scenes[this->sceneIndex] = scene;
	this->sceneIndex++;
}

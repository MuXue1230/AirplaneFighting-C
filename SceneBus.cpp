#include "SceneBus.h"

SceneBus::SceneBus()
{
}

SceneBus::~SceneBus()
{
}

void SceneBus::UpdateScenes()
{
	for (auto &item : this->scenes) {
		if (item->GetStatus() == S_ACTIVE) {
			item->UpdateActors();
		}
	}
}

void SceneBus::UpdateEvent(SDL_Event event)
{
	for (auto &item : this->scenes) {
		if (item->GetStatus() == S_ACTIVE) {
			item->UpdateEvent(event);
		}
	}
}

void SceneBus::UpdateRenderer(SDL_Renderer* renderer)
{
	for (auto &item : this->scenes) {
		if (item->GetStatus() == S_ACTIVE) {
			item->UpdateActorRenderers(renderer);
		}
	}
}

void SceneBus::SetSceneStatus(BasicSceneStatus status, Scene scene)
{
	int index = 0;
	for (const auto &item : this->scenes) {
		if (*item == scene) {
			this->scenes[index]->SetStatus(status);
			return;
		}
		index++;
	}
}

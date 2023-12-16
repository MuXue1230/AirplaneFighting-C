#pragma once
#include <SDL.h>
#include "Scene.h"
class SceneBus
{
public:
	SceneBus();
	~SceneBus();
	void UpdateScenes();
	void UpdateEvent(SDL_Event event);
	void UpdateRenderer(SDL_Renderer* renderer);
	void AddScene(Scene scene);
	void SetSceneStatus(BasicSceneStatus status, Scene scene);
private:
	Scene scenes[100];
	int sceneIndex = 0;
};


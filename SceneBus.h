#pragma once
#include <SDL.h>
#include "Scene.h"
class SceneBus
{
public:
	SceneBus();
	~SceneBus();
	void UpdateScenes();
	void UpdateRenderer(SDL_Renderer* renderer);
	void AddSene(Scene scene);
private:
	Scene scenes[100];
	int sceneIndex = 0;
};


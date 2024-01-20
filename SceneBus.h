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
	template <typename SceneX>
	void AddScene(SceneX scene);
	void SetSceneStatus(BasicSceneStatus status, Scene scene);
private:
	std::vector<std::shared_ptr<Scene>> scenes;
	int sceneIndex = 0;
};

template<typename SceneX>
inline void SceneBus::AddScene(SceneX scene)
{
	this->scenes.push_back(std::make_shared<SceneX>(scene));
	this->sceneIndex++;
}

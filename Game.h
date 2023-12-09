#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Config.h"
#include "TextureBus.h"
#include "SceneBus.h"
#include "AImage.h"

class Game
{
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();
private:
	void ProcessesInput();
	void UpdateGame();
	void GenerateOutput();

	void InitScenes();

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	bool mIsRunning = true;
	Config* mConfig;
	TextureBus* mTextureBus;
	SceneBus* mSceneBus;
};


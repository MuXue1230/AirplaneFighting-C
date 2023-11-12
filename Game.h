#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Config.h"

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
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	bool mIsRunning = true;
	Config* config;
};


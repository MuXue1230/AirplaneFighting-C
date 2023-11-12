#include "Game.h"

Game::Game()
{
	config = new Config("config.json", "assets/");
	config->init();
}

bool Game::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
		SDL_Log("Can't init SDL: ", SDL_GetError());
		return false;
	}
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		SDL_Log("Can't init SDL_image: ", IMG_GetError());
		return false;
	}
	if (TTF_Init()) {
		SDL_Log("Can't init SDL_ttf: ", TTF_GetError());
	}
	SDL_DisplayMode mode;
	config->get_screen_size(&mode);
	mWindow = SDL_CreateWindow("game.window.title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mode.w, mode.h, SDL_WINDOW_BORDERLESS);
	if (!mWindow) {
		SDL_Log("Can't create SDL window: ", SDL_GetError());
		return false;
	}
	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	return true;
}

void Game::RunLoop()
{
	while (mIsRunning) {
		ProcessesInput();
		UpdateGame();
		GenerateOutput();
	}
}

void Game::Shutdown()
{
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(mRenderer);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

void Game::ProcessesInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			mIsRunning = false;
			break;
		}
	}
}

void Game::UpdateGame()
{
}

void Game::GenerateOutput()
{
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	SDL_RenderClear(mRenderer);
	SDL_RenderPresent(mRenderer);
}

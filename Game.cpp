#include "Game.h"

Game::Game()
{
	mConfig = new Config("config.json", "assets/");
	mConfig->init();
	mILTextBus = new ILTextBus(_strdup(mConfig->get_config("language").c_str()));
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
	mConfig->get_screen_size(&mode);
	mWindow = SDL_CreateWindow(mILTextBus->GetText("game.window.title"), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mode.w, mode.h, SDL_WINDOW_BORDERLESS);
	if (!mWindow) {
		SDL_Log("Can't create SDL window: ", SDL_GetError());
		return false;
	}
	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	mTextureBus = new TextureBus(mRenderer);
	mSceneBus = new SceneBus();
	InitScenes();
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
	mSceneBus->UpdateRenderer(mRenderer);
	SDL_RenderPresent(mRenderer);
}

void Game::InitScenes()
{
	Scene* LoadScene = new Scene();
	LoadScene->AddActor(*(new AImage((char*)"load", mTextureBus)));
	LoadScene->SetStatus(ENABLED);
	mSceneBus->AddSene(*LoadScene);
}

#include "Game.h"

Game::Game()
{
	mConfig = new Config("config.json", "assets/");
	mConfig->init();
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
	if (!(Mix_Init(MIX_INIT_OGG) & MIX_INIT_OGG)) {
		SDL_Log("Can't init SDL_mixer: ", Mix_GetError());
		return false;
	}
	if (TTF_Init()) {
		SDL_Log("Can't init SDL_ttf: ", TTF_GetError());
	}
	SDL_DisplayMode mode;
	mConfig->get_screen_size(&mode);
	mWindow = SDL_CreateWindow("game.window.title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mode.w, mode.h, SDL_WINDOW_BORDERLESS);
	if (!mWindow) {
		SDL_Log("Can't create SDL window: ", SDL_GetError());
		return false;
	}
	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	mILTextBus = new ILTextBus(_strdup(mConfig->get_config("language").c_str()), mRenderer);
	mTextureBus = new TextureBus(mRenderer);
	mSceneBus = new SceneBus();
	InitScenes();
	mSceneBus->SetSceneStatus(S_INACTIVE, *this->LoadScene);
	mSceneBus->SetSceneStatus(S_ACTIVE, *this->MainScene);
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
		mSceneBus->UpdateEvent(event);
	}
}

void Game::UpdateGame()
{
	mSceneBus->UpdateScenes();
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
	int w, h;
	SDL_GetWindowSize(mWindow, &w, &h);

	// Set up load scene
	LoadScene = new Scene();
	AImage* load_img = new AImage((char*)"load", mTextureBus);
	AText* load_text = new AText((char*)"game.scene.load.load_text.text", 96, { 0,0,0,0 }, mILTextBus);
	load_img->SetSize(w, h - 100);
	load_text->SetPos((w - load_text->GetRect().w) / 2, h - 100);
	LoadScene->AddActor(*(load_img));
	LoadScene->AddActor(*(load_text));
	mSceneBus->AddScene(*LoadScene);
	mSceneBus->SetSceneStatus(S_ACTIVE, *LoadScene);

	// Set up main scene
	MainScene = new Scene();
	AImage* background = new AImage((char*)"gui/background", mTextureBus);
	AText* game_title = new AText((char*)"game.scene.main.game_title.text", 96, { 255,255,255,255 }, mILTextBus);
	AButton* quit_button = new AButton((char*)"game.scene.main.quit_button.text", mILTextBus, mTextureBus, functions::buttons::QuitButtonFunction);
	background->SetSize(w, h);
	game_title->SetPos((w - game_title->GetRect().w) / 2, h / 2 - 300);
	quit_button->SetPos((w - quit_button->GetRect().w) / 2, h / 2 + 100);
	MainScene->AddActor(*(background));
	MainScene->AddActor(*(game_title));
	MainScene->AddActor(*(quit_button));
	mSceneBus->AddScene(*MainScene);
}

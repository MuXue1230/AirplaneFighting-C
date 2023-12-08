#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <map>
#include <string>

class TextureBus
{
public:
	TextureBus(SDL_Renderer* renderer);
	~TextureBus();
	SDL_Texture* GetTexture(char* texture_name);
private:
	SDL_Texture* LoadTexture(char* texture_name);

	SDL_Renderer* mRenderer;
	std::map<char*, SDL_Texture*> mTextures;
	char* mLoadedTextureList[1000];
	int mLoadedTextureIndex;
};


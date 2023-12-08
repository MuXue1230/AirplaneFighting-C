#include "TextureBus.h"

TextureBus::TextureBus(SDL_Renderer* renderer)
{
	this->mLoadedTextureIndex = 0;
	this->mRenderer = renderer;
}

TextureBus::~TextureBus()
{
	for (auto texture : this->mLoadedTextureList) {
		SDL_DestroyTexture(this->mTextures[texture]);
	}
}

SDL_Texture* TextureBus::GetTexture(char* texture_name)
{
	for (auto item : this->mLoadedTextureList) {
		if (item == texture_name) {
			return this->mTextures[texture_name];
		}
	}
	return this->LoadTexture(texture_name);
}

SDL_Texture* TextureBus::LoadTexture(char* texture_name)
{
	SDL_Surface* surface = IMG_Load(((std::string)"assets/textures/" + (std::string)texture_name + (std::string)".png").c_str());
	if (!surface) {
		SDL_Log("Texture load failure: %s", ((std::string)"assets/textures/" + (std::string)texture_name + (std::string)".png").c_str());
		return nullptr;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(this->mRenderer,surface);
	SDL_FreeSurface(surface);
	if (!texture) {
		SDL_Log("Texture convert failure: %s", ((std::string)"assets/textures/" + (std::string)texture_name + (std::string)".png").c_str());
		return nullptr;
	}
	return texture;
}

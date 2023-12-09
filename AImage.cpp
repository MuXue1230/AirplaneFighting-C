#include "AImage.h"

AImage::AImage(char* name, TextureBus* textureBus)
{
	this->textureBus = textureBus;
	this->texture = this->textureBus->GetTexture(name);
}

void AImage::UpdateActor()
{
}

void AImage::UpdateRenderer(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, texture, NULL, NULL);
}

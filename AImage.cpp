#include "AImage.h"

AImage::AImage(char* name, TextureBus* textureBus)
{
	int textureWidth, textureHeight;
	this->textureBus = textureBus;
	this->texture = this->textureBus->GetTexture(name);
	SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
	this->rect = { 0, 0, textureWidth, textureHeight };
}

void AImage::UpdateActor()
{
}

void AImage::UpdateEvent(SDL_Event event)
{
}

void AImage::UpdateRenderer(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void AImage::SetPos(int x, int y)
{
	this->rect.x = x;
	this->rect.y = y;
}

void AImage::SetSize(int w, int h)
{
	this->rect.w = w;
	this->rect.h = h;
}

SDL_Rect AImage::GetRect() const
{
	return this->rect;
}

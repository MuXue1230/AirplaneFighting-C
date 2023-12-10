#include "AText.h"

AText::AText(char* text, SDL_Color color, ILTextBus* iLTextBus)
{
	int textureWidth, textureHeight;
	this->iLTextBus = iLTextBus;
	this->texture = this->iLTextBus->GetILTextTexture(text, color);
	SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
	this->rect = { 0, 0, textureWidth, textureHeight };
}

void AText::UpdateActor()
{
}

void AText::UpdateRenderer(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void AText::SetPos(int x, int y)
{
	this->rect.x = x;
	this->rect.y = y;
}

void AText::SetSize(int w, int h)
{
	this->rect.w = w;
	this->rect.h = h;
}

SDL_Rect AText::GetRect()
{
	return this->rect;
}

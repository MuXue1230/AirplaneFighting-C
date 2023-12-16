#include "ABQuit.h"

ABQuit::ABQuit(char* text, ILTextBus* iLTextBus, TextureBus* textureBus)
{
	int textureWidth, textureHeight;
	this->textureBus = textureBus;
	this->texture = this->textureBus->GetTexture((char*)"gui/button");
	SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
	this->rect = { 0, 0, textureWidth, textureHeight };
	this->text = new AText(text, 36, { 0,0,0,0 }, iLTextBus);
	this->text->SetPos((textureWidth - this->text->GetRect().w) / 2, (textureHeight - this->text->GetRect().h) / 2);
}

void ABQuit::pressed()
{
    SDL_Event quit_event;
    quit_event.type = SDL_QUIT;
    SDL_PushEvent(&quit_event);
}

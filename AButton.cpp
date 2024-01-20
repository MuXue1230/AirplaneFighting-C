#include "AButton.h"

AButton::AButton(char* text, ILTextBus* iLTextBus, TextureBus* textureBus, SoundBus* soundBus, void (*clickFunc)())
{
	int textureWidth, textureHeight;
	this->textureBus = textureBus;
	this->texture = this->textureBus->GetTexture((char*)"gui/button");
	SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
	this->rect = { 0, 0, textureWidth, textureHeight };
	this->text = new AText(text, 36, { 0,0,0,0 }, iLTextBus);
	this->text->SetPos((textureWidth - this->text->GetRect().w) / 2, (textureHeight - this->text->GetRect().h) / 2);
	this->clickFunc = clickFunc;
	this->soundBus = soundBus;
}

void AButton::UpdateActor()
{
	switch (this->status)
	{
	case B_NORMAL:
		this->texture = this->textureBus->GetTexture((char*)"gui/button");
		break;
	case B_OVER:
		this->texture = this->textureBus->GetTexture((char*)"gui/button_over");
		break;
	case B_PRESS:
		this->texture = this->textureBus->GetTexture((char*)"gui/button_pressed");
		break;
	case B_DISABLED:
		this->texture = this->textureBus->GetTexture((char*)"gui/button_disabled");
		break;
	}
}

void AButton::UpdateEvent(SDL_Event event)
{
	int mouseX, mouseY;
	if (this->status != B_DISABLED) {
		switch (event.type)
		{
		case SDL_MOUSEMOTION:
			SDL_GetMouseState(&mouseX, &mouseY);
			if (mouseX >= rect.x && mouseX <= rect.x + rect.w && mouseY >= rect.y && mouseY <= rect.y + rect.h) {
				if (this->status != B_OVER) {
					this->status = B_OVER;
					this->soundBus->PlaySoundByName((char*)"button");
				}
			}
			else {
				this->status = B_NORMAL;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			SDL_GetMouseState(&mouseX, &mouseY);
			if (mouseX >= rect.x && mouseX <= rect.x + rect.w && mouseY >= rect.y && mouseY <= rect.y + rect.h) {
				if (this->status != B_PRESS) {
					this->status = B_PRESS;
					this->soundBus->PlaySoundByName((char*)"button_click");
				}
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (this->status == B_PRESS) {
				SDL_GetMouseState(&mouseX, &mouseY);
				if (mouseX >= rect.x && mouseX <= rect.x + rect.w && mouseY >= rect.y && mouseY <= rect.y + rect.h) {
					this->status = B_OVER;
					this->clickFunc();
				}
				else {
					this->status = B_NORMAL;
				}
			}
			break;
		}
	}
}

void AButton::UpdateRenderer(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, texture, NULL, &rect);
	this->text->UpdateRenderer(renderer);
}

void AButton::SetPos(int x, int y)
{
	int textureWidth, textureHeight;
	SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
	this->rect.x = x;
	this->rect.y = y;
	this->text->SetPos((textureWidth - this->text->GetRect().w) / 2 + x, (textureHeight - this->text->GetRect().h) / 2 + y);
}

SDL_Rect AButton::GetRect() const
{
	return this->rect;
}

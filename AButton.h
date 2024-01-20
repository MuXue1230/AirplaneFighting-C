#pragma once
#include "Actor.h"
#include "TextureBus.h"
#include "ILTextBus.h"
#include "SoundBus.h"
#include "AText.h"

enum ButtonStatus {
    B_NORMAL = 1,
    B_OVER,
    B_PRESS,
    B_DISABLED,
};

class AButton :
    public Actor
{
public:
    AButton(char* text, ILTextBus* iLTextBus, TextureBus* textureBus, SoundBus* soundBus, void (*clickFunc)());
    void UpdateActor() override;
    void UpdateEvent(SDL_Event event) override;
    void UpdateRenderer(SDL_Renderer* renderer) override;

    void SetPos(int x, int y);

    SDL_Rect GetRect() const;
protected:
    TextureBus* textureBus;
    SoundBus* soundBus;
    SDL_Texture* texture;
    SDL_Rect rect;

    AText* text;

    void (*clickFunc)();

    // Button status
    ButtonStatus status = B_NORMAL;
};


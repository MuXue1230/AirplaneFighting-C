#pragma once
#include "Actor.h"
#include "TextureBus.h"
#include "ILTextBus.h"
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
    AButton(char* text, ILTextBus* iLTextBus, TextureBus* textureBus);
    void UpdateActor() override;
    void UpdateEvent(SDL_Event event) override;
    void UpdateRenderer(SDL_Renderer* renderer) override;

    virtual void pressed();

    void SetPos(int x, int y);

    SDL_Rect GetRect() const;
private:
    TextureBus* textureBus;
    SDL_Texture* texture;
    SDL_Rect rect;

    AText* text;

    // Button status
    ButtonStatus status = B_NORMAL;
};


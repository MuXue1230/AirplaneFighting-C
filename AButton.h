#pragma once
#include "Actor.h"
#include "TextureBus.h"

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
    AButton(TextureBus* textureBus);
    void UpdateActor() override;
    void UpdateEvent(SDL_Event event) override;
    void UpdateRenderer(SDL_Renderer* renderer) override;

    void SetPos(int x, int y);
    void SetSize(int w, int h);

    SDL_Rect GetRect() const;
private:
    TextureBus* textureBus;
    SDL_Texture* texture;
    SDL_Rect rect;

    // Button status
    ButtonStatus status = B_NORMAL;
};


#pragma once
#include <SDL.h>
#include "Actor.h"
#include "TextureBus.h"
class AImage :
    public Actor
{
public:
    AImage(char* name, TextureBus* textureBus);
    void UpdateActor() override;
    void UpdateRenderer(SDL_Renderer* renderer) override;

    void SetPos(int x, int y);
    void SetSize(int w, int h);

    SDL_Rect GetRect();
private:
    TextureBus* textureBus;
    SDL_Texture* texture;
    SDL_Rect rect;
};


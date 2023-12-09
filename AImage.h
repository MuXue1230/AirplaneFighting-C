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
private:
    TextureBus* textureBus;
    SDL_Texture* texture;
};


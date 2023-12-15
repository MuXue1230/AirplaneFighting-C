#pragma once
#include <SDL.h>
#include "Actor.h"
#include "ILTextBus.h"
class AText :
    public Actor
{
public:
    AText(char* text, int fontSize, SDL_Color color, ILTextBus* iLTextBus);
    void UpdateActor() override;
    void UpdateRenderer(SDL_Renderer* renderer) override;

    void SetPos(int x, int y);
    void SetSize(int w, int h);

    SDL_Rect GetRect();
private:
    ILTextBus* iLTextBus;
    SDL_Texture* texture;
    SDL_Rect rect;
};


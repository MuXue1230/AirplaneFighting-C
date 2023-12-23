#include "functions.h"

void functions::buttons::QuitButtonFunction()
{
    SDL_Event quit_event;
    quit_event.type = SDL_QUIT;
    SDL_PushEvent(&quit_event);
}

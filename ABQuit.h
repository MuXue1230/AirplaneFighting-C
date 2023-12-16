#pragma once
#include "AButton.h"
#include <SDL.h>

class ABQuit :
    public AButton
{
public:
    ABQuit(char* text, ILTextBus* iLTextBus, TextureBus* textureBus);
    void pressed() override;
};


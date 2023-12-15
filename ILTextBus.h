#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <Windows.h>
class ILTextBus
{
public:
	ILTextBus(char* ILTranslate, SDL_Renderer* renderer);
	~ILTextBus();
	const char* GetText(const char* ILText);
	SDL_Texture* GetTextTexture(const char* Text, int fontSize, SDL_Color color);
	SDL_Texture* GetILTextTexture(const char* ILText, int fontSize, SDL_Color color);
	void SetILTranslate(char* ILTranslate);
private:
	SDL_Renderer* renderer;
	char* ILTranslate;
	std::map<std::string, std::string> ILKV;
	char* LoadedILKVList[1000];
	int ILKVIndex = 0;
	TTF_Font* font;
};


#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
class ILTextBus
{
public:
	ILTextBus(char* ILTranslate);
	~ILTextBus();
	const char* GetText(const char* ILText);
	SDL_Texture* GetTextTexture(const char* Text);
	SDL_Texture* GetILTextTexture(const char* ILText);
	void SetILTranslate(char* ILTranslate);
private:
	char* ILTranslate;
	std::map<std::string, std::string> ILKV;
	char* LoadedILKVList[1000];
	int ILKVIndex = 0;
};


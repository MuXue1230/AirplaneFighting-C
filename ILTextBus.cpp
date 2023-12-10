#include "ILTextBus.h"

ILTextBus::ILTextBus(char* ILTranslate, SDL_Renderer* renderer)
{
	std::string file_text;
	std::stringstream buffer;
	std::ifstream file;
	std::string line;
	this->ILTranslate = ILTranslate;
	file.open((std::string)"assets/lang/" + (std::string)ILTranslate + (std::string)".lang");
	if (!file.is_open()) {
		SDL_Log(((std::string)"Load translate failure: assets/lang/" + (std::string)ILTranslate + (std::string)".lang").c_str());
		return ;
	}
	buffer << file.rdbuf();
	file.close();
	file_text = buffer.str();
	std::istringstream file_stream(file_text);
	while (std::getline(file_stream, line)) {
		std::istringstream line_stream(line);
		std::string key, value;
		if (std::getline(line_stream, key, '=')) {
			if (std::getline(line_stream, value)) {
				ILKV[key] = value;
				LoadedILKVList[ILKVIndex] = _strdup(key.c_str());
				ILKVIndex++;
			}
		}
	}
	this->renderer = renderer;
	this->font = TTF_OpenFont(((std::string)"assets/font/" + (std::string)ILTranslate + (std::string)".ttf").c_str(), 96);
	if (!font) {
		SDL_Log(((std::string)"Load font failure: assets/font/" + (std::string)ILTranslate + (std::string)".ttf").c_str());
		return;
	}
}

ILTextBus::~ILTextBus()
{
	TTF_CloseFont(font);
}

const char* ILTextBus::GetText(const char* ILText)
{
	for (auto item : this->LoadedILKVList) {
		if (item == NULL) {
			continue;
		}
		if (strcmp(item, ILText) == 0) {
			return this->ILKV[ILText].c_str();
		}
	}
	return ILText;
}

SDL_Texture* ILTextBus::GetTextTexture(const char* Text, SDL_Color color)
{
	if (!font) {
		SDL_Log("Because no font loaded, can't render any text.");
		return nullptr;
	}
	SDL_Color textColor = color;
	SDL_Surface* textSurface = TTF_RenderUTF8_Solid(font, Text, textColor);
	if (!textSurface) {
		SDL_Log("Render text falure.");
		return nullptr;
	}
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);
	return textTexture;
}

SDL_Texture* ILTextBus::GetILTextTexture(const char* ILText, SDL_Color color)
{
	return this->GetTextTexture(this->GetText(ILText), color);
}

void ILTextBus::SetILTranslate(char* ILTranslate)
{
	std::string file_text;
	std::stringstream buffer;
	std::ifstream file;
	std::string line;
	this->ILTranslate = ILTranslate;
	this->ILKVIndex = 0;
	file.open((std::string)"assets/lang/" + (std::string)ILTranslate + (std::string)".lang");
	if (!file.is_open()) {
		SDL_Log(((std::string)"Load translate failure: assets/lang/" + (std::string)ILTranslate + (std::string)".lang").c_str());
		return;
	}
	buffer << file.rdbuf();
	file.close();
	file_text = buffer.str();
	std::istringstream file_stream(file_text);
	while (std::getline(file_stream, line)) {
		std::istringstream line_stream(line);
		std::string key, value;
		if (std::getline(line_stream, key, '=')) {
			if (std::getline(line_stream, value)) {
				ILKV[key] = value;
				LoadedILKVList[ILKVIndex] = _strdup(key.c_str());
				ILKVIndex++;
			}
		}
	}
}

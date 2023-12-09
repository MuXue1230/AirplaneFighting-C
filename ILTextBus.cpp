#include "ILTextBus.h"

ILTextBus::ILTextBus(char* ILTranslate)
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
}

ILTextBus::~ILTextBus()
{
}

const char* ILTextBus::GetText(const char* ILText)
{
	for (auto item : this->LoadedILKVList) {
		if (strcmp(item,ILText) == 0) {
			return this->ILKV[ILText].c_str();
		}
	}
	return ILText;
}

SDL_Texture* ILTextBus::GetTextTexture(const char* Text)
{
	return nullptr;
}

SDL_Texture* ILTextBus::GetILTextTexture(const char* ILText)
{
	return this->GetTextTexture(this->GetText(ILText));
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

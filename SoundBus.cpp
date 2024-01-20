#include "SoundBus.h"

SoundBus::SoundBus()
{
	this->mLoadedSoundIndex = 0;
	this->mLoadedMusicIndex = 0;
}

SoundBus::~SoundBus()
{
	for (auto sound : this->mLoadedSoundList) {
		Mix_FreeChunk(this->mSounds[sound]);
	}
	for (auto music : this->mLoadedMusicList) {
		Mix_FreeMusic(this->mMusic[music]);
	}
}

void SoundBus::PlayMusicByName(char* music_name)
{
    Mix_Music* music = nullptr;
    for (const auto &item : this->mLoadedMusicList) {
        if (item == music_name) {
            music = this->mMusic[music_name];
            break;
        }
    }
    if (music == nullptr) {
        music = this->LoadMusic(music_name);
    }
    if (Mix_PlayMusic(music, -1) == -1) {
        SDL_Log("Failed to play music: %s. Error: %s", music_name, Mix_GetError());
    }
}

void SoundBus::PlaySoundByName(char* sound_name)
{
    Mix_Chunk* sound = nullptr;
    for (const auto &item : this->mLoadedSoundList) {
        if (item == sound_name) {
            sound = this->mSounds[sound_name];
            break;
        }
    }
    if (sound == nullptr) {
        sound = this->LoadSound(sound_name);
    }
    if (Mix_PlayChannel(-1, sound, 0) == -1) {
        SDL_Log("Failed to play sound: %s. Error: %s", sound_name, Mix_GetError());
    }
}


Mix_Music* SoundBus::LoadMusic(char* music_name)
{
	Mix_Music* music = Mix_LoadMUS(((std::string)"assets/sounds/" + (std::string)music_name + (std::string)".ogg").c_str());
	if (!music) {
		SDL_Log("Music load failure: %s", ((std::string)"assets/sounds/" + (std::string)music_name + (std::string)".ogg").c_str());
		return nullptr;
	}

	this->mMusic[music_name] = music;
	this->mLoadedMusicList[this->mLoadedMusicIndex++] = music_name;

	return music;
}

Mix_Chunk* SoundBus::LoadSound(char* sound_name)
{
	Mix_Chunk* sound = Mix_LoadWAV(((std::string)"assets/sounds/" + (std::string)sound_name + (std::string)".wav").c_str());
	if (!sound) {
		SDL_Log("Sound load failure: %s", ((std::string)"assets/sounds/" + (std::string)sound_name + (std::string)".wav").c_str());
		return nullptr;
	}

	this->mSounds[sound_name] = sound;
	this->mLoadedSoundList[this->mLoadedSoundIndex++] = sound_name;

	return sound;
}

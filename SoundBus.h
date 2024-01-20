#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <map>
#include <string>

class SoundBus
{
public:
	SoundBus();
	~SoundBus();
	void PlayMusicByName(char* music_name);
	void PlaySoundByName(char* sound_name);
private:
	Mix_Music* LoadMusic(char* music_name);
	Mix_Chunk* LoadSound(char* sound_name);

	std::map<char*, Mix_Chunk*> mSounds;
	char* mLoadedSoundList[10000000];
	int mLoadedSoundIndex;

	std::map<char*, Mix_Music*> mMusic;
	char* mLoadedMusicList[10000000];
	int mLoadedMusicIndex;
};


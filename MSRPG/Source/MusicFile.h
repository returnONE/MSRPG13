#ifndef MUSICFILE_H_
#define MUSICFILE_H_

#include "SDL_mixer.h"

class MusicFile
{
public:
	MusicFile(char* _fileName);
	~MusicFile();

	//sets e gets
	Mix_Music* GetMusicFile();
	int GetMusicDuration() const;
	void SetMusicDuration(int _duration);
	
	//outras
	void PlayMusic();
	void PauseMusic();

private:
	Mix_Music *music;
	int musicDuration;

};

#endif

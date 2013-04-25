#ifndef SFXFILE_H_
#define SFXFILE_H_

#include "SDL_mixer.h"

class SfxFile
{
public:
	SfxFile(char* _fileName);
	~SfxFile();

	//sets e gets
	Mix_Chunk* GetSfxFile();

	//outras
	void PlaySfx();


private:
	Mix_Chunk *sfx;

};

#endif

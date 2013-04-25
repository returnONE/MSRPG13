#include "MusicFile.h"

MusicFile::MusicFile(char* _fileName)
{
	music = Mix_LoadMUS( _fileName );
}

MusicFile::~MusicFile()
{
	Mix_FreeMusic( music );
}

Mix_Music* MusicFile::GetMusicFile()
{
	return music;
}

void MusicFile::SetMusicDuration( int _duration )
{
	musicDuration = _duration;
}

int MusicFile::GetMusicDuration() const
{
	return musicDuration;
}

void MusicFile::PlayMusic()
{
	if( Mix_PausedMusic() == 1 )
		Mix_ResumeMusic();
	else
		if( Mix_PlayingMusic() == 0 )
			Mix_PlayMusic( music, -1 );
}

void MusicFile::PauseMusic()
{
	if( Mix_PlayingMusic() == 1 )
		Mix_PauseMusic();
}

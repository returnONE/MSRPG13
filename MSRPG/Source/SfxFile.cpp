#include "SfxFile.h"

SfxFile::SfxFile(char* _fileName)
{
	sfx = Mix_LoadWAV( _fileName );
}

SfxFile::~SfxFile()
{
	Mix_FreeChunk( sfx );
}

Mix_Chunk* SfxFile::GetSfxFile()
{
	return sfx;
}

void SfxFile::PlaySfx()
{
	//Mix_SetPosition( 3, 180, 100); não funcionou :C
	Mix_PlayChannel( 3, sfx, 0 ); //canal a ser usado (-1 pega o primeiro livre); sfx a ser tocado; numero de repetições do som
}

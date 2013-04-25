#ifndef LISTMANAGER_H_
#define LISTMANAGER_H_

class Message; //evitando dependencia circular

#include "DynamicList.h"
#include "ImageFile.h"
#include "Message.h"
#include "SfxFile.h"
#include "MusicFile.h"
#include "RenderManager.h"

class ListManager
{
private:
	
	DynamicList<ImageFile>* myImageList;
	DynamicList<Message>* myMessageList;
	DynamicList<SfxFile>* mySfxList;
	DynamicList<MusicFile>* myMusicList;

public:

	static class ListManager *s_ListManager;
	static ListManager *GetListManager (void);

	//image
	DynamicList<ImageFile>* GetMyImageList() const;
	void CreateMyImageList();
	void NewImageToTheList(GLuint _image, int _imageID);

	//message
	void CreateMyMessageList();
	DynamicList<Message>* GetMyMessageList() const;
	//void SetMyMessageList(Message* _message, int _messageID);
	void NewMessageToTheList( std::string _myString, int _charsetCode, float _x, float _y, int _lifeTime, int _nodeID );

	//music
	void CreateMyMusicList();
	DynamicList<MusicFile>* GetMyMusicList() const;
	//void SetMyMusicList(char* _fileName, int _musicID);
	void NewMusicToTheList( char* _fileName, int _musicID );

	//sfx
	void CreateMySfxList();
	DynamicList<SfxFile>* GetMySfxList() const;
	//void SetMySfxList(char* _fileName, int _sfxID);
	void NewSfxToTheList( char* _sfxName, int _sfxID );

};


#endif
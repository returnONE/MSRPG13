#include "ListManager.h"

ListManager* ListManager::s_ListManager = 0;

ListManager* ListManager::GetListManager (void) 
{

	if (s_ListManager == 0)
		s_ListManager = new ListManager;
	return s_ListManager;
}


//////////////////Image List

DynamicList<ImageFile>* ListManager::GetMyImageList() const
{
	return myImageList;
}

void ListManager::CreateMyImageList()
{
	//myImageList = new DynamicList<ImageFile>(new Node<ImageFile>(0, NULL) );
	myImageList = new DynamicList<ImageFile>(NULL);
}

void ListManager::NewImageToTheList( GLuint _image, int _imageID )
{
	GetMyImageList()->NewNode( new Node<ImageFile>(_imageID, new ImageFile(_image)) );

	GetMyImageList()->GetNode(_imageID)->GetNodeData()->SetImageW(RenderManager::GetRenderManager()->GetLocalSurface()->w);
	GetMyImageList()->GetNode(_imageID)->GetNodeData()->SetImageH(RenderManager::GetRenderManager()->GetLocalSurface()->h);
}

//////////////////Message List

void ListManager::CreateMyMessageList()
{
	myMessageList = new DynamicList<Message>(NULL);
}

DynamicList<Message>* ListManager::GetMyMessageList() const
{
	return myMessageList;
}

void ListManager::NewMessageToTheList(std::string _myString, int _charsetCode, float _x, float _y, int _lifeTime, int _nodeID )
{
	GetMyMessageList()->NewNode( new Node<Message>(_nodeID, new Message(_myString, _charsetCode, _x, _y, _lifeTime) ));
}



/////////////////Music List

void ListManager::CreateMyMusicList()
{
	myMusicList = new DynamicList<MusicFile>(NULL );
}

DynamicList<MusicFile>* ListManager::GetMyMusicList() const
{
	return myMusicList;
}

void ListManager::NewMusicToTheList( char* _fileName, int _musicID )
{
	GetMyMusicList()->NewNode( new Node<MusicFile>(_musicID, new MusicFile(_fileName)) );
}



//////////////////Sfx List

void ListManager::CreateMySfxList()
{
	mySfxList = new DynamicList<SfxFile>(NULL );
}

DynamicList<SfxFile>* ListManager::GetMySfxList() const
{
	return mySfxList;
}

void ListManager::NewSfxToTheList( char* _sfxName, int _sfxID )
{
	GetMySfxList()->NewNode( new Node<SfxFile>(_sfxID, new SfxFile(_sfxName)) );
}
#ifndef SCENE_H_
#define SCENE_H_

#include <windows.h>

#include <GL/glu.h>

#include "SDL.h"
#include "SDL_image.h"
#include "DynamicList.h"
#include "RenderManager.h"
//#include "Message.h"
#include "ImageFile.h"
#include "MusicFile.h"
#include "SfxFile.h"
#include "FPSControl.h"
#include "GenericObject.h"
#include "ListManager.h"
//#include "FontManager.h"

#include <fstream>

enum
{
    STATE_INVALID = -1
	,STATE_SPLASHSCREEN
	,STATE_MENU
	,STATE_OPTIONS
	,STATE_CREDITS
	,STATE_INGAME

};

class Scene
{
public:
	Scene(int myState);
	virtual ~Scene();

	//override.
	virtual void Setup();
	virtual void Input();
	virtual void Update();
	virtual void Draw();
	virtual void TearDown();

	//sets e gets
	void SetDone(bool done); //finalização do aplicativo
	bool GetDone() const;

	//mudança de estados (cenas)
	void SetDesiredState(int state);
	int GetDesiredState() const;
	int GetMyState() const;

	//outras
	void DrawMessages();
	void DrawIt(GenericObject* _myGenericObject);

	SDL_Event event;

	DynamicList<GenericObject>* GetMyRenderList() const;
	void CreateMyRenderList();
	void NewRenderToTheList(GenericObject* _genericObject, int _renderID);


	template <typename T>
	void NewObjectToTheList( T** _genericObject, T* _newGenericObject )
	{
		*_genericObject = _newGenericObject;

		NewRenderToTheList(*_genericObject, GenerateObjectID());
	}

	//void NewObjectToTheList(GenericObject** _genericObject, GenericObject* _newGenericObject);
	//GenericObject* NewObjectToTheList(GenericObject* _newGenericObject);

	int GenerateObjectID();

private:

	DynamicList<GenericObject>* renderList;

	bool done;

	int myState;
	int desiredState;

};

#endif
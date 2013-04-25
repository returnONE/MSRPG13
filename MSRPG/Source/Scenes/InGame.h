#ifndef INGAME_H_
#define INGAME_H_

#include "Scene.h"
#include "Button.h"
#include "Background.h"
#include "Character.h"
#include "MapManager.h"
#include "Ground.h"
#include "FixedObject.h"
#include "MovablePickableObject.h"

#include "Tmx.h"

#define HALF_SCREEN_WIDTH_IN_TILES 10
#define HALF_SCREEN_HEIGHT_IN_TILES 9
#define HORIZONTAL_MARGIN 72
#define VERTICAL_MARGIN 648

class InGame : public Scene
{
public:
	InGame();
	~InGame();

	//inherited
	void InGame::Setup();
	void InGame::Input();
	void InGame::Update();
	void InGame::Draw();
	void InGame::TearDown();

	//outras
	void DrawGroundLayer(vector< vector <Ground*> > &_matrix, int _xCharacterTile, int _yCharacterTile, int _yScreenTile);
	void DrawFixedObjectLayer(vector< vector <FixedObject*> > &_matrix, int _xCharacterTile, int _yCharacterTile, int _yScreenTile);
	void DrawMovablePickableObjectLayer(vector< vector <MovablePickableObject*> > &_matrix, int _xCharacterTile, int _yCharacterTile, int _yScreenTile);
	void DrawCharacterLayer(vector< vector <Character*> > &_matrix, int _xCharacterTile, int _yCharacterTile, int _yScreenTile);

	void SetScreenOffsets();
	void VerifyButtons(int _x, int _y);
	Character* GetMainCharacter();

private:

	vector< vector <Ground*> > groundMatrix;
	vector< vector <FixedObject*> > fixedObjectsMatrix;
	vector< vector <MovablePickableObject*> > movablePickableObjectsMatrix;
	vector< vector <Character*> > characterMatrix;

	//Ground* sand;
	//Ground* brick;
	Character* mMainCharacter;

	MapManager* mMapManager;

};

#endif
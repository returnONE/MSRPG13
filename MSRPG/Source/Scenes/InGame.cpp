#include "InGame.h"

#include "SDL.h"
#include "SDL_image.h"

#include <windows.h>
#include <GL/glu.h>

#include "Button.h"

InGame::InGame():
Scene(STATE_INGAME)
{
	mMapManager = new MapManager("Data/Maps/map.tmx");

	SetDone(0);
}

InGame::~InGame()
{
	if(mMapManager)
		delete mMapManager;
	if(ListManager::GetListManager()->GetMyImageList())
		ListManager::GetListManager()->GetMyImageList()->DeleteList();
	if(ListManager::GetListManager()->GetMyMessageList())
		ListManager::GetListManager()->GetMyMessageList()->DeleteList();
	if(ListManager::GetListManager()->GetMySfxList())
		ListManager::GetListManager()->GetMySfxList()->DeleteList();
	if(ListManager::GetListManager()->GetMyMusicList())
		ListManager::GetListManager()->GetMyMusicList()->DeleteList();
	if(GetMyRenderList())
		GetMyRenderList()->DeleteList();
}

void InGame::Setup()
{
	SetDesiredState(GetMyState());

	ListManager::GetListManager()->NewImageToTheList(RenderManager::GetRenderManager()->LoadTexture("Data/Images/char2.png"), IMAGE_CHARACTER1);
	ListManager::GetListManager()->NewImageToTheList(RenderManager::GetRenderManager()->LoadTexture("Data/Images/tileset1.png"), IMAGE_TILESET);
	ListManager::GetListManager()->NewImageToTheList(RenderManager::GetRenderManager()->LoadTexture("Data/Images/tileset2.png"), IMAGE_TILESET2);

	mMapManager->PopulateGroundMatrixMap(groundMatrix, LAYER_GROUND1);
	mMapManager->PopulateFixedObjectMatrixMap(fixedObjectsMatrix, LAYER_FIXED1);
	mMapManager->PopulateMovablePickableMatrixMap(movablePickableObjectsMatrix, LAYER_MOVABLE_PICKABLE1);
	mMapManager->PopulateCharacterMatrixMap(characterMatrix, LAYER_CHARACTER1);

	mMainCharacter = GetMainCharacter();

	//SetScreenOffsets();
}

void InGame::Input()
{
	SDL_Event event;

	while( SDL_PollEvent( &event ) )
	{
		switch( event.type ){
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym){
			case SDLK_LEFT:
				if(mMainCharacter->GetState() == STAND_LEFT){
					mMainCharacter->SetState(STAND_LEFT);
				}
				else{
					mMainCharacter->SetState(STAND_LEFT);
				}
				break;
			case SDLK_RIGHT:
				if(mMainCharacter->GetState() == STAND_RIGHT){
					mMainCharacter->SetState(STAND_RIGHT);
				}
				else{
					mMainCharacter->SetState(STAND_RIGHT);
				}
				break;
			case SDLK_UP:
				if(mMainCharacter->GetState() == WALKING_UP){
					mMainCharacter->SetState(WALKING_UP);
					//mMainCharacter->MoveUp(characterMatrix);
				}
				else{
					mMainCharacter->SetState(STAND_UP);
				}
				break;
			case SDLK_DOWN:
				if(mMainCharacter->GetState() == STAND_DOWN){
					mMainCharacter->SetState(WALKING_DOWN);
				}
				else{
					mMainCharacter->SetState(STAND_DOWN);
				}
				break;
			default:
				break;
				}
			case SDL_MOUSEBUTTONDOWN:
				switch( event.button.state ){
			case SDL_PRESSED:
				VerifyButtons(event.button.x, event.button.y);
				break;
			default:
				break;
				}
				break;
			case SDL_QUIT:
				SetDone(1);
				break;
		}
	}
}

void InGame::Update()
{
	//int state = Button1->IsPressed();

	//if (state >= 0)
	//	SetDesiredState(state);
}

void InGame::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	//for each line
	for(int i = 0; i < SCREEN_LINE_NUMBER; i++)
	{
		DrawGroundLayer(                               groundMatrix, mMainCharacter->GetGlobalPosition().xGlobalPosition, mMainCharacter->GetGlobalPosition().yGlobalPosition + i, i);
		DrawFixedObjectLayer(                    fixedObjectsMatrix, mMainCharacter->GetGlobalPosition().xGlobalPosition, mMainCharacter->GetGlobalPosition().yGlobalPosition + i, i);
		DrawMovablePickableObjectLayer(movablePickableObjectsMatrix, mMainCharacter->GetGlobalPosition().xGlobalPosition, mMainCharacter->GetGlobalPosition().yGlobalPosition + i, i);
		DrawCharacterLayer(                         characterMatrix, mMainCharacter->GetGlobalPosition().xGlobalPosition, mMainCharacter->GetGlobalPosition().yGlobalPosition + i, i);
	}

	//DrawFPS();

	SDL_GL_SwapBuffers();
}

void InGame::DrawGroundLayer(vector< vector <Ground*> > &_matrix, int _xCharacterTile, int _yCharacterTile, int _yScreenTile)
{
	int xMapTile = _xCharacterTile - HALF_SCREEN_WIDTH_IN_TILES;
	int yMapTile = _yCharacterTile - HALF_SCREEN_HEIGHT_IN_TILES;

	int xScreenTile;

	for (int i = 0; i < SCREEN_COLUMN_NUMBER; i++)
	{
		xScreenTile = i;

		int xScreen = HORIZONTAL_MARGIN + (mMapManager->GetMap()->GetTileWidth() *  xScreenTile);
		int yScreen = VERTICAL_MARGIN - (mMapManager->GetMap()->GetTileHeight() * _yScreenTile);

		if(_matrix[yMapTile][i+xMapTile])
		{
			RenderManager::GetRenderManager()->RenderSprite(
				_matrix[yMapTile][i+xMapTile]->GetMyAnimatedSprite()->GetCurrentSpriteFrame(_matrix[yMapTile][i+xMapTile]->GetState(), 0),
				xScreen,
				yScreen,
				xScreen + mMapManager->GetMap()->GetTileWidth(),
				yScreen + mMapManager->GetMap()->GetTileHeight(),
				_matrix[yMapTile][i+xMapTile]->GetMyAnimatedSprite()->GetImage() );
		}

	}
	

}

void InGame::DrawFixedObjectLayer(vector< vector <FixedObject*> > &_matrix, int _xCharacterTile, int _yCharacterTile, int _yScreenTile)
{
	int xMapTile = _xCharacterTile - HALF_SCREEN_WIDTH_IN_TILES;
	int yMapTile = _yCharacterTile - HALF_SCREEN_HEIGHT_IN_TILES;

	int xScreenTile;

	for (int i = 0; i < SCREEN_COLUMN_NUMBER; i++)
	{
		xScreenTile = i;

		int xScreen = HORIZONTAL_MARGIN + (mMapManager->GetMap()->GetTileWidth() *  xScreenTile);
		int yScreen = VERTICAL_MARGIN - (mMapManager->GetMap()->GetTileHeight() * _yScreenTile);

		if(_matrix[yMapTile][i+xMapTile])
		{
			RenderManager::GetRenderManager()->RenderSprite(
				_matrix[yMapTile][i+xMapTile]->GetMyAnimatedSprite()->GetCurrentSpriteFrame(_matrix[yMapTile][i+xMapTile]->GetState(), 0),
				xScreen,
				yScreen,
				xScreen + mMapManager->GetMap()->GetTileWidth(),
				yScreen + mMapManager->GetMap()->GetTileHeight(),
				_matrix[yMapTile][i+xMapTile]->GetMyAnimatedSprite()->GetImage() );
		}

	}


}

void InGame::DrawMovablePickableObjectLayer(vector< vector <MovablePickableObject*> > &_matrix, int _xCharacterTile, int _yCharacterTile, int _yScreenTile)
{
	int xMapTile = _xCharacterTile - HALF_SCREEN_WIDTH_IN_TILES;
	int yMapTile = _yCharacterTile - HALF_SCREEN_HEIGHT_IN_TILES;

	int xScreenTile;

	for (int i = 0; i < SCREEN_COLUMN_NUMBER; i++)
	{
		xScreenTile = i;

		int xScreen = HORIZONTAL_MARGIN + (mMapManager->GetMap()->GetTileWidth() *  xScreenTile);
		int yScreen = VERTICAL_MARGIN - (mMapManager->GetMap()->GetTileHeight() * _yScreenTile);

		if(_matrix[yMapTile][i+xMapTile])
		{
			RenderManager::GetRenderManager()->RenderSprite(
				_matrix[yMapTile][i+xMapTile]->GetMyAnimatedSprite()->GetCurrentSpriteFrame(_matrix[yMapTile][i+xMapTile]->GetState(), 0),
				xScreen,
				yScreen,
				xScreen + mMapManager->GetMap()->GetTileWidth(),
				yScreen + mMapManager->GetMap()->GetTileHeight(),
				_matrix[yMapTile][i+xMapTile]->GetMyAnimatedSprite()->GetImage() );
		}

	}


}

void InGame::DrawCharacterLayer( vector< vector <Character*> > &_matrix, int _xCharacterTile, int _yCharacterTile, int _yScreenTile )
{
	int xMapTile = _xCharacterTile - HALF_SCREEN_WIDTH_IN_TILES;
	int yMapTile = _yCharacterTile - HALF_SCREEN_HEIGHT_IN_TILES;

	int xScreenTile;

	for (int i = 0; i < SCREEN_COLUMN_NUMBER; i++)
	{
		xScreenTile = i;

		int xScreen = HORIZONTAL_MARGIN + (mMapManager->GetMap()->GetTileWidth() *  xScreenTile);
		int yScreen = VERTICAL_MARGIN - (mMapManager->GetMap()->GetTileHeight() * _yScreenTile);

		if(_matrix[yMapTile][i+xMapTile])
		{
			RenderManager::GetRenderManager()->RenderSprite(
				_matrix[yMapTile][i+xMapTile]->GetMyAnimatedSprite()->GetCurrentSpriteFrame(_matrix[yMapTile][i+xMapTile]->GetState(), 200),
				xScreen,
				yScreen,
				xScreen + mMapManager->GetMap()->GetTileWidth(),
				yScreen + mMapManager->GetMap()->GetTileHeight(),
				_matrix[yMapTile][i+xMapTile]->GetMyAnimatedSprite()->GetImage() );
		}

	}
}

void InGame::TearDown()
{

}

void InGame::VerifyButtons( int _x, int _y )
{
	//if(Button1->IsButtonArea(_x, _y))
	//	Button1->SetState(PRESSED);
}

Character* InGame::GetMainCharacter()
{
	for (int i=0; i < characterMatrix.size(); i++)
	{
		for (int j=0; j < characterMatrix[i].size(); j++)
		{
			if(characterMatrix[i][j])
			{
				if ( characterMatrix[i][j]->GetObjectID() == OBJECT_MAIN_CHARACTER )
				{
					return characterMatrix[i][j];
				}
			}
		}
	}

	return 0;
}

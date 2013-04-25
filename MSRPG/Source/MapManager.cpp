#include "MapManager.h"

MapManager::MapManager(const string &_fileName)
{
	mMap = new Tmx::Map();
	mMap->ParseFile(_fileName);

	if (mMap->HasError()) {
		printf("error code: %d\n", mMap->GetErrorCode());
		printf("error text: %s\n", mMap->GetErrorText().c_str());

		system("PAUSE");

	}
}

MapManager::~MapManager(void)
{
}

void MapManager::PopulateGroundMatrixMap(vector< vector<Ground*> > &_groundMatrix, int _layer)
{
	_groundMatrix.resize(GetMap()->GetHeight());

	for(int i=0; i < GetMap()->GetHeight(); i++)
	{
		vector <Ground*> _groundVector;

		_groundVector.resize(GetMap()->GetWidth());

		for(int j=0; j < GetMap()->GetWidth(); j++)
		{
			//verifica que imagem esse tile esta usando
			int tilesetID = GetMap()->GetLayer(_layer)->GetTileTilesetIndex(j, i);

			if (_layer)
			{
				int x=1;
			}

			//pega lista de propriedades de determinado tile
			if(tilesetID >= 0)
			{
				map<string, string> properties = GetMap()->GetTileset(tilesetID)->GetTile( GetMap()->GetLayer(_layer)->GetTileId(j, i) )->GetProperties().GetList();

				//recebe valor de animationID
				map<string, string>::iterator iter;
				iter = properties.begin();
				string tempString;
				tempString.append(iter->second);
				int animationID = atoi(tempString.c_str());
				//recebe valor de objectID
				iter++;
				tempString.clear();
				tempString.append(iter->second);
				int objectID = atoi(tempString.c_str());

				//instancia na matriz o objeto encontrado no mapa
				_groundVector[j] = new Ground(animationID, 0, objectID, j, i);

			}
			else
			{
				_groundVector[j] = NULL;
			}
		}
		
		_groundMatrix[i] = _groundVector;
	}

	//return _groundMatrix;
}

void MapManager::PopulateFixedObjectMatrixMap( vector< vector<FixedObject*> > &_fixedObjectMatrix, int _layer )
{
	_fixedObjectMatrix.resize(GetMap()->GetHeight());

	for(int i=0; i < GetMap()->GetHeight(); i++)
	{
		vector <FixedObject*> _fixedObjectVector;

		_fixedObjectVector.resize(GetMap()->GetWidth());

		for(int j=0; j < GetMap()->GetWidth(); j++)
		{
			//verifica que imagem esse tile esta usando
			int tilesetID = GetMap()->GetLayer(_layer)->GetTileTilesetIndex(j, i);

			if (_layer)
			{
				int x=1;
			}

			//pega lista de propriedades de determinado tile
			if(tilesetID >= 0)
			{
				map<string, string> properties = GetMap()->GetTileset(tilesetID)->GetTile( GetMap()->GetLayer(_layer)->GetTileId(j, i) )->GetProperties().GetList();

				//recebe valor de animationID
				map<string, string>::iterator iter;
				iter = properties.begin();
				string tempString;
				tempString.append(iter->second);
				int animationID = atoi(tempString.c_str());
				//recebe valor de objectID
				iter++;
				tempString.clear();
				tempString.append(iter->second);
				int objectID = atoi(tempString.c_str());

				//instancia na matriz o objeto encontrado no mapa
				_fixedObjectVector[j] = new FixedObject(animationID, 0, objectID, j, i);

			}
			else
			{
				_fixedObjectVector[j] = NULL;
			}
		}

		_fixedObjectMatrix[i] = _fixedObjectVector;
	}
}

void MapManager::PopulateMovablePickableMatrixMap( vector< vector<MovablePickableObject*> > &_movablePickableObjectMatrix, int _layer )
{
	_movablePickableObjectMatrix.resize(GetMap()->GetHeight());

	for(int i=0; i < GetMap()->GetHeight(); i++)
	{
		vector <MovablePickableObject*> _movablePickableObjectVector;

		_movablePickableObjectVector.resize(GetMap()->GetWidth());

		for(int j=0; j < GetMap()->GetWidth(); j++)
		{
			//verifica que imagem esse tile esta usando
			int tilesetID = GetMap()->GetLayer(_layer)->GetTileTilesetIndex(j, i);

			if (_layer)
			{
				int x=1;
			}

			//pega lista de propriedades de determinado tile
			if(tilesetID >= 0)
			{
				map<string, string> properties = GetMap()->GetTileset(tilesetID)->GetTile( GetMap()->GetLayer(_layer)->GetTileId(j, i) )->GetProperties().GetList();

				//recebe valor de animationID
				map<string, string>::iterator iter;
				iter = properties.begin();
				string tempString;
				tempString.append(iter->second);
				int animationID = atoi(tempString.c_str());
				//recebe valor de objectID
				iter++;
				tempString.clear();
				tempString.append(iter->second);
				int objectID = atoi(tempString.c_str());

				//instancia na matriz o objeto encontrado no mapa
				_movablePickableObjectVector[j] = new MovablePickableObject(animationID, 0, objectID, j, i);

			}
			else
			{
				_movablePickableObjectVector[j] = NULL;
			}
		}

		_movablePickableObjectMatrix[i] = _movablePickableObjectVector;
	}
}

void MapManager::PopulateCharacterMatrixMap( vector< vector<Character*> > &_fixedObjectMatrix, int _layer )
{
	_fixedObjectMatrix.resize(GetMap()->GetHeight());

	for(int i=0; i < GetMap()->GetHeight(); i++)
	{
		vector <Character*> _characterVector;

		_characterVector.resize(GetMap()->GetWidth());

		for(int j=0; j < GetMap()->GetWidth(); j++)
		{
			//verifica que imagem esse tile esta usando
			int tilesetID = GetMap()->GetLayer(_layer)->GetTileTilesetIndex(j, i);

			if (_layer)
			{
				int x=1;
			}

			//pega lista de propriedades de determinado tile
			if(tilesetID >= 0)
			{
				map<string, string> properties = GetMap()->GetTileset(tilesetID)->GetTile( GetMap()->GetLayer(_layer)->GetTileId(j, i) )->GetProperties().GetList();

				//recebe valor de animationID
				map<string, string>::iterator iter;
				iter = properties.begin();
				string tempString;
				tempString.append(iter->second);
				int animationID = atoi(tempString.c_str());
				//recebe valor de objectID
				iter++;
				tempString.clear();
				tempString.append(iter->second);
				int objectID = atoi(tempString.c_str());

				//instancia na matriz o objeto encontrado no mapa
				_characterVector[j] = new Character(animationID, 2, objectID, j, i);

			}
			else
			{
				_characterVector[j] = NULL;
			}
		}

		_fixedObjectMatrix[i] = _characterVector;
	}
}

#ifndef MAPMANAGER_H_
#define MAPMANAGER_H_

#include "Tmx.h"
#include "Ground.h"
#include "FixedObject.h"
#include "MovablePickableObject.h"
#include "Character.h"

#include <map>

using namespace std;

class MapManager
{
public:
	MapManager(const string &_fileName);
	~MapManager(void);

	Tmx::Map* GetMap() const { return mMap; }
	void PopulateGroundMatrixMap( vector< vector<Ground*> > &_groundMatrix, int _layer );
	void PopulateFixedObjectMatrixMap( vector< vector<FixedObject*> > &_fixedObjectMatrix, int _layer );
	void PopulateMovablePickableMatrixMap( vector< vector<MovablePickableObject*> > &_fixedObjectMatrix, int _layer );
	void PopulateCharacterMatrixMap( vector< vector<Character*> > &_fixedObjectMatrix, int _layer );

private:
	Tmx::Map* mMap;

};

#endif
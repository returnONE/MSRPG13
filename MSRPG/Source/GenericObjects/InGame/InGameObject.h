#ifndef INGAMEOBJECT_H_
#define INGAMEOBJECT_H_

#include "GenericObject.h"

struct globalPosition
{
	int xGlobalPosition;
	int yGlobalPosition;
};

class InGameObject : public GenericObject
{
public:

	InGameObject(unsigned int _animationID, int _state, unsigned int _objectID, int _xGlobalPosition, int _yGlobalPosition);
	virtual ~InGameObject(void);
	unsigned int GetObjectID() const { return objectID; }
	void SetObjectID(unsigned int _objectID) { objectID = _objectID; }
	globalPosition GetGlobalPosition() const { return mGlobalPosition; }
	void SetGlobalPosition(int _xGlobalPosition, int _yGlobalPosition);
	bool IsPickable() const { return pickable; }
	void SetPickable(bool _pickable) { pickable = _pickable; }
	bool IsMovable() const { return movable; }
	void SetMovable(bool _movable) { movable = _movable; }
	bool IsCollidable() const { return collidable; }
	void SetCollidable(bool _collidable) { collidable = _collidable; }

private:

	unsigned int objectID;

	globalPosition mGlobalPosition;

	bool pickable;
	bool movable;
	bool collidable;

};

#endif
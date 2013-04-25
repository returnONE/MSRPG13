#include "GenericObject.h"

GenericObject::GenericObject(unsigned int _animationID, int _state):
screenX0(-99999),
screenY0(-99999),
screenX1(-99999),
screenY1(-99999)
{
	state = _state;
	animationTime = 0;
	visible = true;
	myAnimatedSprite = new AnimatedSprite(_animationID);
	SetTexture(AnimationManager::GetAnimationManager()->GetAnimationData(_animationID));
}

GenericObject::GenericObject()
{

}

GenericObject::~GenericObject()
{
	delete myAnimatedSprite;
}

int GenericObject::GetScreenX0() const
{
	return screenX0;
}

void GenericObject::SetScreenX0(int _x)
{
	screenX0 = _x;
}

int GenericObject::GetScreenX1() const
{
	return screenX1;
}

void GenericObject::SetScreenX1(int _x)
{
	screenX1 = _x;
}

int GenericObject::GetScreenY0() const
{
	return screenY0;
}

void GenericObject::SetScreenY0(int _y)
{
	screenY0 = _y;
}

int GenericObject::GetScreenY1() const
{
	return screenY1;
}

void GenericObject::SetScreenY1(int _y)
{
	screenY1 = _y;
}

bool GenericObject::Update() //vai ter override na classe filha
{
	return 0;
}

void GenericObject::Setup() //vai ter override na classe filha
{

}

AnimatedSprite* GenericObject::GetMyAnimatedSprite()
{
	return myAnimatedSprite;
}

int GenericObject::GetState() const
{
	return state;
}

void GenericObject::SetState( int _state )
{
	state = _state;
}

int GenericObject::GetAnimationTime() const
{
	return animationTime;
}

void GenericObject::SetAnimationTime( int _animationTime )
{
	animationTime = _animationTime;
}

void GenericObject::SetTexture( AnimationData* _animationData )
{
	for (int i = 0; i < _animationData->stateList.size(); i++) //looping pra cada estado
	{
		GetMyAnimatedSprite()->NewAnimationState();

		for (int j = 0; j < _animationData->stateList[i].frameList.size(); j++) //looping pra cada frame
		{
			GetMyAnimatedSprite()->GetAnimationState(i)->NewSpriteFrame();

			for (int k = 0; k < _animationData->stateList[i].frameList[j].spriteList.size(); k++) //looping pra cada sprite
			{
				GetMyAnimatedSprite()->GetAnimationState(i)->GetSpriteFrame(j)->NewSprite();

				GetMyAnimatedSprite()->GetAnimationState(i)->GetSpriteFrame(j)->GetSprite(k)->SetSpriteTextureOffset(
					  _animationData->stateList[i].frameList[j].spriteList[k].xTex0
					, _animationData->stateList[i].frameList[j].spriteList[k].xTex1
					, _animationData->stateList[i].frameList[j].spriteList[k].yTex0
					, _animationData->stateList[i].frameList[j].spriteList[k].yTex1
					, _animationData->stateList[i].frameList[j].spriteList[k].xRelative
					, _animationData->stateList[i].frameList[j].spriteList[k].yRelative
					, ListManager::GetListManager()->GetMyImageList()->GetNode(_animationData->imageID)->GetNodeData()->GetImageW()
					, ListManager::GetListManager()->GetMyImageList()->GetNode(_animationData->imageID)->GetNodeData()->GetImageH() );

			}
		}
	}
}

void GenericObject::SetVisibility( bool _visible )
{
	visible = _visible;
}

bool GenericObject::IsVisible()
{
	return visible;
}

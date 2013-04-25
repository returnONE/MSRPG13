#include "Scene.h"

Scene::Scene(int _myState):
myState(_myState)
{
	ListManager::GetListManager()->CreateMyImageList();
	ListManager::GetListManager()->CreateMyMessageList();
	ListManager::GetListManager()->CreateMySfxList();
	ListManager::GetListManager()->CreateMyMusicList();
	CreateMyRenderList();
}

Scene::~Scene()
{
	RenderManager::GetRenderManager()->SceneExchange();
	//cada scene decide o que vai deletar e o que vai deixar na memória para a scene seguinte
}

bool Scene::GetDone() const
{
	return done;
}

void Scene::SetDone(bool _done)
{
	done = _done;
}

int Scene::GetDesiredState() const
{
	return desiredState;
}

void Scene::SetDesiredState(int _desiredState)
{
	desiredState = _desiredState;
}

int Scene::GetMyState() const
{
	return myState;
}

void Scene::Setup() //vai ter override na classe filha
{

}

void Scene::Input() //vai ter override na classe filha
{

}

void Scene::Update() //vai ter override na classe filha
{

}

void Scene::Draw() //pode ter override na classe filha
{
	glClear(GL_COLOR_BUFFER_BIT);

	//desenha objetos que estão visíveis na scene
	int currentNodeID = GetMyRenderList()->GetHead()->GetNodeID();

	while(currentNodeID != -9999)
	{
		if(GetMyRenderList()->GetNode(currentNodeID)->GetNodeData()->IsVisible())
			DrawIt(GetMyRenderList()->GetNode(currentNodeID)->GetNodeData());

		if(GetMyRenderList()->GetNode(currentNodeID)->GetNext())
			currentNodeID = GetMyRenderList()->GetNode(currentNodeID)->GetNext()->GetNodeID();
		else
			currentNodeID = -9999;
	}

	//Desenha mensagens visiveis na scene
	DrawMessages(); 

	SDL_GL_SwapBuffers();
}

void Scene::TearDown() //vai ter override na classe filha
{

}

void Scene::DrawMessages()
{
	Node<Message>* Finder = ListManager::GetListManager()->GetMyMessageList()->GetHead();
	if(!Finder) //se não foi encontrada uma primeira mensagem, não há mensagem para ser renderizada
		return;

	while(Finder)
	{
		RenderManager::GetRenderManager()->RenderFont(Finder->GetNodeData()->GetMyString(), Finder->GetNodeData()->GetMyCharSet(),
			Finder->GetNodeData()->GetMessageX(), Finder->GetNodeData()->GetMessageY());

		if(!Finder->GetNodeData()->VerifyMessageDuration())
		{
			ListManager::GetListManager()->GetMyMessageList()->Delete(Finder->GetNodeID());
			Finder = ListManager::GetListManager()->GetMyMessageList()->GetHead();
		}
		else
		{
			Finder = Finder->GetNext();
		}
	}
}

void Scene::DrawIt( GenericObject* _myGenericObject )
{
	RenderManager::GetRenderManager()->RenderSprite( _myGenericObject->GetMyAnimatedSprite()->GetCurrentSpriteFrame(_myGenericObject->GetState(), _myGenericObject->GetAnimationTime()),
		_myGenericObject->GetScreenX0(), _myGenericObject->GetScreenY0(), _myGenericObject->GetScreenX1(), _myGenericObject->GetScreenY1(),  _myGenericObject->GetMyAnimatedSprite()->GetImage());
}

void Scene::CreateMyRenderList()
{
	renderList = new DynamicList<GenericObject>(new Node<GenericObject>(-9999, NULL) );
}

DynamicList<GenericObject>* Scene::GetMyRenderList() const
{
	return renderList;
}

void Scene::NewRenderToTheList( GenericObject* _genericObject, int _renderID )
{
	GetMyRenderList()->NewNode( new Node<GenericObject>(_renderID, _genericObject) );

}

//void Scene::NewObjectToTheList( GenericObject** _genericObject, GenericObject* _newGenericObject )
//{
//	*_genericObject = _newGenericObject;
//
//	NewRenderToTheList(*_genericObject, GenerateObjectID());
//}

//GenericObject* Scene::NewObjectToTheList(GenericObject* _newGenericObject )
//{
//
//	NewRenderToTheList(_newGenericObject, GenerateObjectID());
//}

int Scene::GenerateObjectID()
{
	int objectID = 0;

	while(GetMyRenderList()->GetNode(objectID))
	{
		objectID++;
	}

	return objectID;
}

#include "AnimationManager.h"

AnimationManager* AnimationManager::s_AnimationManager = 0;

AnimationManager* AnimationManager::GetAnimationManager (void) 
{

	if (s_AnimationManager == 0)
		s_AnimationManager = new AnimationManager;
	return s_AnimationManager;
}

void AnimationManager::ParseAnimationXML()
{
	FrameData* frameLocal = new FrameData;

	ifstream myfile("Data/Images/AnimationConfig.xml");
	rapidxml::xml_document<> doc;
	xml_node<> * root_node;

	vector<char> buffer((istreambuf_iterator<char>(myfile)), istreambuf_iterator<char>( ));
	buffer.push_back('\0');

	doc.parse<0>(&buffer[0]);

	root_node = doc.first_node("ANIMATION_CONFIGURATION");

	//pega o numero de animações que existem no xml e cria o vetor de animações com esse numero
	int numberOfAnimations = atoi(root_node->first_node("NUMBER_OF_ANIMATIONS")->value());
	vector <AnimationData> animationLocal;
	animationLocal.resize(numberOfAnimations);

	//entra no node de OBJECTS
	xml_node<> * animationNode = root_node->first_node("ANIMATION");

	for(int i=0; i < numberOfAnimations; i++)
	{
		//pega o numero dessa animação
		animationLocal[i].animationCode = atoi(animationNode->first_node("ANIMATION_CODE")->value());
		animationLocal[i].imageID = atoi(animationNode->first_node("IMAGE_ID")->value());

		//pega o numero de estados que essa animação tem e cria o vetor de estados
		int numberOfStates = atoi(animationNode->first_node("NUMBER_OF_STATES")->value());
		vector <StateData> stateLocal;
		stateLocal.resize(numberOfStates);

		xml_node<> * stateNode = animationNode->first_node("STATE");

		for(int j=0; j < numberOfStates; j++)
		{			
			stateLocal[j].stateCode = atoi(stateNode->first_node("STATE_CODE")->value());

			int numberOfFrames = atoi(stateNode->first_node("NUMBER_OF_FRAMES")->value());
			vector <FrameData> frameLocal;
			frameLocal.resize(numberOfFrames);

			xml_node<> * frameNode = stateNode->first_node("FRAME");

			for(int k=0; k < numberOfFrames; k++)
			{	
				frameLocal[k].frameCode = atoi(frameNode->first_node("FRAME_CODE")->value());

				int numberOfSprites = atoi(frameNode->first_node("NUMBER_OF_SPRITES")->value());
				vector <SpriteData> spriteLocal;
				spriteLocal.resize(numberOfSprites);

				xml_node<> * spriteNode = frameNode->first_node("SPRITE");

				for(int l=0; l < numberOfSprites; l++)
				{
					spriteLocal[l].xTex0 = atoi(spriteNode->first_node("X0")->value());
					spriteLocal[l].yTex0 = atoi(spriteNode->first_node("Y0")->value());
					spriteLocal[l].xTex1 = atoi(spriteNode->first_node("X1")->value());
					spriteLocal[l].yTex1 = atoi(spriteNode->first_node("Y1")->value());
					spriteLocal[l].xRelative = atoi(spriteNode->first_node("XRELATIVE")->value());
					spriteLocal[l].yRelative = atoi(spriteNode->first_node("YRELATIVE")->value());

					spriteNode = spriteNode->next_sibling();

				} 
				frameLocal[k].spriteList = spriteLocal;

				frameNode = frameNode->next_sibling();
			}
			//guarda dados coletados por frameLocal em stateLocal
			stateLocal[j].frameList = frameLocal;

			//avança para o proximo nó
			stateNode = stateNode->next_sibling();
		}

		animationLocal[i].stateList = stateLocal;

		animationNode = animationNode->next_sibling();		
	}

	animationList = animationLocal;
}

AnimationData* AnimationManager::GetAnimationData(unsigned int _animationCode)
{

	
	return &animationList[_animationCode];

}

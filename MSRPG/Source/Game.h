#ifndef GAME_H_
#define GAME_H_

class Scene;
#include "FPSControl.h"

class Game
{
public:
	Game();
	~Game();

	void InitWindow();
	int GameLooping();

	// gets and sets
	void SetCurrentState(int timer);
	int GetCurrentState() const;

	//outras
	void TearDownScene();
	void ChangeState(Scene* newState);
	void FirstStateChange(Scene* newState);
	void VerifyStateChange();
	void LastTearDown();
	void GameSetup();

private:
	Scene* TheScene;

	int currentState;

	bool done;
};

#endif

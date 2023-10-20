#pragma once
#include "Object.h"
#include "Core.h"
#include "VideoManager.h"

class Game
{
public:
	Game();
	virtual ~Game();

	virtual void GameLoop();
	virtual void OnUpdate();
	virtual void OnRender();

	std::vector<Object*> GetObjects() { return Objects; }
private:

	std::vector<Object*> Objects;
};


#pragma once
#include "Object.h"
#include "Core.h"
#include "VideoManager.h"

class Game
{
public:
	Game();
	~Game();

	static void OnUpdate();

private:
	std::vector<Object*> GetObjects() { return Objects; }

	std::vector<Object*> Objects;
};


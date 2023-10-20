#pragma once
#include "Game.h"


class Engine
{
public:
	Engine();
	~Engine();

	void EngineLoop();

	void OnUpdate();
	void OnRender();
};


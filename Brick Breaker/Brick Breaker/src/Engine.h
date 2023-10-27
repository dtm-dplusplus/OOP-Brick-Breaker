#pragma once
#include "Game.h"


class Engine
{
public:
	Engine();
	~Engine();

	static void EngineLoop();

	static void SetGame(Game*& _game) { s_Game = _game; }
private:
	static Game* s_Game;

	static void OnUpdate();
	static void OnRender();
};


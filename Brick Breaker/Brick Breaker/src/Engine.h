#pragma once
#include "Game.h"


class Engine
{
public:
	Engine();
	~Engine();

	static void EngineLoop();

	static void SetGame(Game*& _game) { m_Game = _game; }
private:
	static Game* m_Game;

	static void OnUpdate();
	static void OnRender();
};


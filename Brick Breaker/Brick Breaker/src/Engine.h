#pragma once
#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "Game.h"

class Engine
{
public:
	Engine();
	~Engine();

	bool GetIsRunning() const;
	static void EngineLoop();

	static void SetGame(Game*& _game) { s_Game = _game; }
private:
	static Game* s_Game;
	static bool isRunning;
	static void OnUpdate();
	static void OnRender();
};

#endif

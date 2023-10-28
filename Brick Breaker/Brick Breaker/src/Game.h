#pragma once
#ifndef _GAME_H_
#define _GAME_H_

#include "Level/Level.h"
#include "Level/DebugLevel.h"

class Game
{
public:
	Game();
	virtual ~Game();

	virtual void OnUpdate();
	virtual void OnRender();

private:
	Level* m_CurrentLevel;
	std::vector<Level*> m_Levels;
};

#endif

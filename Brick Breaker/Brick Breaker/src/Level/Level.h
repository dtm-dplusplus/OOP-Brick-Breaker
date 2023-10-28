#pragma once
#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "Core.h"
#include "Object.h"

class Level
{
public:
	Level();
	virtual ~Level() = default;

	std::string GetLevelName();
	void SetLevelName(const std::string& _name);

	std::vector<Object*> GetObjects();

	virtual void Load(){}
	virtual void Unload();

	virtual void OnUpdate(){}

protected:
	std::string m_LevelName;
	std::vector<Object*> m_LevelObjects;

	friend class Game;
};

#endif

#pragma once
#ifndef _DEBUGLEVEL_H_
#define _DEBUGLEVEL_H_

#include "Level.h"

class DebugLevel final : public Level
{
public:
	DebugLevel();
	~DebugLevel() override;
	void OnUpdate() override;

	void Load() override;
};

#endif

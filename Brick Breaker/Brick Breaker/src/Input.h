#pragma once

#include "Core.h"

class Input
{
public:
	static void PollInput();

	static int GetMouseMotionX();

private:
	static SDL_Event m_Event;
	static int MouseX, MouseY;
};


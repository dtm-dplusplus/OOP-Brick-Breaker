#pragma once
#ifndef _INPUT_H_
#define _INPUT_H_

#include "Core.h"

class Input
{
public:
	static void PollInput();

	static int GetMouseMotionX();

private:
	static SDL_Event s_Event;
	static int s_MouseX, s_MouseY;
};

#endif

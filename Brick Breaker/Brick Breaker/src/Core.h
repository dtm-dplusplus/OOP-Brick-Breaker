#pragma once
#ifndef _CORE_H_
#define _CORE_H_


#include <iostream>
#include <iomanip>
#include <string>
#include <string_view>

#include <vector>
#include <list>
#include <functional>

#include <glm.hpp>
#include <SDL.h>

struct Collider
{
	SDL_FRect Rect;
	SDL_Color Color;

	SDL_FRect& GetRect() { return Rect; }
	SDL_FRect GetRect() const { return Rect; }

	SDL_Color& GetColor() { return Color; }
	SDL_Color GetColor() const { return Color; }
};

#endif // _CORE_H_

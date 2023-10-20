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
	glm::vec4 Color;


	// Return Collider Bounds
	// Bounds Correspond to sides of window - left, right, top and bottom
	// 
	float GetBoundLeft() const { return Rect.x; }
	float GetBoundRight() const { return Rect.x + Rect.w; }
	float GetBoundTop() const { return Rect.y; }
	float GetBoundBottom() const { return Rect.y + Rect.h; }

	void Update(const glm::vec2& _position)
	{
		Rect.x = _position.x;
		Rect.y = _position.y;
	}
	SDL_FRect& GetRect() { return Rect; }
	SDL_FRect GetRect() const { return Rect; }

	glm::vec4& GetColor() { return Color; }
	glm::vec4  GetColor() const { return Color; }


};

#endif // _CORE_H_

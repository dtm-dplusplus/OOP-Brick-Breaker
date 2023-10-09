#pragma once

#include "Core.h"

class Renderer
{
public:
	static bool Startup();
	static bool Shutdown();

	static void ClearRenderer();
	static void UpdateRenderer();

	static void SetRenderDrawColor(const SDL_Color& _color) { SDL_SetRenderDrawColor(m_renderer, _color.r, _color.g, _color.b, _color.a); }

	static void RenderColliderF(const SDL_FRect& _col, const SDL_Color& _col_color);
	static void RenderPointF(const float _x, const float _y, const SDL_Color& _color = {0xff, 0x00, 0x00,0xFF});
private:
	static SDL_Renderer* m_renderer;

};
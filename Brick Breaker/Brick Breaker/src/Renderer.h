#pragma once

#include "Core.h"

class Renderer
{
public:
	static bool StartUp();
	static bool Shutdown();

	static SDL_Renderer*& GetSDLRenderer() { return m_renderer; }

	static void ClearRenderer();
	static void UpdateRenderer();

	static void SetRenderDrawColor(const SDL_Color& _color) { SDL_SetRenderDrawColor(m_renderer, _color.r, _color.g, _color.b, _color.a); }

	static void RenderRectF(const SDL_FRect& _col, const SDL_Color& _col_color);
	static void RenderPointF(float _x, float _y, const SDL_Color& _color);
private:
	static SDL_Renderer* m_renderer;
	static SDL_Color clearColor;

	static int renderScaleX;
	static int renderScaleY;
};
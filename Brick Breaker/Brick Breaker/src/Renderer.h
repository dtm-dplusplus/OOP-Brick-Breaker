#pragma once

#include "Core.h"
#include "Texture.h"



class Renderer
{
public:
	static bool StartUp();
	static bool Shutdown();

	static SDL_Renderer*& GetSDLRenderer();

	static void ClearRenderer();
	static void UpdateRenderer();

	static void SetRenderDrawColor(const SDL_Color& _color);

	static void RenderRectFill(const Collider*& _collider);
	static void RenderRectLine(Collider*& _collider);


	static void RenderPointF(float _x, float _y, const SDL_Color& _color);

	static void RenderTexture(Texture*& _texture, Collider*& _collider);

private:
	static SDL_Renderer* s_Renderer;
	static SDL_Color s_ClearColor;
};
#pragma once
#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "Core.h"
#include "Texture.h"

struct Collider
{
	SDL_FRect Rect;
	glm::vec4 Color{ 0x00, 0xFF,0x00,0xFF };
	bool RenderCollider{ false };

	void Update(const glm::vec2& _position)
	{
		Rect.x = _position.x;
		Rect.y = _position.y;
	}

	void Update(const float _x, const float _y)
	{
		Rect.x = _x;
		Rect.y = _y;
	}

	// Return m_Collider Bounds
	// Bounds Correspond to sides of window - left, right, top and bottom
	float GetBoundLeft() const { return Rect.x; }
	float GetBoundRight() const { return Rect.x + Rect.w; }
	float GetBoundTop() const { return Rect.y; }
	float GetBoundBottom() const { return Rect.y + Rect.h; }

	SDL_FRect& GetRect() { return Rect; }
	SDL_FRect GetRect() const { return Rect; }

	glm::vec4& GetColor() { return Color; }
	glm::vec4 GetColor() const { return Color; }

	bool& IsRenderCollider() { return RenderCollider; }
	bool IsRenderCollider() const { return RenderCollider; }
};

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

#endif

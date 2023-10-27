#include "Renderer.h"

#include "UI.h"
#include "Window.h"

SDL_Renderer* Renderer::s_Renderer{ NULL };
SDL_Color Renderer::s_ClearColor{ 0x00, 0x00, 0x00,0xFF };

bool Renderer::StartUp()
{
	s_Renderer = SDL_CreateRenderer(Window::GetSDLWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (s_Renderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
	}

	return true;
}

bool Renderer::Shutdown()
{
	SDL_DestroyRenderer(s_Renderer);

	return true;
}

SDL_Renderer*& Renderer::GetSDLRenderer()
{
	return s_Renderer;
}

void Renderer::ClearRenderer()
{
	SDL_SetRenderDrawColor(s_Renderer, s_ClearColor.r, s_ClearColor.g, s_ClearColor.b, s_ClearColor.a);
	SDL_RenderClear(s_Renderer);
}
void Renderer::UpdateRenderer()
{
	SDL_RenderSetScale(s_Renderer, UI::GetImGuiIO().DisplayFramebufferScale.x, UI::GetImGuiIO().DisplayFramebufferScale.y);
	SDL_RenderPresent(s_Renderer);
}

void Renderer::SetRenderDrawColor(const SDL_Color& _color)
{
	SDL_SetRenderDrawColor(s_Renderer, _color.r, _color.g, _color.b, _color.a);
}

void Renderer::RenderPointF(const float _x, const float _y, const SDL_Color& _color)
{
	SDL_SetRenderDrawColor(s_Renderer, _color.r, _color.g, _color.b, _color.a);
	SDL_RenderDrawPointF(s_Renderer, _x, _y);
}


void Renderer::RenderRectFill(const Collider*& _collider)
{
	SDL_SetRenderDrawColor(s_Renderer, (Uint8)_collider->Color.r, (Uint8)_collider->Color.g, (Uint8)_collider->Color.b, (Uint8)_collider->Color.a);
	SDL_RenderFillRectF(s_Renderer, &_collider->Rect);
}


void Renderer::RenderRectLine(Collider*& _collider)
{
	SDL_SetRenderDrawColor(s_Renderer, _collider->Color.r, _collider->Color.g, _collider->Color.b, _collider->Color.a);
	SDL_RenderDrawRectF(s_Renderer, &_collider->Rect);
}

void Renderer::RenderTexture(Texture*& _texture, Collider*& _collider)
{
	SDL_RenderCopyF(s_Renderer, _texture->GetTexture(), NULL, &_collider->GetRect());
}

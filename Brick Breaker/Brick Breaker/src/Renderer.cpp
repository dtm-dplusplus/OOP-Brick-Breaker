#include "Renderer.h"
#include "Window.h"

SDL_Renderer* Renderer::m_renderer{ NULL };

bool Renderer::Startup()
{
	m_renderer = SDL_CreateRenderer(Window::GetSDLWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_renderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
	}

	return true;
}

bool Renderer::Shutdown()
{
	SDL_DestroyRenderer(m_renderer);

	return true;
}

void Renderer::ClearRenderer()
{
	SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(m_renderer);
}
void Renderer::UpdateRenderer()
{
	SDL_RenderPresent(m_renderer);
}

void Renderer::RenderPointF(const float _x, const float _y, const SDL_Color& _color)
{
	SDL_SetRenderDrawColor(m_renderer, _color.r, _color.g, _color.b, _color.a);
	SDL_RenderDrawPointF(m_renderer, _x, _y);
}

void Renderer::RenderColliderF(const SDL_FRect& _col, const SDL_Color& _col_color)
{
	SDL_SetRenderDrawColor(m_renderer, _col_color.r, _col_color.g, _col_color.b, _col_color.a);
	SDL_RenderFillRectF(m_renderer, &_col);
}
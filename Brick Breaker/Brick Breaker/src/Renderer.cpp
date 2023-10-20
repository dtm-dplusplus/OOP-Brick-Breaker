#include "Renderer.h"

#include "UI.h"
#include "Window.h"

SDL_Renderer* Renderer::m_renderer{ NULL };
SDL_Color Renderer::clearColor{ 0x00, 0x00, 0x00,0xFF };
int Renderer::renderScaleX{Window::GetWidthI()};
int Renderer::renderScaleY{ Window::GetHeightI() };

bool Renderer::StartUp()
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
	SDL_SetRenderDrawColor(m_renderer, clearColor.r, clearColor.g, clearColor.b, clearColor.a);
	SDL_RenderClear(m_renderer);
}
void Renderer::UpdateRenderer()
{
	SDL_RenderSetScale(m_renderer, UI::GetImGuiIO().DisplayFramebufferScale.x, UI::GetImGuiIO().DisplayFramebufferScale.y);
	SDL_RenderPresent(m_renderer);
}

void Renderer::RenderPointF(const float _x, const float _y, const SDL_Color& _color)
{
	SDL_SetRenderDrawColor(m_renderer, _color.r, _color.g, _color.b, _color.a);
	SDL_RenderDrawPointF(m_renderer, _x, _y);
}

void Renderer::RenderRectFill(const Collider& _collider)
{
	SDL_SetRenderDrawColor(m_renderer, _collider.Color.r, _collider.Color.g, _collider.Color.b, _collider.Color.a);
	SDL_RenderFillRectF(m_renderer, &_collider.Rect);
}


void Renderer::RenderRectLine(const Collider& _collider)
{
	SDL_SetRenderDrawColor(m_renderer, _collider.Color.r, _collider.Color.g, _collider.Color.b, _collider.Color.a);
	SDL_RenderDrawRectF(m_renderer, &_collider.Rect);
}
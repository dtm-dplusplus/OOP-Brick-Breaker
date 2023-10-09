#include "VideoManager.h"

bool VideoManager::windowOpen{ true };

int VideoManager::m_WIN_W{ 720 };
int VideoManager::m_WIN_H{ 740 };

SDL_Window* VideoManager::m_window{ NULL };
SDL_Renderer* VideoManager::m_renderer{ NULL };

bool VideoManager::StartUp()
{
	// Initialise SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
	}

	// Create window
	m_window = SDL_CreateWindow("OOP Brick Breaker++", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_WIN_W, m_WIN_H, SDL_WINDOW_SHOWN);
	if (m_window == NULL)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
	}

	// Create renderer for window
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_renderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
	}

	return true;
}

bool VideoManager::Shutdown()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();

	return true;
}

void VideoManager::ClearRenderer()
{
	SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(m_renderer);
}
void VideoManager::UpdateRenderer()
{
	SDL_RenderPresent(m_renderer);
}

void VideoManager::RenderCollider(const SDL_Rect& _col, const SDL_Color& _col_color)
{
	SDL_SetRenderDrawColor(m_renderer, _col_color.r, _col_color.g, _col_color.b, _col_color.a);
	SDL_RenderFillRect(m_renderer, &_col);
}

void VideoManager::WindowLoop()
{
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0)
	{
		switch (event.type)
		{
			case SDL_KEYDOWN:
			{
				std::cout << "key down: " << std::to_string(event.key.keysym.sym) << std::endl;
			}

			case SDL_WINDOWEVENT:
			{
				switch (event.window.event)
				{
					case SDL_WINDOWEVENT_CLOSE:
					{
						windowOpen = false;
					}

					case SDL_WINDOWEVENT_RESIZED:
					{
						// Resize Function
					}

				default: {}
				}
			}

			default: {}
		}
	}

	ClearRenderer();

	SDL_SetRenderDrawColor(m_renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderDrawPoint(m_renderer, m_WIN_W/2, m_WIN_H/2);

	UpdateRenderer();
}

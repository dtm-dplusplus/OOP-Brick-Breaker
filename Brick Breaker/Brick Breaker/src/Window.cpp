#include "Window.h"

bool Window::windowOpen{ true };

int Window::m_winWidth{ 720 };
int Window::m_winHeight{ 480 };

SDL_Window* Window::m_window{ NULL };

bool Window::StartUp()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	m_window = SDL_CreateWindow("OOP Brick Breaker++", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_winWidth, m_winHeight, SDL_WINDOW_SHOWN);
	if (m_window == NULL)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	return true;
}

bool Window::Shutdown()
{
	SDL_DestroyWindow(m_window);

	return true;
}

#include "Window.h"

bool Window::s_windowOpen{ true };

int Window::s_winWidth{ 1280 };
int Window::s_winHeight{ 720 };

SDL_Window* Window::s_window{ NULL };

bool Window::StartUp()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	s_window = SDL_CreateWindow("OOP Brick Breaker++", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, s_winWidth, s_winHeight, SDL_WINDOW_SHOWN);
	if (s_window == NULL)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	//Initialize PNG loading
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return false;
	}

	return true;
}

bool Window::Shutdown()
{
	SDL_DestroyWindow(s_window);
	IMG_Quit();
	// Mix_Quit();

	return true;
}

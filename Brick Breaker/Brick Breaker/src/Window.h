#pragma once

#include "Core.h"


class Window
{
public:
	static bool Startup();
	static bool Shutdown();

	static SDL_Window*& GetSDLWindow() { return m_window; }

	static int GetWidth() { return m_winWidth; }
	static int GetHeight() { return m_winHeight; }

	static bool GetWindowOpen() { return windowOpen; }
	static void SetWindowOpen(const bool _window_open) { windowOpen = _window_open; }

private:
	static SDL_Window* m_window;

	static bool windowOpen;
	static int m_winWidth, m_winHeight;

};


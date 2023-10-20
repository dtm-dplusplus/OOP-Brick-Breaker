#pragma once

#include "Core.h"


class Window
{
public:
	static bool StartUp();
	static bool Shutdown();

	static SDL_Window*& GetSDLWindow() { return m_window; }


	static int GetWidthI() { return m_winWidth; }
	static int GetWidthHalfI() { return m_winWidth / 2; }
	static float GetWidthF() { return static_cast<float>(m_winWidth); }
	static float GetWidthHalfF() { return static_cast<float>(m_winWidth / 2); }

	static int GetHeightI() { return m_winHeight; }
	static int GetHeightHalfI() { return m_winHeight / 2; }
	static float GetHeightF() { return static_cast<float>(m_winHeight); }
	static float GetHeightHalfF() { return static_cast<float>(m_winHeight / 2); }


	static bool GetWindowOpen() { return windowOpen; }
	static void SetWindowOpen(const bool _window_open) { windowOpen = _window_open; }

private:
	static SDL_Window* m_window;

	static bool windowOpen;
	static int m_winWidth, m_winHeight;

};


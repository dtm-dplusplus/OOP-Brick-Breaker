#pragma once

#include "Core.h"


class Window
{
public:
	static bool StartUp();
	static bool Shutdown();

	static SDL_Window*& GetSDLWindow() { return s_window; }


	static int GetWidthI() { return s_winWidth; }
	static int GetWidthHalfI() { return s_winWidth / 2; }
	static float GetWidthF() { return static_cast<float>(s_winWidth); }
	static float GetWidthHalfF() { return static_cast<float>(s_winWidth / 2); }

	static int GetHeightI() { return s_winHeight; }
	static int GetHeightHalfI() { return s_winHeight / 2; }
	static float GetHeightF() { return static_cast<float>(s_winHeight); }
	static float GetHeightHalfF() { return static_cast<float>(s_winHeight / 2); }


	static bool GetWindowOpen() { return s_windowOpen; }
	static void SetWindowOpen(const bool _window_open) { s_windowOpen = _window_open; }

private:
	static SDL_Window* s_window;

	static bool s_windowOpen;
	static int s_winWidth, s_winHeight;

};


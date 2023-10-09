#pragma once

#include "Core.h"

class VideoManager
{
public:
	static bool StartUp();
	static bool Shutdown();

	static void WindowLoop();

	static void ClearRenderer();
	static void UpdateRenderer();

	static void RenderCollider(const SDL_Rect& _col, const SDL_Color& _col_color);

	static int GetWidth() { return m_WIN_W; }
	static int GetHeight() { return m_WIN_H; }

	static bool GetWindowOpen(){ return windowOpen; }
	static void SetWindowOpen(const bool _window_open) { windowOpen = _window_open; }

private:
	static int m_WIN_W, m_WIN_H;

	static SDL_Window* m_window;
	static SDL_Renderer* m_renderer;

	static bool windowOpen;
};


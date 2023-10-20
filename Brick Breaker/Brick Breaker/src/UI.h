#pragma once

#include "imgui_internal.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

class UI
{
public:
	static void StartUp();

	static ImGuiIO& GetImGuiIO() { return io; }
	static void ShutDown();

	static void ClearUI();
	static void RenderUI();
private:
	static ImGuiIO io;

};


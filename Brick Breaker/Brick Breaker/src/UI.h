#pragma once
#include "../vendor/imgui-master/imgui.h"
#include "../vendor/imgui-master/imgui_impl_sdl2.h"
#include "../vendor/imgui-master/imgui_impl_sdlrenderer2.h"

class UI
{
public:
	static void StartUp();

	static ImGuiIO& GetImGuiIO() { return io; };

	static void ClearUI();
	static void RenderUI();
private:
	static ImGuiIO io;
};


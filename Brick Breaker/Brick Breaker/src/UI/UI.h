#pragma once
#ifndef _UI_H_
#define _UI_H_


#include "Core.h"

#include "imgui.h"
#include "imgui_internal.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

class UI
{
public:
	static void StartUp();

	static ImGuiIO& GetImGuiIO() { return s_io; }
	static void ShutDown();

	static void ClearUI();
	static void RenderUI();
private:
	static ImGuiIO s_io;

};

#endif

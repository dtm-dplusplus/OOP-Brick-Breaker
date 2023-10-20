#include "VideoManager.h"

#include "Core.h"
#include "Window.h"
#include  "Renderer.h"
#include "UI.h"
#include "../vendor/imgui-master/imgui.h"
#include "../vendor/imgui-master/imgui_impl_sdl2.h"
#include "../vendor/imgui-master/imgui_internal.h"

bool VideoManager::StartUp()
{
	Window::StartUp();
	Renderer::StartUp();
	UI::StartUp();

	return true;
}

bool VideoManager::Shutdown()
{
	Window::Shutdown();
	Renderer::Shutdown();
	SDL_Quit();

	return true;
}

void VideoManager::WindowLoop()
{
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0)
	{
		ImGui_ImplSDL2_ProcessEvent(&event);
		switch (event.type)
		{
			case SDL_KEYDOWN:
			{
				std::cout << "key down: " << std::to_string(event.key.keysym.sym) << std::endl;
			}

			case SDL_MOUSEBUTTONDOWN:
			{
				std::cout << "mouse down: " << std::to_string(event.button.button) << std::endl;
			}
			case SDL_WINDOWEVENT:
			{
				switch (event.window.event)
				{
					case SDL_WINDOWEVENT_CLOSE:
					{
						Window::SetWindowOpen(false);
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

	Renderer::ClearRenderer();
	UI::ClearUI();

	if (static bool b{1})ImGui::ShowDemoWindow(&b);
		

	static float x{ Window::GetWidth() / 2.0f }, y{ Window::GetHeight() / 2.0f };
	Renderer::RenderPointF(x,y, {0xFF, 0x00, 0x00,0xFF});
	UI::RenderUI();
	Renderer::UpdateRenderer();
}
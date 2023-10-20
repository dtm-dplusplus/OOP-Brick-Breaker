#include "Engine.h"

#include "Core.h"
#include "Object.h"
#include "Renderer.h"
#include "VideoManager.h"
#include "UI.h"
#include "Window.h"

void Engine::Startup()
{
	Window::StartUp();
	Renderer::StartUp();
	UI::StartUp();
}


void Engine::ShutDown()
{
	Window::Shutdown();
	Renderer::Shutdown();
	UI::ShutDown();
	SDL_Quit();
}

void Engine::EngineLoop()
{
	// Poll Input & Events
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

	// Clear Renderer
	Renderer::ClearRenderer();
	UI::ClearUI();

	// Update Renderer
	{
		// if (static bool b{ 0 })ImGui::ShowDemoWindow(&b);
		Object obj;
		obj.GetCollider().GetRect() = { Window::GetWidthHalfF(), Window::GetHeightHalfF(), 30,30 };
		obj.GetCollider().GetColor() = { 0xFF, 0x00, 0x00,0xFF };

		Renderer::RenderRectFill(obj.GetCollider());

		ImGui::Begin("Object Properties");
		ImGui::DragFloat2("Position", &obj.GetPosition().x);
		ImGui::ColorEdit4("Color", &obj.GetCollider().Color.r);
		ImGui::End();
	}

	// Render Present
	UI::RenderUI();
	Renderer::UpdateRenderer();
}

void Engine::OnUpdate()
{
	// Update Game Components and objects
}

void Engine::OnRender()
{
	// Render Game Components and objects

}

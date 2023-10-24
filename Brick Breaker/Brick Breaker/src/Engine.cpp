#include "Engine.h"

#include "Core.h"
#include "VideoManager.h"
#include "Game.h"

Game* Engine::m_Game{nullptr};

Engine::Engine()
{
	Window::StartUp();
	Renderer::StartUp();
	UI::StartUp();

	m_Game = new Game;
}

Engine::~Engine()
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

	// Update Game
	m_Game->OnUpdate();
	m_Game->GameLoop();
	m_Game->OnRender();

	// Render Present
	UI::RenderUI();
	Renderer::UpdateRenderer();
}

void Engine::OnUpdate()
{
	// Update Game Components and objects
	m_Game->OnUpdate();
}

void Engine::OnRender()
{
	// Render Game Components and objects
	m_Game->OnRender();
}

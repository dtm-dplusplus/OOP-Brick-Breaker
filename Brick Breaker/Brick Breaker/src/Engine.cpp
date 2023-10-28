#include "Engine.h"

#include "Core.h"
#include "Input/Input.h"
#include "UI/UI.h"
#include "Video/Renderer.h"
#include "Video/Window.h"

Game* Engine::s_Game{nullptr};
bool Engine::isRunning{ true };

Engine::Engine()
{
	Window::StartUp();
	Renderer::StartUp();
	UI::StartUp();

	s_Game = new Game;

}

Engine::~Engine()
{
	Window::Shutdown();
	Renderer::Shutdown();
	UI::ShutDown();
	SDL_Quit();
}

bool Engine::GetIsRunning() const
{
	return isRunning;
}

void Engine::EngineLoop()
{
	// Poll Input & Events
	Input::PollInput();

	// Clear Renderer
	Renderer::ClearRenderer();
	UI::ClearUI();

	// Update Game
	s_Game->OnUpdate();
	s_Game->OnRender();

	// Render Present
	UI::RenderUI();
	Renderer::UpdateRenderer();

	isRunning = Window::GetWindowOpen();
}

void Engine::OnUpdate()
{
	// Update Game Components and objects
	s_Game->OnUpdate();
}

void Engine::OnRender()
{
	// Render Game Components and objects
	s_Game->OnRender();
}

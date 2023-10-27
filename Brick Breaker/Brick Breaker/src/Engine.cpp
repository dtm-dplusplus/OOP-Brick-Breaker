#include "Engine.h"

#include "Core.h"
#include "VideoManager.h"
#include "Game.h"
#include "Input.h"

Game* Engine::s_Game{nullptr};

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

void Engine::EngineLoop()
{
	// Poll Input & Events
	Input::PollInput();

	// Clear Renderer
	Renderer::ClearRenderer();
	UI::ClearUI();

	// Update Game
	s_Game->OnUpdate();
	s_Game->GameLoop();
	s_Game->OnRender();

	// Render Present
	UI::RenderUI();
	Renderer::UpdateRenderer();
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

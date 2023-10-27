#include "Engine.h"

#include "Core.h"
#include "VideoManager.h"
#include "Game.h"
#include "Input.h"

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
	Input::PollInput();

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

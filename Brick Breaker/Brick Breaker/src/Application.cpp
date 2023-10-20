#include "Application.h"

#include "Engine.h"
#include "VideoManager.h"
#include "Window.h"


Application::Application()
{
	Engine::Startup();
}

Application::~Application()
{
	Engine::ShutDown();
}

void Application::Run()
{
	while (Window::GetWindowOpen()) { Engine::EngineLoop(); }
}
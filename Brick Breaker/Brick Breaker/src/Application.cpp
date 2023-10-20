#include "Application.h"

#include "Engine.h"
#include "VideoManager.h"
#include "Window.h"


Application::Application()
{
	m_Engine = new Engine;
}

Application::~Application()
{
	delete m_Engine;
}

void Application::Run() const
{
	while (Window::GetWindowOpen()) { m_Engine->EngineLoop(); }
}

#include "Application.h"

#include "Engine.h"

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
	while (m_Engine->GetIsRunning()) { m_Engine->EngineLoop(); }
}

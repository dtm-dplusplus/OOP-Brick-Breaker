#include "Application.h"
#include "VideoManager.h"
#include "Window.h"


Application::Application()
{
	VideoManager::StartUp();
}

Application::~Application()
{
	VideoManager::Shutdown();
}

void Application::Run()
{
	while (Window::GetWindowOpen()) { VideoManager::WindowLoop(); }
}
#include "Application.h"
#include "VideoManager.h"


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
	while (VideoManager::GetWindowOpen()) { VideoManager::WindowLoop(); }
}

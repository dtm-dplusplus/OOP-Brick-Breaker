#include "VideoManager.h"

#include "Core.h"
#include "Window.h"
#include  "Renderer.h"

bool VideoManager::StartUp()
{
	Window::Startup();
	Renderer::Startup();

	return true;
}

bool VideoManager::Shutdown()
{
	Window::Shutdown();
	Renderer::Shutdown();
	SDL_Quit();

	return true;
}

void VideoManager::WindowLoop()
{
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0)
	{
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

	Renderer::ClearRenderer();

	static float x{ Window::GetWidth() / 2.0f }, y{ Window::GetHeight() / 2.0f };
	Renderer::SetRenderDrawColor({ 0xFF, 0x00, 0x00, 0xFF });
	Renderer::RenderPointF(x,y);

	Renderer::UpdateRenderer();
}
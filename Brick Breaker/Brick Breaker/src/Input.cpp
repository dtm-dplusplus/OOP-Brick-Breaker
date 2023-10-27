#include "Input.h"
#include "UI.h"
#include "Window.h"

SDL_Event Input:: m_Event{};
int Input::MouseX{};
int Input::MouseY{};


void Input::PollInput()
{
	while (SDL_PollEvent(&m_Event) != 0)
	{
		ImGui_ImplSDL2_ProcessEvent(&m_Event);
		switch (m_Event.type)
		{
		case SDL_KEYDOWN:
		{
			// std::cout << "key down: " << std::to_string(event.key.keysym.sym) << std::endl;
		}

		case SDL_MOUSEMOTION:
			{
			// SDL_GetRelativeMouseState(&MouseX, &MouseY);
			SDL_GetMouseState(&MouseX, &MouseY);
			}
		case SDL_MOUSEBUTTONDOWN:
		{
			// std::cout << "mouse down: " << std::to_string(event.button.button) << std::endl;
		}
		case SDL_WINDOWEVENT:
		{
			switch (m_Event.window.event)
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
}

int Input::GetMouseMotionX()
{
	return  MouseX;
}


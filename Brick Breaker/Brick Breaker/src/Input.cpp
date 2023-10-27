#include "Input.h"
#include "UI.h"
#include "Window.h"

SDL_Event Input:: s_Event{};
int Input::s_MouseX{};
int Input::s_MouseY{};


void Input::PollInput()
{
	while (SDL_PollEvent(&s_Event) != 0)
	{
		ImGui_ImplSDL2_ProcessEvent(&s_Event);
		switch (s_Event.type)
		{
		case SDL_KEYDOWN:
		{
			// std::cout << "key down: " << std::to_string(event.key.keysym.sym) << std::endl;
		}

		case SDL_MOUSEMOTION:
			{
			// SDL_GetRelativeMouseState(&s_MouseX, &s_MouseY);
			SDL_GetMouseState(&s_MouseX, &s_MouseY);
			}
		case SDL_MOUSEBUTTONDOWN:
		{
			// std::cout << "mouse down: " << std::to_string(event.button.button) << std::endl;
		}
		case SDL_WINDOWEVENT:
		{
			switch (s_Event.window.event)
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
	return  s_MouseX;
}


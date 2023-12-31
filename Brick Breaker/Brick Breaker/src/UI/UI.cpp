#include "UI.h"

#include "Video/Renderer.h"
#include "Video/Window.h"


ImGuiIO UI::s_io;

void UI::StartUp()
{
    // Setup ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    s_io = ImGui::GetIO(); (void)s_io;
    s_io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    s_io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup ImGui style
    ImGui::StyleColorsDark();

    // Setup ImGui SDL2 Implementation
    ImGui_ImplSDL2_InitForSDLRenderer(Window::GetSDLWindow(), Renderer::GetSDLRenderer());
    ImGui_ImplSDLRenderer2_Init(Renderer::GetSDLRenderer());
}

void UI::ShutDown()
{
    ImGui_ImplSDL2_Shutdown();
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui::Shutdown();
}

void UI::ClearUI()
{
    ImGui_ImplSDLRenderer2_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
}

void UI::RenderUI()
{
    ImGui::Render();
    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
}

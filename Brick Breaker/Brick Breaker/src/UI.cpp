#include "UI.h"


#include "Renderer.h"
#include "Window.h"

ImGuiIO UI::io;

void UI::StartUp()
{
    // Setup ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

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

#include "UI.h"

#include "Renderer.h"
#include "Window.h"
#include "../vendor/imgui-master/imgui.h"
#include "../vendor/imgui-master/imgui_impl_sdl2.h"
#include "../vendor/imgui-master/imgui_impl_sdlrenderer2.h"

ImGuiIO UI::io;

void UI::StartUp()
{
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    ImGui_ImplSDL2_InitForSDLRenderer(Window::GetSDLWindow(), Renderer::GetSDLRenderer());
    ImGui_ImplSDLRenderer2_Init(Renderer::GetSDLRenderer());
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

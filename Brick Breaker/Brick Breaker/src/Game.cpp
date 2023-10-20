#include "Game.h"

Game::Game()
{
	Objects.push_back(new Object({ Window::GetWidthF() / 5.f, Window::GetHeightHalfF() }));
	Objects.push_back(new Object({ Window::GetWidthF() / 4.f, Window::GetHeightHalfF() }));
	Objects.push_back(new Object({ Window::GetWidthF() / 3.f, Window::GetHeightHalfF() }));
}

Game::~Game()
{
}

void Game::OnUpdate()
{
	// for (Object* obj : Objects) { obj->OnUpdate(); }

	// if (static bool b{ 0 })ImGui::ShowDemoWindow(&b);
	Object obj;
	obj.GetCollider().GetRect() = { Window::GetWidthHalfF(), Window::GetHeightHalfF(), 30,30 };
	obj.GetCollider().GetColor() = { 0xFF, 0x00, 0x00,0xFF };

	Renderer::RenderRectFill(obj.GetCollider());

	ImGui::Begin("Object Properties");
	ImGui::DragFloat2("Position", &obj.GetPosition().x);
	ImGui::ColorEdit4("Color", &obj.GetCollider().Color.r);
	ImGui::End();

}


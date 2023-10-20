#include "Game.h"

Game::Game()
{
	Objects.push_back(new Object({ Window::GetWidthF() / 5.f * 2, Window::GetHeightHalfF() }));
	Objects.push_back(new Object({ Window::GetWidthF() / 5.f * 3, Window::GetHeightHalfF() }));
	Objects.push_back(new Object({ Window::GetWidthF() / 5.f * 4, Window::GetHeightHalfF() }));

	for (Object*& obj : Objects)
	{
		obj->SetCollider({obj->GetPosition().x, obj->GetPosition().y, 40, 40} );
		obj->GetCollider().Color = { 0xFF, 0x00,0x00,0xFF };
	}

}

Game::~Game()
{
	for (Object*& obj : Objects) { delete obj; }
}

void Game::GameLoop()
{
	// Query Inputs with Engine


	// Do Game systems and logic


}

void Game::OnUpdate()
{
	// List currently active game objects
	ImGui::Begin("Debug Game");
	ImGui::SetNextItemOpen(true, ImGuiCond_Once);
	if (ImGui::TreeNode("Objects"))
	{
		ImGui::BeginMenuBar();
		for (int i{0}, max{ (int)Objects.size() }; i < max; i++)
		{
			if (i == 0) { ImGui::SetNextItemOpen(true, ImGuiCond_Once);}

			if (ImGui::TreeNode((void*)(intptr_t)i, Objects[i]->GetName().c_str()))
			{
				// Transform
				ImGui::Text("Transform");
				ImGui::DragFloat2("Position", &Objects[i]->GetPosition().x);

				// Collider
				ImGui::Text("Collider");
				ImGui::DragFloat("Width", &Objects[i]->GetCollider().GetRect().w, 1, 0, INTMAX_MAX);
				ImGui::DragFloat("Height", &Objects[i]->GetCollider().GetRect().h, 1, 0, INTMAX_MAX);
				ImGui::Combo("Render Mode", &Objects[i]->GetRenderMode(), "Line Mode\0Fill Mode\0\0");
				ImGui::ColorEdit4("Color", &Objects[i]->GetCollider().Color.r);

				ImGui::TreePop();
			}
		}
		ImGui::TreePop();
	}
	ImGui::End();


	for (Object*& obj : Objects){ obj->OnUpdate(); }
}

void Game::OnRender()
{
	for (Object*& obj : Objects) { obj->OnRender(); }
}

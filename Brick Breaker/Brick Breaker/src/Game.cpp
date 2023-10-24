#include "Game.h"

Game::Game()
{
	Objects.push_back(new Object);
	Objects[0]->SetPosition({ Window::GetWidthHalfF(), Window::GetHeightHalfF() });

	for (Object*& obj : Objects)
	{
		obj->SetCollider({{obj->GetPosition().x, obj->GetPosition().y, 40, 40}} );
		obj->GetTexture()->SetTexturePath("res\\textures\\24-Breakout-Tiles.png");
		obj->GetTexture()->LoadTexture();
	}

	Objects[0]->SetName("Ball");
	Objects[0]->SetVelocity({ 20.f, 0.0f });
}

Game::~Game()
{
	for (Object*& obj : Objects) { delete obj; }
}

void Game::GameLoop()
{
	// Query Inputs with Engine


	// Do Game systems and logic
	if (Objects[0]->GetCollider()->GetBoundLeft() <= 0 ||
		Objects[0]->GetCollider()->GetBoundRight() >= Window::GetWidthF())
	{
		Objects[0]->GetVelocity() = -Objects[0]->GetVelocity();
	}
}	


void Game::OnUpdate()
{
	// List currently active game objects
	ImGui::Begin("Debug Game");

	// Show ImGui demo window if checked
	static bool showDemo{ false };
	ImGui::Checkbox("Demo", &showDemo);
	if (showDemo) { ImGui::ShowDemoWindow(); }

	// List game objects
	ImGui::SetNextItemOpen(true, ImGuiCond_Once);
	if (ImGui::TreeNode("Game Objects"))
	{
		for (int i{0}, max{ (int)Objects.size() }; i < max; i++)
		{
			if (i == 0) { ImGui::SetNextItemOpen(true, ImGuiCond_Once);}

			if (ImGui::TreeNode(Objects[i]->GetName().c_str()))
			{
				if(ImGui::TreeNode("Transform"))
				{
					ImGui::DragFloat2("Position", &Objects[i]->GetPosition().x);
					ImGui::DragFloat2("Velocity", &Objects[i]->GetVelocity().x);
					// ImGui::DragFloat2("Scale", &Objects[i]->GetScale().x);
					ImGui::TreePop();
				}
				if (ImGui::TreeNode("Collider"))
				{
					ImGui::SeparatorText("Collider Size");
					ImGui::DragFloat("Width", &Objects[i]->GetCollider()->GetRect().w, 1, 0, INTMAX_MAX);
					ImGui::DragFloat("Height", &Objects[i]->GetCollider()->GetRect().h, 1, 0, INTMAX_MAX);
					ImGui::SeparatorText("Render Options");
					ImGui::Checkbox("Render Collider", &Objects[i]->GetCollider()->IsRenderCollider());
					ImGui::ColorEdit4("Color", &Objects[i]->GetCollider()->Color.r);
					ImGui::TreePop();
				}
				if (ImGui::TreeNode("Texture"))
				{
					ImGui::Text(Objects[i]->GetTexture()->GetTexurePath().c_str());
					ImGui::TreePop();
				}
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

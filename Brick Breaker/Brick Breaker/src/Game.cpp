#include "Game.h"

#include <SDL_syswm.h>

#include "Input.h"

Game::Game()
{
	m_GameObjects.push_back(new Object);
	m_GameObjects[0]->SetName("Player");
	m_GameObjects[0]->SetPosition(Window::GetWidthHalfF(), Window::GetHeightF() / 10 * 9);
	m_GameObjects[0]->SetCollider( 150, 40 );
	m_GameObjects[0]->GetTexture()->SetTexturePath("res\\textures\\Breakout Tile Set Free\\PNG\\49-Breakout-Tiles.png");
	m_GameObjects[0]->GetTexture()->LoadTexture();

	m_GameObjects.push_back(new Object);
	m_GameObjects[1]->SetName("Ball");
	m_GameObjects[1]->SetPosition({ Window::GetWidthHalfF(), Window::GetHeightHalfF() });
	m_GameObjects[1]->SetVelocity(20.f, 0.0f);
	m_GameObjects[1]->SetCollider( 40, 40);
	m_GameObjects[1]->GetTexture()->SetTexturePath("res\\textures\\Breakout Tile Set Free\\PNG\\58-Breakout-Tiles.png");
	m_GameObjects[1]->GetTexture()->LoadTexture();

	const int brickNum{ 12 };
	int rowNum{ 5 };
	static float width = Window::GetWidthF() / 12;
	static float height = 40;
	float yOffset = 100;

	for (int r{ 0 }, rNum{ 5 }; r < rNum; r++)
	{
		for (int b{ 0 }; b < brickNum; b++)
		{
			static int bCount{ 1 };
			Object* brick = new Object;
			brick->SetName("Brick" + std::to_string(bCount++));
			brick->SetPosition(b * width, yOffset + r * height);
			brick->SetCollider(width, height);
			brick->GetTexture()->SetTexturePath("res\\textures\\Breakout Tile Set Free\\PNG\\07-Breakout-Tiles.png");
			brick->GetTexture()->LoadTexture();
			m_GameObjects.push_back(brick);
		}
	}
}

Game::~Game()
{
	for (Object*& obj : m_GameObjects) { delete obj; }
}

void Game::GameLoop()
{
	// Query Inputs with Engine
	m_GameObjects[0]->SetPositionX(Input::GetMouseMotionX());

	// Do Game systems and logic
	// Ball movement
	if (m_GameObjects[1]->GetCollider()->GetBoundLeft() <= 0 ||
		m_GameObjects[1]->GetCollider()->GetBoundRight() >= Window::GetWidthF())
	{				  
		m_GameObjects[1]->GetVelocity() = -m_GameObjects[1]->GetVelocity();
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
		for (int i{0}, max{ (int)m_GameObjects.size() }; i < max; i++)
		{
			if (i == 0) { ImGui::SetNextItemOpen(true, ImGuiCond_Once);}

			if (ImGui::TreeNode(m_GameObjects[i]->GetName().c_str()))
			{
				if(ImGui::TreeNode("Transform"))
				{
					ImGui::DragFloat2("Position", &m_GameObjects[i]->GetPosition().x);
					ImGui::DragFloat2("Velocity", &m_GameObjects[i]->GetVelocity().x);
					// ImGui::DragFloat2("Scale", &Objects[i]->GetScale().x);
					ImGui::TreePop();
				}
				if (ImGui::TreeNode("Collider"))
				{
					ImGui::SeparatorText("Collider Size");
					ImGui::DragFloat("Width", &m_GameObjects[i]->GetCollider()->GetRect().w, 1, 0, INTMAX_MAX);
					ImGui::DragFloat("Height", &m_GameObjects[i]->GetCollider()->GetRect().h, 1, 0, INTMAX_MAX);
					ImGui::SeparatorText("Render Options");
					ImGui::Checkbox("Render Collider", &m_GameObjects[i]->GetCollider()->IsRenderCollider());
					ImGui::ColorEdit4("Color", &m_GameObjects[i]->GetCollider()->Color.r);
					ImGui::TreePop();
				}
				if (ImGui::TreeNode("Texture"))
				{
					ImGui::Text(m_GameObjects[i]->GetTexture()->GetTexurePath().c_str());
					ImGui::TreePop();
				}
				if (ImGui::TreeNode("Render"))
				{
					ImGui::Checkbox("Render Object", &m_GameObjects[i]->GetIsRender());

					ImGui::TreePop();
				}
				ImGui::TreePop();
			}
		}
		ImGui::TreePop();																																																																																																																																					
	}
	ImGui::End();

	for (Object*& obj : m_GameObjects){ obj->OnUpdate(); }
}

void Game::OnRender()
{
	for (Object*& obj : m_GameObjects) { obj->OnRender(); }
}

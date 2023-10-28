#include "Game.h"

Game::Game()
{
	m_Levels.push_back(new DebugLevel);
	m_CurrentLevel = m_Levels[0];
	m_CurrentLevel->Load();
}

Game::~Game()
{
	delete m_CurrentLevel;
	for (Level*& l : m_Levels) { delete l; }
	m_Levels.clear();
}

void Game::OnUpdate()
{
	// UPDATE LEVEL //
	m_CurrentLevel->OnUpdate();
	for (Object*& obj : m_CurrentLevel->m_LevelObjects) { obj->OnUpdate(); }
}

void Game::OnRender()
{
	for (Object*& obj : m_CurrentLevel->m_LevelObjects) { obj->OnRender(); }
}

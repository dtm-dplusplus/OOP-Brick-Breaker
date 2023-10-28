#include "Level.h"

Level::Level()
{

}

std::string Level::GetLevelName()
{
	return m_LevelName;
}

void Level::SetLevelName(const std::string& _name)
{
	m_LevelName = _name;
}

std::vector<Object*> Level::GetObjects()
{
	return m_LevelObjects;
}

void Level::Unload()
{
	for (Object*& obj : m_LevelObjects) { delete obj; }
	m_LevelObjects.clear();
}
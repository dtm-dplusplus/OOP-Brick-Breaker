#pragma once
#include "Engine.h"

class Application
{
public:
	Application();
	~Application();

	void Run();

private:
	Engine* m_Engine;
};


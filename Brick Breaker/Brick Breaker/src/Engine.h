#pragma once


class Engine
{
public:
	static void Startup();
	static void ShutDown();

	static void EngineLoop();

	void OnUpdate();
	void OnRender();
};


#pragma once
#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "Engine.h"

class Application
{
public:
	Application();
	~Application();

	void Run() const;

private:
	Engine* m_Engine;
};

#endif

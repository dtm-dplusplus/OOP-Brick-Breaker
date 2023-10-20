#pragma once

#include "Core.h"

class Object
{
public:
	Object();
	virtual ~Object();

	virtual void OnUpdate();
	virtual void OnRender();
	
protected:
	void OnBeginPlay();

	SDL_Rect Collider;

private:
	std::string name;
};


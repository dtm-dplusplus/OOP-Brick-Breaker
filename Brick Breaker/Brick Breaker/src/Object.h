#pragma once

#include "Core.h"

class Object
{
public:
	Object();
	Object(const glm::vec2& _position) { Position = _position; };

	virtual ~Object();

	virtual void OnUpdate();
	virtual void OnRender();

	std::string& GetName() { return name; }
	std::string GetName() const { return name; }

	glm::vec2& GetPosition() { return Position; }
	glm::vec2 GetPosition() const { return Position; }
	void SetPosition(const glm::vec2& _position) { Position = _position; }

	Collider& GetCollider() { return Collider; }
	Collider GetCollider() const { return Collider; }
	void SetCollider(const Collider& _collider) { Collider = _collider; }


protected:
	virtual void OnBeginPlay();

	glm::vec2 Position;
	Collider Collider;

private:
	std::string name;

};


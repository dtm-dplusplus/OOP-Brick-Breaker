#pragma once

#include "Core.h"
#include "Texture.h"

class Object
{
public:
	Object();
	explicit Object(const glm::vec2& _position);;
	virtual ~Object();

	virtual void OnUpdate();
	virtual void OnRender();

	Texture Texture;

	std::string& GetName() { return Name; }
	std::string GetName() const { return Name; }
	void SetName(const std::string& _name) { Name = _name; }

	int& GetRenderMode() { return RenderMode; }
	int GetRenderMode() const { return RenderMode; }
	void SetRenderMode(const int _render_mode) { RenderMode = _render_mode; }

	glm::vec2& GetPosition() { return Position; }
	glm::vec2 GetPosition() const { return Position; }
	void SetPosition(const glm::vec2& _position) { Position = _position; }

	Collider& GetCollider() { return Collider; }
	Collider GetCollider() const { return Collider; }
	void SetCollider(const Collider& _collider) { Collider = _collider; }

protected:
	glm::vec2 Position;
	Collider Collider;

private:
	static int ObjectCount;
	std::string Name;
	int RenderMode;

};


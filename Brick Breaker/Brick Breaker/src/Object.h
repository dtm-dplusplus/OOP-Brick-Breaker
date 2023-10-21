#pragma once

#include "Core.h"
#include "Texture.h"

class Object
{
public:
	Object();
	explicit Object(const glm::vec2& _position);
	virtual ~Object();

	virtual void OnUpdate();
	virtual void OnRender();


	std::string& GetName();
	std::string GetName() const;
	void SetName(const std::string& _name);

	glm::vec2& GetPosition();
	glm::vec2 GetPosition() const;
	void SetPosition(const glm::vec2& _position);

	glm::vec2& GetScale();
	glm::vec2 GetScale() const;
	void SetScale(const glm::vec2& _scale);

	Collider*& GetCollider();
	Collider* GetCollider() const;
	void SetCollider(const Collider& _collider);

	Texture*& GetTexture();

protected:
	glm::vec2 m_Position;
	glm::vec2 m_Scale;

	Collider* m_Collider;

private:
	static int s_ObjectCount;
	std::string m_ObjectName;

	Texture* m_Texture;
};


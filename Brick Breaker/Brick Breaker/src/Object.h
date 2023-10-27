#pragma once

#include "Core.h"
#include "Texture.h"

class Object
{
public:
	Object();
	virtual ~Object();

	virtual void OnUpdate();
	virtual void OnRender();


	std::string& GetName();
	std::string GetName() const;
	void SetName(const std::string& _name);

	glm::vec2& GetPosition();
	glm::vec2 GetPosition() const;
	void SetPosition(const glm::vec2& _position);
	void SetPosition(const float _x, const float _y);
	void SetPositionX(const float _x);
	void SetPositionY(const float _y);


	glm::vec2& GetVelocity();
	glm::vec2 GetVelocity() const;
	void SetVelocity(const glm::vec2& _velocity);
	void SetVelocity(const float _x,const float _y);


	glm::vec2& GetScale();
	glm::vec2 GetScale() const;
	void SetScale(const glm::vec2& _scale);

	Collider*& GetCollider();
	Collider* GetCollider() const;
	void SetCollider(const Collider& _collider) const;
	void SetCollider(const float _w, float _h) const;


	Texture*& GetTexture();

protected:
	glm::vec2 m_Position;
	glm::vec2 m_Scale;
	glm::vec2 m_Velocity;

	Collider* m_Collider;

private:
	static int s_ObjectCount;
	std::string m_ObjectName;

	Texture* m_Texture;
};


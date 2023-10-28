#pragma once
#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "Core.h"
#include "Video/Renderer.h"

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
	void SetPosition(float _x, float _y);
	void SetPositionX(float _x);
	void SetPositionY(float _y);

	glm::vec2& GetScale();
	glm::vec2 GetScale() const;
	void SetScale(const glm::vec2& _scale);

	glm::vec2& GetVelocity();
	glm::vec2 GetVelocity() const;
	void SetVelocity(const glm::vec2& _velocity);
	void SetVelocity(float _x, float _y);


	Collider*& GetCollider();
	Collider* GetCollider() const;
	void SetCollider(const Collider& _collider) const;
	void SetCollider(float _w, float _h) const;

	bool& GetIsRender();
	bool GetIsRender() const;
	void SetIsRender(bool _isrender);

	Texture*& GetTexture();

protected:
	glm::vec2 m_Position;
	glm::vec2 m_Scale;
	glm::vec2 m_Velocity;

	Collider* m_Collider;

	bool m_IsRender;
	std::string m_ObjectName;
	Texture* m_Texture;

private:
	static int s_ObjectCount;
	int ObjectID;
};

#endif

#include "Object.h"

#include <Windows.h>

#include "Renderer.h"

int Object::s_ObjectCount{0};


Object::Object()
{
	m_Position = {0.f, 0.f};
	m_Velocity = { 0.f, 0.f };
	m_Scale = { 1.0f, 1.0f };
	m_Collider = new Collider;
	m_Texture = new Texture;

	m_ObjectName = "Object" + std::to_string(s_ObjectCount++);
}


Object::~Object()
{
}

void Object::OnUpdate()
{
	// Update Position from velocity
	m_Position += m_Velocity;

	// Update m_Collider
	m_Collider->Update(m_Position);
}

void Object::OnRender()
{
	Renderer::RenderTexture(m_Texture, m_Collider);
	if(m_Collider->IsRenderCollider()){ Renderer::RenderRectLine(m_Collider); }
}

std::string& Object::GetName()
{
	return m_ObjectName;
}

std::string Object::GetName() const
{
	return m_ObjectName;
}

void Object::SetName(const std::string& _name)
{
	m_ObjectName = _name;
}

glm::vec2& Object::GetPosition()
{
	return m_Position;
}

glm::vec2 Object::GetPosition() const
{
	return m_Position;
}

void Object::SetPosition(const glm::vec2& _position)
{
	m_Position = _position;
}

void Object::SetPosition(const float _x, const float _y)
{
	m_Position = { _x, _y };
}

void Object::SetPositionX(const float _x)
{
	m_Position.x = _x;
}

void Object::SetPositionY(const float _y)
{
	m_Position.y = _y;
}

glm::vec2& Object::GetVelocity()
{
	return m_Velocity;
}

glm::vec2 Object::GetVelocity() const
{
	return m_Velocity;
}

void Object::SetVelocity(const glm::vec2& _velocity)
{
	m_Velocity = _velocity;
}

void Object::SetVelocity(const float _x, const float _y)
{
	m_Velocity = { _x, _y };
}

glm::vec2& Object::GetScale()
{
	return m_Scale;
}

glm::vec2 Object::GetScale() const
{
	return m_Scale;
}

void Object::SetScale(const glm::vec2& _scale)
{
	m_Scale = _scale;
}

Collider*& Object::GetCollider()
{
	return m_Collider;
}

Collider* Object::GetCollider() const
{
	return m_Collider;
}

void Object::SetCollider(const Collider& _collider) const
{
	*m_Collider = _collider;
}

void Object::SetCollider(const float _w, const float _h) const
{
	*m_Collider = { m_Position.x , m_Position.y, _w, _h };
}

Texture*& Object::GetTexture()
{
	return m_Texture;
}

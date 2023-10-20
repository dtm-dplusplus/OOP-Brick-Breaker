#include "Object.h"

#include "Renderer.h"

int Object::ObjectCount{0};


Object::Object()
{
	Position = {0.f,0.f};
	Collider.Update(Position);
	name = "Object" + std::to_string(ObjectCount++);
}

Object::Object(const glm::vec2& _position)
{
	Position = _position;
	Collider.Update(Position);
	name = "Object" + std::to_string(ObjectCount++);
}

Object::~Object()
{
}

void Object::OnUpdate()
{
	// Update Collider
	Collider.Update(Position);
}

void Object::OnRender()
{
	Renderer::RenderRectFill(Collider);
}

void Object::OnBeginPlay()
{

}

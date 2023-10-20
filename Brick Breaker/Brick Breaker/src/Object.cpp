#include "Object.h"

#include "Renderer.h"

int Object::ObjectCount{0};


Object::Object()
{
	Position = {0.f,0.f};
	Collider.Update(Position);
	Name = "Object" + std::to_string(ObjectCount++);
}

Object::Object(const glm::vec2& _position)
{
	Position = _position;
	Collider.Update(Position);
	Name = "Object" + std::to_string(ObjectCount++);
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
	if(RenderMode){ Renderer::RenderRectFill(Collider); }
	else { Renderer::RenderRectLine(Collider); }
}

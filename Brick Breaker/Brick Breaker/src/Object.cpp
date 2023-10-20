#include "Object.h"

#include "Renderer.h"
#include "../vendor/imgui-master/imgui.h"

Object::Object()
{
}

Object::~Object()
{
}

void Object::OnUpdate()
{
	// Update Collider
	Collider.Rect.x = Position.x;
	Collider.Rect.y = Position.y;

}

void Object::OnRender()
{
	Renderer::RenderRectFill(Collider);
}

void Object::OnBeginPlay()
{

}

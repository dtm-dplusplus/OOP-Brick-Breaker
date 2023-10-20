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
	
}

void Object::OnRender()
{
	Renderer::RenderRectFill(Collider);
}

void Object::OnBeginPlay()
{

}

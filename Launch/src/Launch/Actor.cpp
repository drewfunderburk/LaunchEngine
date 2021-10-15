#include "Actor.h"
#include "Log.h"

Launch::Actor::Actor()
{
	m_transform = Transform();
	m_transform.m_actor = this;
}

Launch::Actor::~Actor()
{
	end();
}

void Launch::Actor::start()
{
	EngineObject::start();
}

void Launch::Actor::update()
{
	EngineObject::update();
}

void Launch::Actor::end()
{
	EngineObject::end();

	for each (Component * component in m_components)
		delete component;

	for each (Actor * child in m_children)
		delete child;
}

Launch::Component* Launch::Actor::addComponent(Component* component)
{
	m_components.push_back(component);
	return component;
}

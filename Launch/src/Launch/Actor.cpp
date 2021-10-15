#include "Actor.h"

Launch::Actor::Actor()
{
	m_transform = Transform();
	m_transform.m_actor = this;
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
}
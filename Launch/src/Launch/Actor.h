#pragma once
#include "EngineObject.h"
#include "Transform.h"
#include <vector>

namespace Launch
{
	class Actor : public EngineObject
	{
		class Component;
	public:
		Actor();
		virtual ~Actor() {}

		virtual void start() override;
		virtual void update() override;
		virtual void end() override;

		template<typename T>
		T* getComponent()
		{
			for each (Component* component in m_components)
			{
				if (typeid(component) == typeid(T))
					return component;
			}
			return nullptr;
		}

	private:
		Transform m_transform;
		Actor* m_parent = null;
		std::vector<Actor*> m_children;
		std::vector<Component*> m_components;
	};
}
#pragma once
#include "EngineObject.h"
#include "Transform.h"
#include "Components/Component.h"
#include <vector>

namespace Launch
{
	class Actor : public EngineObject
	{
	public:
		Actor();
		virtual ~Actor();

		virtual void start() override;
		virtual void update() override;
		virtual void end() override;

		Component* addComponent(Component* component);

		Transform getTransform() const { return m_transform; }
		void setTransform(Transform transform) { m_transform = transform; }

		Actor* getParent() const { return m_parent; }
		void setParent(Actor* parent) { m_parent = parent; }

		template<typename T>
		T* getComponent() const
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
		Actor* m_parent = nullptr;
		std::vector<Actor*> m_children;
		std::vector<Component*> m_components;
	};
}
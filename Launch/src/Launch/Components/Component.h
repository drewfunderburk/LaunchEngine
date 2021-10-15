#pragma once
#include "../EngineObject.h"

namespace Launch
{
	class Component : public EngineObject
	{
		friend class Actor;
	public:
		Component() {}
		virtual ~Component() {}

		virtual void start() override;
		virtual void update() override;
		virtual void end() override;

		Actor* getActor() { return m_actor; }

	private:
		Actor* m_actor = nullptr;
	};
}
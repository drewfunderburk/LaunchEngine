#pragma once
#include "EngineObject.h"
#include <vector>

namespace Launch
{
	class Scene : public EngineObject
	{
		class Actor;
	public:
		Scene() {}
		virtual ~Scene() {}

		void start();
		void update();
		void end();

	private:
		std::vector<Actor*> m_actors;
	};
}
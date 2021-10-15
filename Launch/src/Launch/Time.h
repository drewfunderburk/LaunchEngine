#pragma once
#include "Core.h"

namespace Launch
{
	class LAUNCH_API Time
	{
	private:
		Time() {}
		~Time() {}

	public:
		inline static float getDeltaTime() { return m_deltaTime; }

	private:
		static float m_deltaTime;
	};
}
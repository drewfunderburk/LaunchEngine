#pragma once

namespace Launch
{
	class Time
	{
	private:
		Time() {}
		~Time() {}

	public:
		static float getDeltaTime() { return m_deltaTime; }

	private:
		static float m_deltaTime;
	};
}
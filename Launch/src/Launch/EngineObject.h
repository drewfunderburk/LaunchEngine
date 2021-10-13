#pragma once

namespace Launch
{
	class EngineObject
	{
	public:
		EngineObject() {}
		virtual ~EngineObject() {}

		virtual void start() { m_started = true; }
		virtual void update() {}
		virtual void end() {}

		inline bool getStarted() const { return m_started; }
		inline bool getEnabled() const { return m_enabled; }
		void setEnabled(bool enabled) { m_enabled = enabled; }

	private:
		bool m_started = false;
		bool m_enabled = true;
	};
}
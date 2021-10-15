#pragma once

#include "Core.h"
#include <vector>

namespace Launch
{
	class LAUNCH_API Application
	{
		class Scene;
	public:
		Application();
		virtual ~Application();

		void Run();

		virtual void start();
		virtual void update();
		virtual void end();


	private:
		std::vector<Scene*> m_scenes;
	};

	// To be defined in client
	Application* CreateApplication();
}


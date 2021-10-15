#pragma once

#include "Core.h"
#include "Scene.h"
#include <vector>

namespace Launch
{
	class LAUNCH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		virtual void start();
		virtual void update();
		virtual void end();

		void addScene(Scene* scene);
		void removeScene(Scene* scene);
		Scene* getScene(int index);

		static Scene* getCurrentScene() { return m_currentScene; }
		static void setCurrentScene(Scene* scene) { m_currentScene = scene; }

	private:
		std::vector<Scene*> m_scenes;
		static Scene* m_currentScene;
	};

	// To be defined in client
	Application* CreateApplication();
}


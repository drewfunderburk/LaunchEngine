#include "Application.h"
#include <cmath>

namespace Launch
{
	Scene* Launch::Application::m_currentScene = nullptr;

	Launch::Application::Application()
	{
	}

	Launch::Application::~Application()
	{
	}

	void Application::Run()
	{
		system("pause");
	}
	void Application::start()
	{
	}
	void Application::update()
	{
	}
	void Application::end()
	{
	}

	void Application::addScene(Scene* scene)
	{
		m_scenes.push_back(scene);
		if (!m_currentScene)
			setCurrentScene(scene);
	}

	void Application::removeScene(Scene* scene)
	{
		for (auto i = m_scenes.begin(); i < m_scenes.end(); i++)
		{
			if (*i == scene)
			{
				m_scenes.erase(i);
				delete *i;
			}
		}
	}

	Scene* Application::getScene(int index)
	{
		if (index < 0 || index > m_scenes.size())
			return nullptr;
		return m_scenes[index];
	}
}

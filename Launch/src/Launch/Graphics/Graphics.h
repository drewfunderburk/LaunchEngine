#pragma once

#include "../Core.h"
#include <GLFW/glfw3.h>

namespace Launch
{
	class LAUNCH_API Graphics
	{
	public:
		Graphics() {}
		~Graphics() {}

		void Init();
		void Terminate();

		int getScreenWidth() { return m_screenWidth; }
		void setScreenWidth(int width) { m_screenWidth = width; }
		int getScreenHeight() { return m_screenHeight; }
		void setScreenHeight(int height) { m_screenHeight = height; }
		const char* getTitle() { return m_screenTitle; }
		void setTitle(const char * title) { m_screenTitle = title; }

	private:
		GLFWwindow* m_window = nullptr;

		int m_screenWidth = 1280;
		int m_screenHeight = 720;
		const char* m_screenTitle = "LaunchEngine";
	};
}
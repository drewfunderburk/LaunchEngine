#include "Graphics.h"
#include "../Log.h"
#include <string>

void Launch::Graphics::Init()
{
	LN_CORE_TRACE("Initializing GLFW...");
	if (!glfwInit())
	{
		LN_CORE_ERROR("Could not initialize GLFW!");
		return;
	}
	std::string str = "OpenGL version: ";
	std::string version = glfwGetVersionString();
	LN_CORE_TRACE((str + version).c_str());

	LN_CORE_TRACE("Creating OpenGL window...");
	m_window = glfwCreateWindow(m_screenWidth, m_screenHeight, m_screenTitle, nullptr, nullptr);
	if (!m_window)
	{
		glfwTerminate();
		LN_CORE_ERROR("Could not create OpenGL window!");
		return;
	}
	glfwMakeContextCurrent(m_window);
}

void Launch::Graphics::Terminate()
{
	if (!m_window)
	{
		LN_CORE_ERROR("Could not terminate Graphics. OpenGL window not valid!");
		return;
	}

	LN_CORE_TRACE("Destroying window...");
	glfwDestroyWindow(m_window);

	LN_CORE_TRACE("Terminating GLFW...");
}

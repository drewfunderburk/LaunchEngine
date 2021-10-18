#include "GL/glew.h"
#include <string>
#include "Graphics.h"
#include "../Log.h"

void debugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const char* message, const void* userParam)
{
	std::string str = "GL CALLBACK: type = " + std::to_string(type) + ", severity = " + std::to_string(severity) + ", message = " + message + "\n";
	LN_CORE_ERROR(str);
}

void Launch::Graphics::init()
{
	LN_CORE_TRACE("Initializing GLFW...");
	if (!glfwInit())
	{
		LN_CORE_ERROR("Could not initialize GLFW!");
		return;
	}

	std::string str = "GLFW version: ";
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

	LN_CORE_TRACE("Initializing GLEW...");
	if (glewInit() != GLEW_OK)
	{
		LN_CORE_ERROR("Could not initialize GLEW!");
		return;
	}
	str = "OpenGL version: ";
	version = (const char*)glGetString(GL_VERSION);
	LN_CORE_TRACE((str + version).c_str());

	LN_CORE_TRACE("Setting up OpenGL Debug...");
	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageCallback(debugCallback, nullptr);
}

void Launch::Graphics::terminate()
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

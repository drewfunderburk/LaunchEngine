#include "OpenGL.h"
#include "../Log.h"
#include <string>

void debugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const char* message, const void* userParam)
{
	std::string str = "GL CALLBACK: type = " + std::to_string(type) + ", severity = " + std::to_string(severity) + ", message = " + message + "\n";
	LN_CORE_ERROR(str);
}

void Launch::OpenGL::init()
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

void Launch::OpenGL::terminate()
{
	if (!m_window)
	{
		LN_CORE_ERROR("Could not terminate OpenGL. OpenGL window not valid!");
		return;
	}

	LN_CORE_TRACE("Destroying window...");
	glfwDestroyWindow(m_window);

	LN_CORE_TRACE("Terminating GLFW...");
}

void Launch::OpenGL::draw()
{
	float positions[6] =
	{
		-0.5f, -0.5f,
		 0.0f,  0.5f,
		 0.5f, -0.5f
	};

	// Vertex buffer
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

	// Vertex attribute
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	// Rendering
	glClear(GL_COLOR_BUFFER_BIT);

	glDrawArrays(GL_TRIANGLES, 0, 3);


	// Swap front and back buffers
	glfwSwapBuffers(m_window);

	// Poll and process events
	glfwPollEvents();
}

int Launch::OpenGL::createShader(const char* vertexShader, const char* fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
	return 0;
}

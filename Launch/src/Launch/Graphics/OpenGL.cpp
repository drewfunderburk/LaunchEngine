#include "OpenGL.h"
#include "../Log.h"
#include <string>
#include <fstream>
#include <sstream>

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

	const char* filePath = "src/Shaders/OpenGL_Basic.shader";
	char fullPath[_MAX_PATH];
	if (_fullpath(fullPath, filePath, _MAX_PATH) != NULL)
		printf("Full path is: %s\n", fullPath);
	else
		printf("Invalid path\n");

	ShaderProgramSource source = parseShader(filePath);
	LN_CORE_WARN(source.VertexSource);
	LN_CORE_WARN(source.FragmentSource);
	unsigned int shader = createShader(source.VertexSource, source.FragmentSource);
	glUseProgram(shader);

	// Rendering
	glClear(GL_COLOR_BUFFER_BIT);

	glDrawArrays(GL_TRIANGLES, 0, 3);


	// Swap front and back buffers
	glfwSwapBuffers(m_window);

	// Poll and process events
	glfwPollEvents();
}

unsigned int Launch::OpenGL::compileShader(unsigned int type, const char* source)
{
	unsigned int id = glCreateShader(type);
	glShaderSource(id, 1, &source, nullptr);
	glCompileShader(id);

	// TODO: Shader error handling
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		LN_CORE_ERROR("OpenGL Failed to compile Shader!");
		LN_CORE_ERROR(message);
		glDeleteShader(id);

		return 0;
	}

	return id;
}

unsigned int Launch::OpenGL::createShader(const char* vertexShader, const char* fragmentShader)
{
	unsigned int program = glCreateProgram();
	LN_CORE_TRACE("Compiling vertex shader...");
	unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
	LN_CORE_TRACE("Compiling fragment shader...");
	unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

Launch::OpenGL::ShaderProgramSource Launch::OpenGL::parseShader(const char* filePath)
{
	enum class ShaderType
	{
		NONE = -1,
		VERTEX = 0,
		FRAGMENT = 1
	};

	std::ifstream stream(filePath);

	std::string line;
	std::stringstream sStream[2];
	ShaderType type = ShaderType::NONE;
	while (getline(stream, line))
	{
		if (line.find("#vertex") != std::string::npos)
			type = ShaderType::VERTEX;
		else if (line.find("#fragment") != std::string::npos)
			type = ShaderType::FRAGMENT;
		else
			sStream[(int)type] << line << "\n";
	}

	return { sStream[0].str().c_str(), sStream[1].str().c_str() };
}

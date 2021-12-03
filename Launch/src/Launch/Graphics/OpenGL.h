#pragma once
#include "../Core.h"
#include "IGraphicsAPI.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <string>

namespace Launch
{
	class LAUNCH_API OpenGL : public IGraphicsAPI
	{
		struct ShaderProgramSource
		{
			std::string VertexSource;
			std::string FragmentSource;
		};

	public:
		OpenGL() {}
		~OpenGL() {}

		void init();
		void terminate();
		void draw();

		int getScreenWidth() const { return m_screenWidth; }
		void setScreenWidth(int width) { m_screenWidth = width; }

		int getScreenHeight() const { return m_screenHeight; }
		void setScreenHeight(int height) { m_screenHeight = height; }

		const char* getTitle() const { return m_screenTitle; }
		void setTitle(const char* title) { m_screenTitle = title; }

	private:
		unsigned int compileShader(unsigned int type, const char* source);
		unsigned int createShader(const char* vertexShader, const char* fragmentShader);
		ShaderProgramSource parseShader(const char* filePath);

	private:
		GLFWwindow* m_window = nullptr;

		int m_screenWidth = 1920;
		int m_screenHeight = 1080;
		const char* m_screenTitle = "LaunchEngine";
	};
}
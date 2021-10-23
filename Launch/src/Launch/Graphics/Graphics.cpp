#include "../Log.h"
#include "Graphics.h"
#include "OpenGL.h"

Launch::IGraphicsAPI* Launch::Graphics::m_graphicsAPI = nullptr;

void Launch::Graphics::init()
{
	LN_CORE_TRACE("Initializing OpenGL...");
	m_graphicsAPI = new OpenGL();
	m_graphicsAPI->init();
}

void Launch::Graphics::terminate()
{
	LN_CORE_TRACE("Terminating OpenGL...");
	m_graphicsAPI->terminate();
	delete m_graphicsAPI;
}

int Launch::Graphics::getScreenWidth()
{
	return m_graphicsAPI->getScreenWidth();
}

void Launch::Graphics::setScreenWidth(int width)
{
	m_graphicsAPI->setScreenWidth(width);
}

int Launch::Graphics::getScreenHeight()
{
	return m_graphicsAPI->getScreenHeight();
}

void Launch::Graphics::setScreenHeight(int height)
{
	m_graphicsAPI->setScreenHeight(height);
}

const char* Launch::Graphics::getTitle()
{
	return m_graphicsAPI->getTitle();
}

void Launch::Graphics::setTitle(const char* title)
{
	m_graphicsAPI->setTitle(title);
}

#pragma once
#include "../Core.h"
#include "IGraphicsAPI.h"

namespace Launch
{
	class LAUNCH_API Graphics
	{
	private:
		Graphics() {}
		~Graphics() {}

	public:

		static void init();
		static void terminate();
		static void draw();

		static int getScreenWidth();
		static void setScreenWidth(int width);
		static int getScreenHeight();
		static void setScreenHeight(int height);
		static const char* getTitle();
		static void setTitle(const char* title);

	private:
		static IGraphicsAPI* m_graphicsAPI;
		
	};
}
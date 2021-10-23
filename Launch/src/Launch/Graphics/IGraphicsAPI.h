#pragma once
#include "../Core.h"

namespace Launch
{
	class LAUNCH_API IGraphicsAPI
	{
	public:
		virtual void init() {}
		virtual void terminate() {}

		virtual int getScreenWidth() const { return -1; }
		virtual void setScreenWidth(int width) {}

		virtual int getScreenHeight() const { return -1; }
		virtual void setScreenHeight(int height) {}

		virtual const char* getTitle() const { return "null"; }
		virtual void setTitle(const char* title) {}
	};
}
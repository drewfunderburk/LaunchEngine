#pragma once

#ifdef LN_PLATFORM_WINDOWS

extern Launch::Application* Launch::CreateApplication();

int main(int argc, char** argv)
{
	Launch::Log::Init();
	LN_CORE_WARN("Initialized Log!");
	LN_INFO("Hello");
	
	auto app = Launch::CreateApplication();
	app->Run();
	delete app;
}

#endif 

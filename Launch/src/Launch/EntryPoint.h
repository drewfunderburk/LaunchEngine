#pragma once

#ifdef LN_PLATFORM_WINDOWS

extern Launch::Application* Launch::CreateApplication();

int main(int argc, char** argv)
{
	// Initialize Log
	LN_CORE_PRINT("Initializing Log...\n");
	Launch::Log::Init();
	LN_CORE_INFO("Log initialized");

	// Initialize Graphics
	LN_CORE_INFO("Initializing Graphics...");
	Launch::Graphics graphics = Launch::Graphics();
	graphics.Init();
	LN_CORE_INFO("Graphics Initialized");

	// Launch client application
	LN_CORE_INFO("Launching Application...");
	auto app = Launch::CreateApplication();
	app->Run();
	delete app;

	LN_CORE_INFO("Closing Launch");
	return 0;
}

#endif 

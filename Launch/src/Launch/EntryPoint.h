#pragma once

#ifdef LN_PLATFORM_WINDOWS

extern Launch::Application* Launch::CreateApplication();

int main(int argc, char** argv)
{
	// Initialize Log
	printf("Initializing Log...\n");
	Launch::Log::Init();
	LN_CORE_INFO("Log initialized");

	// Launch client application
	LN_CORE_INFO("Launching Application...");
	auto app = Launch::CreateApplication();
	app->Run();
	delete app;

	LN_CORE_INFO("Closing Launch");
	return 0;
}

#endif 

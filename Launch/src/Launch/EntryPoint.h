#pragma once

#ifdef LN_PLATFORM_WINDOWS

extern Launch::Application* Launch::CreateApplication();

int main(int argc, char** argv)
{
	printf("Launch Engine\n");
	auto app = Launch::CreateApplication();
	app->Run();
	delete app;
}

#endif 

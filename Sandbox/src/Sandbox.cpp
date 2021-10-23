#include <Launch.h>

class Sandbox : public Application
{
public:
	Sandbox()
	{
		Graphics::draw();
	}
	~Sandbox()
	{

	}
};

Launch::Application* Launch::CreateApplication()
{
	return new Sandbox();
}
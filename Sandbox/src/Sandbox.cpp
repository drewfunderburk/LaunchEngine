#include <Launch.h>

class Sandbox : public Launch::Application
{
public:
	Sandbox()
	{
		Launch::Vector4 test4 = Launch::Vector4();
		LN_TRACE(test4.toString());
		Launch::Vector3 test3 = Launch::Vector3();
		LN_TRACE(test3.toString());
		Launch::Vector2 test2 = Launch::Vector2();
		LN_TRACE(test2.toString());
	}
	~Sandbox()
	{

	}
};

Launch::Application* Launch::CreateApplication()
{
	return new Sandbox();
}
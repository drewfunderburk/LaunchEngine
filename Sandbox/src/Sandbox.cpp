#include <Launch.h>

class Sandbox : public Application
{
public:
	Sandbox()
	{
		Vector4 test4 = Vector4();
		LN_TRACE(test4.toString());
		Vector3 test3 = Vector3();
		LN_TRACE(test3.toString());
		Vector2 test2 = Vector2();
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
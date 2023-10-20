#include "Application.h"

int main(int argc, char* args[])
{
	Application* app = new Application;

	app->Run();

	delete app;

	return 0;
}

#include "Application.h"

int main(int argc, char argv[])
{
	Application application;

	while (application.isRunning())
	{
		application.pollEvents();
		application.update();
		application.render();
	}

	return 0;
}
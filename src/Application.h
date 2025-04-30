#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include <list>
#include <sstream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"

#include "Button.h"
//#include "Label.h"

class Application
{
private:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	sf::Vector2i mousePosition;

	Label label;

	Button* button0;
	Button* button1;
	Button* button2;
	Button* button3;
	Button* button4;
	Button* button5;
	Button* button6;
	Button* button7;
	Button* button8;
	Button* button9;

	Button* equal;
	Button* plus;
	Button* minus;
	Button* multiply;
	Button* devide;

	Button* dot;
	Button* abs;

	std::string inputingValues;
	int result;
	

public:
	Application();
	virtual ~Application();

	const bool isRunning() const;

	void pollEvents();
	void update();
	void render();

};


#endif
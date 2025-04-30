#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include "SFML/Graphics.hpp"

#include "Label.h"

class Button : public sf::RectangleShape
{
private:
	mutable int counter = 0;
	sf::Event ev;
	sf::Vector2f size;
	sf::Vector2f position;
	sf::Color color;

	sf::Text text;
	sf::Font font;

	Label label;
public:
	Button(sf::Vector2f size, sf::Vector2f position, std::string _text);
	virtual ~Button();

	void update(sf::RenderWindow& target);
	void render(sf::RenderTarget& target);

	void initText(std::string _text);
	std::string getText();
};

#endif
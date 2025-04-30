#ifndef LABEL_H
#define LABEL_H

#include <iostream>
#include "SFML/Graphics.hpp"

class Label
{
private:
	sf::Event ev;
	sf::Vector2f size;
	sf::Vector2f position;
	sf::Color color;
	sf::Font font;
public:
	sf::Text outputText;
	std::string inputText;

public:
	Label();
	virtual ~Label();

	void update(sf::RenderWindow& target);
	void render(sf::RenderTarget& target);

	//std::string& getString();
	//sf::Text getText();
};

#endif
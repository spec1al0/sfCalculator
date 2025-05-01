#include "Label.h"

Label::Label()
{
	if (!this->font.loadFromFile("../src/External/src/Sheeping Dogs.ttf"))
		std::cout << "Error: [invalid font]" << std::endl;

	this->outputText.setFont(this->font);
	this->outputText.setCharacterSize(31);
	this->outputText.setFillColor(sf::Color::White);
	this->outputText.setPosition(sf::Vector2f(300, 0));
}

Label::~Label()
{
}

void Label::update(sf::RenderWindow& target)
{
}

void Label::render(sf::RenderTarget& target)
{
	target.draw(this->outputText);
}

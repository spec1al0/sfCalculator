#include "Button.h"

Button::Button(sf::Vector2f size, sf::Vector2f position, std::string _text)
{
	setSize(size);
	setPosition(position);

	this->initText(_text);
}

Button::~Button()
{
	delete this;
}


void Button::update(sf::RenderWindow& target)
{
	if (this->getGlobalBounds().contains(sf::Mouse::getPosition(target).x, sf::Mouse::getPosition(target).y))
	{
		this->setOutlineColor(sf::Color(57, 247, 165));
		this->setOutlineThickness(1.0);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->setFillColor(sf::Color(29, 38, 38));
			this->setOutlineThickness(0);
			//this->label.outputText.setString(" ");
			//this->label.outputText.setString(this->text.getString());	
			//std::cout << "Button has been clicked" << std::endl;
		}
		else
			this->setFillColor(sf::Color(27, 27, 27));

		
	}
	else
	{
		this->setFillColor(sf::Color(27, 27, 27));
		this->setOutlineThickness(0);
	}
}

void Button::render(sf::RenderTarget& target)
{
	target.draw(*this);
	target.draw(this->text);
	target.draw(this->label.outputText);
}

void Button::initText(std::string _text)
{
	if (!this->font.loadFromFile("External/src/Sheeping Dogs.ttf"))
		std::cout << "Error: [invalid font]" << std::endl;

	this->text.setFont(this->font);
	this->text.setString(_text);
	this->text.setCharacterSize(31);
	this->text.setFillColor(sf::Color::Black);
	this->text.setPosition(sf::Vector2f(this->getPosition().x+31, this->getPosition().y));
}

std::string Button::getText()
{
	return this->text.getString();
}


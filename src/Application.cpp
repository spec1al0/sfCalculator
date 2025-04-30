#include "Application.h"

Application::Application()
{
	this->videoMode.width = 403;
	this->videoMode.height = 630;
	this->window = new sf::RenderWindow(videoMode, "SFCalculator", sf::Style::Close);

	this->button0 = new Button(sf::Vector2f(97, 70), sf::Vector2f(203, 557), "0");
	this->button1 = new Button(sf::Vector2f(97, 70), sf::Vector2f(103, 484), "1");
	this->button2 = new Button(sf::Vector2f(97, 70), sf::Vector2f(203, 484), "2");
	this->button3 = new Button(sf::Vector2f(97, 70), sf::Vector2f(303, 484), "3");
	this->button4 = new Button(sf::Vector2f(97, 70), sf::Vector2f(103, 411), "4");
	this->button5 = new Button(sf::Vector2f(97, 70), sf::Vector2f(203, 411), "5");
	this->button6 = new Button(sf::Vector2f(97, 70), sf::Vector2f(303, 411), "6");
	this->button7 = new Button(sf::Vector2f(97, 70), sf::Vector2f(103, 338), "7");
	this->button8 = new Button(sf::Vector2f(97, 70), sf::Vector2f(203, 338), "8");
	this->button9 = new Button(sf::Vector2f(97, 70), sf::Vector2f(303, 338), "9");

	this->equal = new Button(sf::Vector2f(97, 70), sf::Vector2f(3, 557), "=");
	this->plus = new Button(sf::Vector2f(97, 70), sf::Vector2f(3, 484), "+");
	this->minus = new Button(sf::Vector2f(97, 70), sf::Vector2f(3, 411), "-");
	this->multiply = new Button(sf::Vector2f(97, 70), sf::Vector2f(3, 338), "*");
	this->devide = new Button(sf::Vector2f(97, 70), sf::Vector2f(3, 265), "/");

	this->dot = new Button(sf::Vector2f(97, 70), sf::Vector2f(303, 557), ".");
	this->abs = new Button(sf::Vector2f(97, 70), sf::Vector2f(103, 557), "+/-");

}

Application::~Application()
{
	delete this->window;
}

const bool Application::isRunning() const
{
	return this->window->isOpen();
}

void Application::pollEvents()
{
	while (this->window->pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::TextEntered:
			if (this->ev.text.unicode < 128)
			{
				this->label.inputText += static_cast<char>(this->ev.text.unicode);
			}
			this->label.outputText.setString(this->label.inputText);
			break;
		case sf::Event::MouseButtonPressed:
			this->mousePosition = sf::Mouse::getPosition(*this->window);

			if (this->button0->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
			{
				inputingValues.push_back('0');
				this->label.outputText.setString(this->button0->getText());
			}
			else if (this->button1->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
			{
				inputingValues.push_back('1');
				this->label.outputText.setString(this->button1->getText());
			}
			else if (this->button2->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
			{
				inputingValues.push_back('2');
				this->label.outputText.setString(this->button2->getText());
			}
			else if (this->button3->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
			{
				inputingValues.push_back('3');
				this->label.outputText.setString(this->button3->getText());
			}
			else if (this->button4->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
			{
				inputingValues.push_back('4');
				this->label.outputText.setString(this->button4->getText());
			}
			else if (this->button5->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
			{
				inputingValues.push_back('5');
				this->label.outputText.setString(this->button5->getText());
			}
			else if (this->button6->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
			{
				inputingValues.push_back('6');
				this->label.outputText.setString(this->button6->getText());
			}
			else if (this->button7->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
			{
				inputingValues.push_back('7');
				this->label.outputText.setString(this->button7->getText());
			}
			else if (this->button8->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
			{
				inputingValues.push_back('8');
				this->label.outputText.setString(this->button8->getText());
			}
			else if (this->button9->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
			{
				inputingValues.push_back('9');
				this->label.outputText.setString(this->button9->getText());
			}

			else if (this->equal->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
			{
				// outputing in console 
				for(int i = 0; i < inputingValues.size(); i++)
				{ 
					std::cout << inputingValues[i];
				}
				std::cout << std::endl;
				// outputing in console


				for (int i = 0; i < inputingValues.size(); i++)
				{
					if (inputingValues[i] == '+')
					{
						result = static_cast<int>((inputingValues[i - 1] - '0') + (inputingValues[i + 1] - '0'));
					}
					else if (inputingValues[i] == '-')
					{
						result = static_cast<int>((inputingValues[i - 1] - '0') - (inputingValues[i + 1] - '0'));
					}
					else if (inputingValues[i] == '*')
					{
						result = static_cast<int>((inputingValues[i - 1] - '0') * (inputingValues[i + 1] - '0'));
					}
					else if (inputingValues[i] == '/')
					{
						result = static_cast<int>((inputingValues[i - 1] - '0') / (inputingValues[i + 1] - '0'));
					}
				}
				std::cout << result << std::endl;

				std::stringstream ss;
				ss << result;
				std::string resultAsString = ss.str();
				this->label.outputText.setString(resultAsString);

				inputingValues = "";
			}
			else if (this->plus->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
			{
				inputingValues.push_back('+');
				this->label.outputText.setString(this->plus->getText());
			}
			else if (this->minus->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
			{
				inputingValues.push_back('-');
				this->label.outputText.setString(this->minus->getText());
			}
			else if (this->multiply->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
			{
				inputingValues.push_back('*');
				this->label.outputText.setString(this->multiply->getText());
			}
			else if (this->devide->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
			{
				inputingValues.push_back('/');
				this->label.outputText.setString(this->devide->getText());
			}
			else if (this->dot->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
			{
				inputingValues.push_back('.');
				this->label.outputText.setString(this->dot->getText());
			}
			else if (this->abs->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
			{
				this->label.outputText.setString("");
			}
			break;
		default:
			break;
		}
	}
}

void Application::update()
{
	this->label.update(*this->window);

	this->button0->update(*this->window);
	this->button1->update(*this->window);
	this->button2->update(*this->window);
	this->button3->update(*this->window);
	this->button4->update(*this->window);
	this->button5->update(*this->window);
	this->button6->update(*this->window);
	this->button7->update(*this->window);
	this->button8->update(*this->window);
	this->button9->update(*this->window);

	this->equal->update(*this->window);
	this->plus->update(*this->window);
	this->minus->update(*this->window);
	this->multiply->update(*this->window);
	this->devide->update(*this->window);

	this->dot->update(*this->window);
	this->abs->update(*this->window);
	
}

void Application::render()
{
	this->window->clear(sf::Color::Black);

	this->label.render(*this->window);

	this->button0->render(*this->window);
	this->button1->render(*this->window);
	this->button2->render(*this->window);
	this->button3->render(*this->window);
	this->button4->render(*this->window);
	this->button5->render(*this->window);
	this->button6->render(*this->window);
	this->button7->render(*this->window);
	this->button8->render(*this->window);
	this->button9->render(*this->window);

	this->equal->render(*this->window);
	this->plus->render(*this->window);
	this->minus->render(*this->window);
	this->multiply->render(*this->window);
	this->devide->render(*this->window);

	this->dot->render(*this->window);
	this->abs->render(*this->window);

	this->window->display();
}

#include <SFML/Graphics.hpp>

#include "Config.h"
#include "Button.h"

Button::Button(sf::Vector2f size)
	:shape(size)
{
	if (!font.loadFromFile("ariblk.ttf"))
	{
		//error
	}
	this->text.setCharacterSize(24);
	this->text.setFillColor(sf::Color::White);

}

void Button::setString(std::string str) {
	this->text.setString(str);
}

void Button::setFillColor(sf::Color color)
{
	shape.setFillColor(color);
}

void Button::setOutlineColor(sf::Color color)
{
	shape.setOutlineColor(color);
}

void Button::setOutlineThickness(int size)
{
	shape.setOutlineThickness(size);
}

void Button::setPosition(sf::Vector2f position)
{
	shape.setPosition(position);
	text.setPosition(position);
}

void Button::draw(sf::RenderWindow& window)
{

	this->text.setFont(font);
	window.draw(shape);
	window.draw(text);
	
}

#include <SFML/Graphics.hpp>

#include "Config.h"
#include "Button.h"

Button::Button(std::string text, sf::Vector2f position, sf::Vector2f size)
	:shape(size)
{
	if (!font.loadFromFile("ariblk.ttf"))
	{
		//error
	}
	this->text.setFont(font);
	this->text.setString(text);

	this->text.setCharacterSize(24);
	this->text.setFillColor(sf::Color::White);
	this->text.setPosition(position);

}

void Button::setFillColor(sf::Color color)
{
	shape.setFillColor(color);
}

void Button::setOutlineColor(sf::Color color)
{
	shape.setOutlineColor(color);
}

void Button::setOutlineTrickness(int size)
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
	window.draw(shape);
	window.draw(text);
}

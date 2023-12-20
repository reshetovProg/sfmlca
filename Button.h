#pragma once
class Button
{
private:
	sf::Text text;
	sf::Font font;
	sf::RectangleShape shape;
public:
	Button(std::string text, sf::Vector2f position, sf::Vector2f size);
	void setFillColor(sf::Color color);
	void setOutlineColor(sf::Color color);
	void setOutlineTrickness(int size);
	void setPosition(sf::Vector2f position);
	void draw(sf::RenderWindow& window);
};


#pragma once
#include "Button.h"
class Calculator
{
private:
	sf::RenderWindow window;
	//std::vector<sf::RectangleShape> keyboard;

	sf::Text text;
	sf::Font font;
	std::vector<Button> keyboard;
//	sf::RectangleShape rectangle;
public:
	Calculator();
	void run();
private:
	void processEvents();
	void update();
	void render();
};


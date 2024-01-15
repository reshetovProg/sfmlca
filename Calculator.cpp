#include <SFML/Graphics.hpp>
#include <iostream>

#include "Config.h"
#include "Calculator.h"


Calculator::Calculator()
	:window(WINDOW_SIZE, "Calculator")
{
	if (!fontField.loadFromFile("ariblk.ttf"))
	{
		//error
	}
	this->textField.setCharacterSize(40);

	this->textField.setFillColor(sf::Color::White);
	
	

	for (int i = 1; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			Button btn(buttonSize);
			if (i > 1 && j == 3) {
				btn.setFillColor(colorFillOrangeButton);
				btn.setOutlineColor(colorOutlineOrangeButton);
				btn.setOutlineThickness(tricknessSize / 2);
			}
			else {
				btn.setFillColor(colorFillButton);
				btn.setOutlineColor(colorOutlineButton);
				btn.setOutlineThickness(tricknessSize);
			}
			btn.setString(keyboardSymbols[i-1][j]);
			btn.setPosition(sf::Vector2f(j * (buttonSize.x + tricknessSize),
				i * (buttonSize.y + tricknessSize)));
			keyboard.push_back(btn);
		}

	}
	
}

void Calculator::run()
{
	while (window.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Calculator::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				sf::Vector2i mousePosition(sf::Mouse::getPosition(window));
				for (int i = 0; i < keyboard.size(); i++) {
					sf::Vector2f shapePosition(keyboard[i].getPos());
					if (mousePosition.x >= shapePosition.x
						&& mousePosition.x <= shapePosition.x + buttonSize.x
						&& mousePosition.y >= shapePosition.y
						&& mousePosition.y <= shapePosition.y + buttonSize.y) {						
							keyboard[i].setFillColor(keyboard[i].getOutlineColor());
							if (keyboard[i].getString() == "." ||
								keyboard[i].getString() >= "0" &&
								keyboard[i].getString() <= "9") {
								stringField += keyboard[i].getString();
							}
							
					}
					
				}
			}
			

		}

		if (event.type == sf::Event::MouseButtonReleased) {
				for (int i = 0; i < keyboard.size(); i++) {
					keyboard[i].setFillColor(keyboard[i].getColor());
				}
		}
		
    }
}

void Calculator::update()
{
	this->textField.setString(stringField);
	textField.setPosition(sf::Vector2f(
		WINDOW_SIZE.width - textField.getCharacterSize()/1.45*stringField.getSize(),
		buttonSize.y / 2 - textField.getCharacterSize() / 2));
}

void Calculator::render()
{
	window.clear(colorOutlineButton);
	for (auto i : keyboard) {
		i.draw(window);
	}
	this->textField.setFont(fontField);
	window.draw(textField);

	window.display();
}

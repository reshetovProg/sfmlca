#pragma once
#include "Button.h"
class Calculator
{
private:
	sf::RenderWindow window;
	std::vector<Button> keyboard;
	std::string keyboardSymbols[5][4] = {   {"C","CE","X^2","X^Y"},
											{"7","8","9","+"},
											{"4","5","6","-"},
											{"1","2","3","*"},
											{".","0","=","/"} };

public:
	Calculator();
	void run();
private:
	void processEvents();
	void update();
	void render();
};


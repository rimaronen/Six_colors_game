#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
class ToolBar
{
public:
	ToolBar(); // place toolbar buttons on board
	void draw(sf::RenderWindow& window); // draw tool bar
	button_t getButtonPressed(const sf::Vector2f & position) const; // press the buttons in use
	void init(); //init the toolbar
	void disableUsedButton(color_t,color_t);//set the color that the computer and human chose
	//void setButtonHumanPress(color_t color); //unset the color that the computer chose
//	bool checkIfComputerButtonPressed(color_t color); //check if the computer press on button
	bool checkIfButtonPressed(const sf::Vector2f & position);
	~ToolBar();
private:

	std::vector<Button> m_button;
};


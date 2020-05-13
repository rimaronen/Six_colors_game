#pragma once
#include <SFML/Graphics.hpp>
#include <experimental/vector>
#include "Button_util.h"

class Button
{
public:

	Button(const button_t button , bool pressed = false); //C-tor
	void setPoisition(const sf::Vector2f & pos);
	void draw(sf::RenderWindow & window); //print the buttons
	void setShadow(sf::RenderWindow & window);
	void setComputerButtonPressed(color_t color);
	button_t getButton() const; //return button name
	bool isPressed(const sf::Vector2f & pos); 
	bool checkIfButtonIsPressed();
	void setPressed();
	void setUnPressed();
	~Button();


private:
	button_t m_button; //
	sf::Sprite m_sprite; //hold the texture
	sf::Vector2f m_position{ 0, 0 }; //default position
	bool m_pressed;

};


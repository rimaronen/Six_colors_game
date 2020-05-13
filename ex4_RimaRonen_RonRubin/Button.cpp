#include "Button.h"
#include "Button_util.h"
#include "GameResources.h"
#include <iostream>

const float IMAGE_SIZE_X = 50.0f;
const float IMAGE_SIZE_Y = 50.0f;


Button::Button(const button_t  button , bool press)
	:m_button(button)  , m_pressed(press)
{
	//this section load and set the postion buttons
	switch (button)
	{
	case red_button:
		m_position = { (SCREEN_SIZE_X / 2.0f) - 70, 600 };
		m_sprite.setTexture(GameResources::instance().getRedexture());
		break;
	case blue_button:
		m_position = { (SCREEN_SIZE_X / 2.0f) - 140, 600 };
		m_sprite.setTexture(GameResources::instance().getBlueTexture());
		break;
	case green_button:
		m_position = { (SCREEN_SIZE_X / 2.0f) - 210,  600 };
		m_sprite.setTexture(GameResources::instance().getGreenTexture());
		break;
	case orange_button:
		m_position = { (SCREEN_SIZE_X / 2.0f) , 600 };
		m_sprite.setTexture(GameResources::instance().getOrangeTexture());
		break;
	case yellow_button:
		m_sprite.setTexture(GameResources::instance().getYellowTexture());
		m_position = { (SCREEN_SIZE_X / 2.0f) + 70 , 600 };
		break;
	case purple_button:
		m_sprite.setTexture(GameResources::instance().getPurpuleTexture());
		m_position = { (SCREEN_SIZE_X / 2.0f) + 140, 600 };
		break;
	case exit_button:
		m_sprite.setTexture(GameResources::instance().getExitTexture());
		m_position = { 0, SCREEN_SIZE_Y - 55 };
		break;
	case restart_button:
		m_sprite.setTexture(GameResources::instance().getRestartTexture());
		m_position = { SCREEN_SIZE_X - 55, SCREEN_SIZE_Y - 55 };
		break;
	}
	m_sprite.setTextureRect(sf::IntRect(0, 0, 55, 55));	
	m_sprite.setPosition(m_position);

}

void Button::setPoisition(const sf::Vector2f & pos)
{
	m_position = pos;
}

void Button::draw(sf::RenderWindow & window)
{
	setShadow(window);
	window.draw(m_sprite); //draw the button
}

void Button::setShadow(sf::RenderWindow & window)
{
	if (m_sprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
		m_sprite.setColor(sf::Color(200, 235, 255, 225));
	else if (m_pressed == true)
		m_sprite.setColor(sf::Color(255, 0, 0, 10));
	else {
		m_sprite.setColor(sf::Color(255, 255, 255));

	}
}


void Button::setComputerButtonPressed(color_t color)
{
	switch (color)
	{
	case red_color_t:
		m_pressed = true;
		break;
	case green_color_t:
		m_pressed = true;;
		break;
	case blue__color_t:
		m_pressed = true;
		break;
	case yellow_color_t:
		m_pressed = true;
		break;
	case purple_color_t:
		m_pressed = true;
		break;
	case orange_color_t:
		m_pressed = true;
	}
}

//bool Button::checkIfComputerButtonPressed(color_t color)
//{
//	return m_pressed;
//}


button_t Button::getButton() const
{
	return m_button;
}
bool Button::isPressed(const sf::Vector2f & position)
{
	//check if the button pressed
	if (m_sprite.getGlobalBounds().contains(position)) {
		return true ;
	}
	return false;
}
bool Button::checkIfButtonIsPressed()
{
	return m_pressed;
}

void Button::setPressed()
{
	m_pressed = true;
}
void Button::setUnPressed()
{
	m_pressed = false;
}
Button::~Button()
{
}

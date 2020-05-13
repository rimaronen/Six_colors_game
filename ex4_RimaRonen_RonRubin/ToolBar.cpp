#include "ToolBar.h"


const int BUTTONS_SIZE = 8;

ToolBar::ToolBar()
{
	init();
}

void ToolBar::draw(sf::RenderWindow & window)
{

	for (int i = 0; i < m_button.size(); ++i)
		if(!m_button[i].checkIfButtonIsPressed())
		m_button[i].draw(window);
}

button_t ToolBar::getButtonPressed(const sf::Vector2f & position) const
{
	for (auto button : m_button)
		if (button.isPressed(position))
			return button.getButton();
}

void ToolBar::init()
{
	for (int i = 0; i < BUTTONS_SIZE; ++i)
	{
		m_button.push_back({ (button_t)i });
	}
}

void ToolBar::disableUsedButton(color_t computerColor, color_t humanColor)
{
	for (int i = 0; i < m_button.size(); ++i)
		if (m_button[i].getButton() == computerColor || 
			m_button[i].getButton() == humanColor) 
			m_button[i].setPressed();
		else m_button[i].setUnPressed();

}



bool ToolBar::checkIfButtonPressed(const sf::Vector2f & position)
{
	for (int i = 0; i < m_button.size(); ++i) {
		if (m_button[i].isPressed(position)) {
			if (m_button[i].checkIfButtonIsPressed() && m_button[i].getButton() != restart_button)
				return true;
			else {
				m_button[i].setPressed();
			}
		}
		else if (m_button[i].checkIfButtonIsPressed())
			m_button[i].setUnPressed();
	}
	return false;
}

ToolBar::~ToolBar()
{
}

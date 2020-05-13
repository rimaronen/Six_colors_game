#include "Shape.h"


// shape c-tor
Shape::Shape()
	:m_colorName(no_color_t)
{
}

// this function returns the wanted line of the shape
const std::pair<sf::Vector2f, sf::Vector2f>& Shape::getLine(const size_t& lineNumber) const
{
	return m_lines[lineNumber];
}

// return shape color
color_t Shape::getColor() const
{
	return m_colorName;
}

// return neighbor from wanted position
int Shape::getNeighbor(int numOfNeighbor) const
{
	return m_neighbors[numOfNeighbor];
}

// set neighbor 
void Shape::setNeighbor(const size_t& numOfNeighbor)
{
	if (m_nextNeeighbor < NUM_OF_NEIGHBORS) {
		m_neighbors[m_nextNeeighbor] = numOfNeighbor;
		increaseNumberOfNeighbors();
	}
}

Shape::~Shape()
{
}

// set shape's color and size
void Shape::setShape()
{
	m_colorName = getRandomColor(); // get random color
	setColor(m_colorName); // set color
	// set position and scale
	sf::Vector2f old = m_convexShape.getPosition();
	m_convexShape.setScale(old.x + 2.5f, old.y + 2.5f);
	m_convexShape.setOutlineThickness(0.5f);
	m_convexShape.setOutlineColor(sf::Color::Black);
}

void Shape::setBeforeDisplay()
{
	m_convexShape.setScale({ 2.6f,2.6f });
	m_convexShape.setOrigin(-15.0f, -40.0f);
	if (m_playerCaptured)
		m_convexShape.setOutlineColor(sf::Color::White);
}

void Shape::setColor(const color_t & color, bool simulation)
{
	if (!simulation) {
		m_colorName = color;
		switch (color)
		{
		case red_color_t:
			m_convexShape.setFillColor(sf::Color(255, 13, 13));
			break;
		case green_color_t:
			m_convexShape.setFillColor(sf::Color(84, 254, 155));
			break;
		case blue__color_t:
			m_convexShape.setFillColor(sf::Color(0, 152, 252));
			break;
		case yellow_color_t:
			m_convexShape.setFillColor(sf::Color(255, 255, 0));
			break;
		case purple_color_t:
			m_convexShape.setFillColor(sf::Color(255, 30, 255));
			break;
		case orange_color_t:
			m_convexShape.setFillColor(sf::Color(255, 128, 64));
			break;
		}
	}
	else
		m_simulationColor = color;
}

// set shape as conquered by computer
void Shape::setAsCapturedComputer()
{
	m_computerCaptured = true;
}

// set shape as conquered by player
void Shape::setAsCapturedPlayer()
{
	m_playerCaptured = true;
}

// return if captured
bool Shape::isPlayerCaptured() const
{
	return m_playerCaptured;
}

// return if captured
bool Shape::isComputerCaptured() const
{
	return m_computerCaptured;
}

/*this funciton returns the shape color randomle on the board*/
const color_t & Shape::getRandomColor() const
{
	int i;
	i = rand() % 6;

	switch (i) {
	case red_color_t:
		return red_color_t;
	case orange_color_t:
		return orange_color_t;
	case yellow_color_t:
		return yellow_color_t;
	case green_color_t:
		return green_color_t;
	case blue__color_t:
		return blue__color_t;
	case purple_color_t:
		return purple_color_t;
	}
}

void Shape::increaseNumberOfNeighbors()
{
	m_nextNeeighbor += 1;
}

bool operator==(const std::pair<sf::Vector2f, sf::Vector2f>& lLine,
	const std::pair<sf::Vector2f, sf::Vector2f>& rLine)
{
	std::pair<sf::Vector2f, sf::Vector2f> temp;
	temp.first = rLine.second;
	temp.second = rLine.first;

	return ((lLine.first == temp.first && lLine.second == temp.second) ||
		lLine.first == rLine.first && lLine.second == rLine.second);
}

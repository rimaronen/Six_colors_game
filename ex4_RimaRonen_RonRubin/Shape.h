#pragma once
#include "button_util.h"
#include <SFML/Graphics.hpp>

const size_t NUM_OF_NEIGHBORS = 4;
const size_t NEIGHBOR_1 = 0;
const size_t NEIGHBOR_2 = 1;
const size_t NEIGHBOR_3 = 2;
const size_t NEIGHBOR_4 = 3;



class Shape
{
public:
	Shape(); //shapes c-tor
	~Shape();
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void setLine() = 0;
	void setShape();
	virtual void setBeforeDisplay();
	void setColor(const color_t & color , bool simulation = false); // set shape color
	void setNeighbor(const size_t& numOfNeighbor);
	virtual void setAsCapturedComputer(); // set shape as captured by computer
	virtual void setAsCapturedPlayer(); // set shape as captured by player
	virtual bool isPlayerCaptured() const; // return if shape is captured
	virtual bool isComputerCaptured() const; // return if shape is captured by computer
	// return line of shape
	const std::pair<sf::Vector2f, sf::Vector2f>& getLine(const size_t& lineNumber) const;
	color_t getColor() const;
	int getNeighbor(int numOfNeighbor) const; // get neighbor at wanted position
protected:
	sf::ConvexShape m_convexShape;
	int m_neighbors[4] = { -1, -1, -1, -1 }; // set neighbors array for each shape (initialize -1)
	size_t m_nextNeeighbor = 0;
	bool m_playerCaptured = false; // set if shape was conquered by player
	bool m_computerCaptured = false; // set if shape was conquered by player
	//sf::Color m_color; // initialize shape color;
	color_t m_colorName;
	color_t m_simulationColor;
	const color_t & getRandomColor() const; // set color for the shape
	std::pair<sf::Vector2f, sf::Vector2f> m_lines[NUM_OF_NEIGHBORS]; // set lines for shapes
	sf::RectangleShape m_rect;
private:
	void increaseNumberOfNeighbors();
};

// operator == for comparing between two lines 
bool operator==(const std::pair<sf::Vector2f, sf::Vector2f>& lLine, 
	const std::pair<sf::Vector2f, sf::Vector2f>& rLine);
#include "Utils.h"



Utils::Utils()
{
}

/*this function converts board's coords to cell index for the graph*/
unsigned Utils::convertCoordsToCellIndex(const sf::Vector2i& position, const sf::Vector2f& boardSize)
{
	return (position.y * boardSize.x) + position.x;
}

sf::Vector2i Utils::convertCellIndexToCoord(const unsigned& cell)
{
	int xPos = cell % 60; // num of columns
	int yPos = cell / 60;
	return { xPos, yPos };
}

Utils::~Utils()
{
}

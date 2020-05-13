#pragma once
#include <SFML/Graphics.hpp>
class Utils
{
public:
	Utils();
	static unsigned convertCoordsToCellIndex(const sf::Vector2i& position, const sf::Vector2f& boardSize);
	static sf::Vector2i convertCellIndexToCoord(const unsigned& cell);
	~Utils();
};

struct Point {
	sf::Vector2f point_1 = {-1, -1};
	sf::Vector2f point_2 = { -1, -1 };
	sf::Vector2f point_3 = { -1, -1 };
	sf::Vector2f point_4 = { -1, -1 };

};
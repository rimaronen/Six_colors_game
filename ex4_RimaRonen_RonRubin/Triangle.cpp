#include "Triangle.h"

// triangle c-tor
Triangle::Triangle(const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& p3)
{
	sf::ConvexShape triangle(3); // create triangle convex shape
	//set triangle's points
	triangle.setPoint(0, p1);
	triangle.setPoint(1, p2);
	triangle.setPoint(2, p3);

	m_convexShape = triangle;
	
	// set color and size
	Shape::setShape();
	// set lines for shapes
	setLine();
}

Triangle::~Triangle()
{
}

// this function draws the triangle on the board
void Triangle::draw(sf::RenderWindow& window)
{
	setBeforeDisplay();
	window.draw(m_convexShape);
}

// this function sets lines to square
void Triangle::setLine()
{
	m_lines[0].first = m_convexShape.getPoint(0);
	m_lines[0].second = m_convexShape.getPoint(1);

	m_lines[1].first = m_convexShape.getPoint(1);
	m_lines[1].second = m_convexShape.getPoint(2);

	m_lines[2].first = m_convexShape.getPoint(2);
	m_lines[2].second = m_convexShape.getPoint(0);

	// define line with coords -1 to ensure that triangle has no fourth line
	m_lines[3].first = { -1.0f, -1.0f };
	m_lines[3].second = { -1.0f, -1.0f };
}


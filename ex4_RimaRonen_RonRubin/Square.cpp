#include "Square.h"
#include <iostream>
// square c-tor
Square::Square(const Point& points)
{
	sf::ConvexShape square(4); // create square convex shape

	//// set square's points
	square.setPoint(0, points.point_1);
	square.setPoint(1, points.point_2);
	square.setPoint(2, points.point_3);
	square.setPoint(3, points.point_4);


	m_convexShape = square;

	// set color and size
	Shape::setShape();
	// set lines for shapes
	setLine();
}

Square::~Square()
{
}

// this function draws the triangle on the board
void Square::draw(sf::RenderWindow& window) {
	setBeforeDisplay();
	window.draw(m_convexShape);
}

// this function sets lines to square
void Square::setLine()
{
	m_lines[0].first = m_convexShape.getPoint(0);
	m_lines[0].second = m_convexShape.getPoint(1);

	m_lines[1].first = m_convexShape.getPoint(1);
	m_lines[1].second = m_convexShape.getPoint(2);

	m_lines[2].first = m_convexShape.getPoint(2);
	m_lines[2].second = m_convexShape.getPoint(3);

	m_lines[3].first = m_convexShape.getPoint(3);
	m_lines[3].second = m_convexShape.getPoint(0);
}


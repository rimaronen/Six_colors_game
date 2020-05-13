#pragma once
#include "Shape.h"
#include "util.h"

class Triangle : public Shape
{
public:
	Triangle(const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& p3);
	~Triangle();
	virtual void draw(sf::RenderWindow& window) override; // draw triangle
	virtual void setLine() override;
private:
};


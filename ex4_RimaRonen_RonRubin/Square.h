#pragma once
#include "Shape.h"
#include "util.h"

class Square : public Shape
{
public:
	Square(const Point& points);
	~Square();
	virtual void draw(sf::RenderWindow& window) override;
	virtual void setLine() override; // set lines of square
private:
};


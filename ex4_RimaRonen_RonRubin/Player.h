#pragma once
#include <SFML/Graphics.hpp>
#include "Button_util.h"
#include "Shape.h"
#include "Board.h"

class Player
{
public:
	Player(Board& bord);
	~Player();
	virtual void play(const color_t & color) = 0;
	virtual void increaseConqueredArea();
	virtual int getScore() const; // get score
	void resertConquered(); 
	virtual int getOwnCell() = 0; //return the cell
	

protected:
	Board& m_board;
	size_t m_conquered = 1; // count how much shapes are conquered
};


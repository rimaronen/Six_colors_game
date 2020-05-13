#include "Player.h"


// player c-tor
Player::Player(Board& board)
	:m_board(board)
{
}

Player::~Player()
{
}

void Player::increaseConqueredArea()
{
	m_conquered += 1;
}

int Player::getScore() const
{
	return m_conquered;
}

void Player::resertConquered()
{
	m_conquered = 0;
}

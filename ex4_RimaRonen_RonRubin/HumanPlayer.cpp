#include "HumanPlayer.h"



HumanPlayer::HumanPlayer(Board& board)
	:Player(board)
{
}



HumanPlayer::~HumanPlayer()
{
}

// this function accepts color pressed from the player. the player will conquere the neighbors with 
// the similar color pressed
void HumanPlayer::play(const color_t & color)
{
	resertConquered();
	for (size_t shape = 0; shape < m_board.getShapesCapacity(); ++shape)
		if (m_board.isPlayerCaptured(shape)) {
			increaseConqueredArea();
			m_board.setShapeColor(color, shape);
			for (int i = 0; i < NUM_OF_NEIGHBORS; ++i)
				if ((m_board.getNeighbor(shape, i) != -1) &&
					(m_board.getShapeColor(m_board.getNeighbor(shape, i)) == color))
					m_board.setShapeAsCapturedPlayer(m_board.getNeighbor(shape, i));
				
		}
}

int HumanPlayer::getOwnCell()
{

	for (size_t i = 0; i < m_board.getShapesCapacity(); ++i)
	{
		if (m_board.isPlayerCaptured(i)) {
			return i;
		}
	}
}

#include "ComputerPlayer.h"
const int SIX_COLOR = 6;
ComputerPlayer::ComputerPlayer(Board& board)
	:Player(board)
{
}

void ComputerPlayer::play(const color_t & color)
{
	resertConquered();
	for (size_t shape = 0; shape < m_board.getShapesCapacity(); ++shape)
		if (m_board.isComputerCaptured(shape)) {
			m_board.setShapeColor(color, shape, false);
			increaseConqueredArea();
			for (int i = 0; i < NUM_OF_NEIGHBORS; ++i)
				if ((m_board.getNeighbor(shape, i) != -1) &&
					(m_board.getShapeColor(m_board.getNeighbor(shape, i)) == color))
					m_board.setShapeAsCapturedComputer(m_board.getNeighbor(shape, i));
		}

}

color_t ComputerPlayer::getSimulationColor(const color_t  color , const color_t HumanColor)
{
	color_t SimulatorColor = no_color_t;
	int temp = 0;
	int maxNumOfNeigbour = 0;
	for (int tempColor = 0; tempColor < SIX_COLOR; ++tempColor)
	{
		if (tempColor != color && tempColor !=  HumanColor)
			maxNumOfNeigbour = getMaxNeighbor((color_t)tempColor);
		if (maxNumOfNeigbour > temp)
		{
			temp = maxNumOfNeigbour;
			SimulatorColor = (color_t)tempColor;
		}
	}
	return SimulatorColor;
}


int ComputerPlayer::getMaxNeighbor(const color_t color)
{
	int tempCountNeighbors = 0;
	for (size_t shape = 0; shape < m_board.getShapesCapacity(); ++shape)
		if (m_board.isComputerCaptured(shape)) {
			for (int i = 0; i < NUM_OF_NEIGHBORS; ++i)
				if ((m_board.getNeighbor(shape, i) != -1) &&
					(m_board.getShapeColor(m_board.getNeighbor(shape, i)) == color)) {
					m_board.setShapeColor(color, shape, true);
					tempCountNeighbors++;
				}

		}
	return tempCountNeighbors;

}
int ComputerPlayer::getOwnCell()
{

	for (size_t i = 0; i < m_board.getShapesCapacity(); ++i)
	{
		if (m_board.isComputerCaptured(i)) {
			return i;
		}
	}
}



ComputerPlayer::~ComputerPlayer()
{
}

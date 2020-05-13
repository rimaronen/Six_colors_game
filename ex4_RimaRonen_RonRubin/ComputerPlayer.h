#pragma once
#include "Player.h"


class ComputerPlayer : public Player
{
public:
	ComputerPlayer(Board& board);
	~ComputerPlayer();

	virtual void play(const color_t & color) override;
	color_t getSimulationColor(const color_t color, const color_t HumanColor);
	virtual int getOwnCell() override;

private:
	int getMaxNeighbor(const color_t color);
	
};


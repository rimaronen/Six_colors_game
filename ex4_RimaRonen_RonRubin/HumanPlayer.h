#pragma once
#include "Player.h"


class HumanPlayer : public Player
{
public:
	HumanPlayer(Board& board);
	~HumanPlayer();
	virtual void play(const color_t & color) override;
	virtual int getOwnCell() override;

private:

};


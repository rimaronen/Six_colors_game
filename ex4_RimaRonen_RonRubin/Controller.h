#pragma once
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include "ToolBar.h"
#include "Board.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "MessageBox.h"

const int SCREEN_SIZE_X = 600;
const int SCREEN_SIZE_Y = 800;

const std::string VICTORY_MSG = "You Won!";
const std::string LOSE_GAME_MSG = "You Lost :(";

class Controller
{
public:
	Controller(); // c-tor
	~Controller();
	void run(); // run the program
	bool handleMouseButtonKey(const sf::Vector2f & position); // handle mouse press
	void handleEvents(); // main loop handle events

private:
	void checkScore(); // check computer's and player's score
	void drawMessageBox(); // draw message box
	void updatePlayerScore(); // set player score
	void updateComputerScore(); // set computer score
	int getPlayerScore() const; // return player score
	int getComputerScore() const; // return copmuter score
	void restartController(); // restart controller members
	void initScore(); // init player and copmuter score
	sf::RenderWindow m_window;
	sf::Vector2i m_boardSize; // initial board size
	bool ComputerTurn = false;
	bool m_endGame = false; // if player pressed exit button
	bool m_wonGame = false;
	int ComputerCell;
	int HumanCell;
	std::unique_ptr<Board> m_board; // board game
	std::unique_ptr<ToolBar> m_toolBar; //Toolbar
	color_t SimulationColor = no_color_t;
	std::unique_ptr<HumanPlayer> m_humanPlayer;
	std::unique_ptr<ComputerPlayer> m_computerPlayer;

	std::unique_ptr<MessageBox> m_messageBox;
	std::unique_ptr<MessageBox> m_scoreBoxPlayer;
	std::unique_ptr<MessageBox> m_scoreBoxComputer;

	int m_playerScore = 1;
	int m_computerScore = 1;
};


#include "Controller.h"
#include "Button_util.h"


Controller::Controller()
	:m_board(std::make_unique<Board>(m_window)),
	//m_boardSize(300, 450),
	m_toolBar(std::make_unique<ToolBar>()),
	m_computerPlayer(std::make_unique<ComputerPlayer>(*m_board)),
	m_humanPlayer(std::make_unique<HumanPlayer>(*m_board)),
	m_messageBox(std::make_unique<MessageBox>(m_window)),
	m_scoreBoxPlayer(std::make_unique<MessageBox>(m_window)),
	m_scoreBoxComputer(std::make_unique<MessageBox>(m_window))
{
	HumanCell = m_humanPlayer->getOwnCell(); //retrun the first cell
	ComputerCell = m_computerPlayer->getOwnCell(); //return the first cell
}

Controller::~Controller()
{
}

// main function - runs the game
void Controller::run()
{
	sf::View view;
	// create the window
	m_window.create(sf::VideoMode(SCREEN_SIZE_X, SCREEN_SIZE_Y), "6 COLORS GAME");
	m_window.setFramerateLimit(60);

	initScore();

	while (m_window.isOpen() && !m_endGame) { // as long as the window is open
		
		checkScore(); // check player's and computer's score
		m_window.clear(sf::Color::Black); // clear window
		m_board->draw(); // draw the board
		m_toolBar->draw(m_window);
		drawMessageBox();
		handleEvents();
		color_t ComputerColor = m_board->getShapeColor(ComputerCell);
		color_t HumanColor = m_board->getShapeColor(HumanCell);
		m_toolBar->disableUsedButton(HumanColor, ComputerColor);
		if (ComputerTurn) {
			SimulationColor = (color_t)m_computerPlayer->getSimulationColor(ComputerColor, HumanColor);
			m_computerPlayer->play(SimulationColor);

		}
		m_window.display();
	}
	m_window.close();
}

/*this function handles mouse key pressed*/
bool Controller::handleMouseButtonKey(const sf::Vector2f& position)
{
	button_t button = m_toolBar->getButtonPressed(position);

	if (!m_toolBar->checkIfButtonPressed(position)) {
		switch (button)
		{
		case red_button:
			m_humanPlayer->play(red_color_t);
			return true;
		case orange_button:
			m_humanPlayer->play(orange_color_t);
			return true;
		case yellow_button:
			m_humanPlayer->play(yellow_color_t);
			return true;
		case green_button:
			m_humanPlayer->play(green_color_t);
			return true;
		case blue_button:
			m_humanPlayer->play(blue__color_t);
			return true;
		case purple_button:
			m_humanPlayer->play(purple_color_t);
			return true;
		case exit_button:
			exit(EXIT_SUCCESS);
		case restart_button:
			restartController();
			m_board->resetBoard();
		}
		return false;
	}
	else
		return false;
}
/*this function runs main events in the game*/
void Controller::handleEvents()
{
	ComputerTurn = false;
	sf::Event event;
	if (m_window.waitEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			m_endGame = true; // end the game, and close the window
			break;
		case sf::Event::MouseButtonReleased:
			if (!m_messageBox->shouldDisplay()) // is msg box set as not displayed
				if (event.mouseButton.button == sf::Mouse::Button::Left) {
					ComputerTurn = handleMouseButtonKey(m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }));
				}
		}

		updatePlayerScore();
		updateComputerScore();
	}
}

void Controller::checkScore()
{
	if (getPlayerScore() >= (int)m_board->getShapesCapacity() / 2) {
		m_messageBox->display(VICTORY_MSG, player_victory_msg, sf::Vector2f(300, 400));
		m_wonGame = true;
	}

	else if (getComputerScore() >= (int)m_board->getShapesCapacity() / 2) { // if computer won
		m_messageBox->display(LOSE_GAME_MSG, computer_victory_msg, sf::Vector2f(300, 400));
		m_wonGame = false;
	}
}

void Controller::drawMessageBox()
{
	m_scoreBoxComputer->draw();
	
	m_scoreBoxPlayer->draw();
	if (m_messageBox->shouldDisplay())
		m_messageBox->draw();
}

void Controller::updatePlayerScore()
{
	m_playerScore = m_humanPlayer->getScore();
	m_scoreBoxPlayer->display(std::to_string(m_playerScore), player_score_msg, sf::Vector2f(100, 700));
}

void Controller::updateComputerScore()
{
	m_computerScore = m_computerPlayer->getScore();
	m_scoreBoxComputer->display(std::to_string(m_computerScore), computer_score_msg, sf::Vector2f(500, 700));
}

int Controller::getPlayerScore() const
{
	return m_playerScore;
}

int Controller::getComputerScore() const
{
	return m_computerScore;
}

void Controller::restartController()
{
	m_wonGame = false;
	m_messageBox->doNotDisplay();
	m_computerScore = 0;
	m_playerScore = 0;
}

void Controller::initScore()
{
	m_scoreBoxComputer->display(std::to_string(1), computer_score_msg, sf::Vector2f(100, 700));
	m_scoreBoxPlayer->display(std::to_string(1), player_score_msg, sf::Vector2f(500, 700));
}

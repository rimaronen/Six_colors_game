#include "Board.h"
#include <vector>


// board c-tor
Board::Board(sf::RenderWindow& window)
	:m_window(window)
{
	init();
}

Board::~Board()
{
}

void Board::isNotFirstGame()
{
	m_firstGame = false;
}

void Board::replceShapes()
{
	Point point; // create point
	for (int row = 0; row <= ROWS; ++row) {
		std::vector<std::pair<Point, typeShape_t>> vecRow; // create row vector
		for (int col = 0; col <= COLS; ++col)
			vecRow.push_back(std::make_pair(point, init_t)); // create pair for each column
		m_boardGame[row] = vecRow; //  insert the row to the vector
	}

}

void Board::init()
{
	if (m_firstGame)
		creatBoard(); //create the board
	else
		replceShapes(); //replace the shapes
	placeShapesPoints(); // place points of the shapes on the board
	addShapesToBoard();
	initializeNeighbors();

}

// this function creates an empty board to fill it with shapes points
void Board::creatBoard()
{
	Point point; // create point
	for (int row = 0; row <= ROWS; ++row) {
		std::vector<std::pair<Point, typeShape_t>> vecRow; // create row vector
		for (int col = 0; col <= COLS; ++col)
			vecRow.push_back(std::make_pair(point, init_t)); // create pair for each column
		m_boardGame.push_back(vecRow); //  insert the row to the vector
	}
}

/*this function places all the shapes of the game on the board*/
void Board::placeShapesPoints()
{
	initFrameRows(); // init first row

	for (int row = 1; row < ROWS; ++row)
		for (int col = 0; col < COLS; ++col) {
			if (row % 2 != 0) // odd row - handle diamonds
				handleDiamondsOddRow(row, col);
			else { // if row is even
				hadnleFramesCols(row);
				if (col < COLS - 1) // if is not the last cell
					handleDiamondsEvenRow(row, col + 1);
			}
		}
}

/*this function add's the shapes to the board by the points that defines them*/
void Board::addShapesToBoard()
{
	for (int row = 0; row < m_boardGame.size(); ++row)
		for (int col = 0; col < m_boardGame[row].size(); ++col)
			switch (m_boardGame[row][col].second) // switch on shape types
			{
			case vertical_t: // cut shape points veritically to two shapes
				addVirticalTriangles(m_boardGame[row][col].first);
				break;
			case horizontal_t: // cut shape points horizontally to two shapes
				addHorizontalTriangles(m_boardGame[row][col].first);
				break;
			case diamond_t: // keep the shape as diamond
				addDiamondSqueares(m_boardGame[row][col].first);
				break;
			case frame_t: // set the shape as a triangle frame
				addFrameTriangles(m_boardGame[row][col].first);
				break;
			case framePlayer_t:
				addFramePlayar(m_boardGame[row][col].first);
				break;
			case frameComputer_t:
				addFrameComputer(m_boardGame[row][col].first);
				break;
			}
}

// this function creates vertical triangles 
void Board::addVirticalTriangles(const Point & points)
{
	m_shapes.push_back(std::make_unique<Triangle>(points.point_1, points.point_2, points.point_3));
	m_shapes.push_back(std::make_unique<Triangle>(points.point_1, points.point_3, points.point_4));
}

// this function create horizontal triangles 
void Board::addHorizontalTriangles(const Point & points)
{
	m_shapes.push_back(std::make_unique<Triangle>(points.point_1, points.point_2, points.point_4));
	m_shapes.push_back(std::make_unique<Triangle>(points.point_2, points.point_3, points.point_4));
}

// this function creates diamonds squares 
void Board::addDiamondSqueares(const Point & points)
{
	m_shapes.push_back(std::make_unique<Square>(points));
}

// this function creates frame triangles
void Board::addFrameTriangles(const Point & points)
{
	m_shapes.push_back(std::make_unique<Triangle>(points.point_1, points.point_2, points.point_3));
}

// this function creates frame triangle and sets players first location
void Board::addFramePlayar(const Point& points)
{
	m_shapes.push_back(std::make_unique<Triangle>(points.point_1, points.point_2, points.point_3));
	m_shapes[m_shapes.size() - 1]->setAsCapturedPlayer();
}

// this function creates frame triangle and sets computers first location
void Board::addFrameComputer(const Point& points)
{
	m_shapes.push_back(std::make_unique<Triangle>(points.point_1, points.point_2, points.point_3));
	m_shapes[m_shapes.size() - 1]->setAsCapturedComputer();
}

// init first row in board game
void Board::initFrameRows()
{
	// init first cells
	initFirstColsFrame(); // initialize first columns

	// initialize first row frame
	for (int row = 0, col = 1; col < COLS + 1; ++col) {
		m_boardGame[row][col].first.point_1 = { float(col * 10.0f - 5.0f), float(row) };
		m_boardGame[row][col].first.point_2 = { float(col * 10.0f) , float(row + 5.0f) };
		m_boardGame[row][col].first.point_3 = { float(col * 10.0f + 5.0f), float(row) };
		m_boardGame[row][col].second = frame_t;
	}

	int startCol = (ROWS % 2 == 0 ? 0 : 1);
	float factor = (ROWS % 2 == 0 ? 0.0f : 5.0f);
	// initialize last row frame
	for (int row = ROWS, col = 1 - startCol; col <= COLS - startCol; ++col) {
		m_boardGame[row][col].first.point_1 = { float(col * 10.0f) - 5.0f + factor, float(row * 5.0f) };
		m_boardGame[row][col].first.point_2 = { float(col * 10.0f) + factor, float(ROWS * 5.0f - 5.0f) };
		m_boardGame[row][col].first.point_3 = { float(col * 10.0f) + 5.0f + factor, float(row * 5.0f) };
		m_boardGame[row][col].second = frame_t;
	}
	// init last cell
	initLastColsFrame();
}

// this function initializes first columns of the first column
void Board::initFirstColsFrame()
{
	m_boardGame[0][0].first.point_1 = { 0.0f, 0.0f };
	m_boardGame[0][0].first.point_2 = { 0.0f, 5.0f };
	m_boardGame[0][0].first.point_3 = { 5.0f, 0.0f };
	m_boardGame[0][0].second = frame_t;

	if (ROWS % 2 == 0) { // if number of rows is even, need to handle first col triangle
		m_boardGame[ROWS][0].first.point_1 = { 0.0f , float(ROWS * 5.0f - 5) };
		m_boardGame[ROWS][0].first.point_2 = { 0.0f, float(ROWS * 5.0f) };
		m_boardGame[ROWS][0].first.point_3 = { 5.0f, float(ROWS * 5.0f) };
		m_boardGame[ROWS][0].second = framePlayer_t;
	}
}

// this function initializes last columns of the first column
void Board::initLastColsFrame()
{
	m_boardGame[0][COLS].first.point_1 = { float(COLS * 10.0f - 5.0f), 0.0f };
	m_boardGame[0][COLS].first.point_2 = { float(COLS * 10.0f), 5.0f };
	m_boardGame[0][COLS].first.point_3 = { float(COLS * 10.0f), 0.0f };
	m_boardGame[0][COLS].second = frameComputer_t;

	if (ROWS % 2 == 0) {
		m_boardGame[ROWS][COLS].first.point_1 = { float(COLS) * 10.0f, float(ROWS * 5.0f - 5.0f) };
		m_boardGame[ROWS][COLS].first.point_2 = { float(COLS * 10.0f - 5.0f), float(ROWS * 5.0f) };
		m_boardGame[ROWS][COLS].first.point_3 = { float(COLS * 10.0f), float(ROWS * 5.0f) };
		m_boardGame[ROWS][COLS].second = frame_t;
	}
}
// handle diamonds point
void Board::handleDiamondsOddRow(const int& row, const int& col)
{
	m_boardGame[row][col].first.point_1 = sf::Vector2f(col * 10 + 5, (row * 5) - 5);
	m_boardGame[row][col].first.point_2 = sf::Vector2f(col * 10, row * 5);
	m_boardGame[row][col].first.point_3 = sf::Vector2f(col * 10 + 5, (row * 5) + 5);
	m_boardGame[row][col].first.point_4 = sf::Vector2f(col * 10 + 10, row * 5);

	m_boardGame[row][col].second = getGamebleShape();

}


void Board::handleDiamondsEvenRow(const int& row, const int& col)
{
	m_boardGame[row][col].first.point_1 = sf::Vector2f(col * 10, (row * 5) - 5);
	m_boardGame[row][col].first.point_2 = sf::Vector2f(col * 10 - 5, row * 5);
	m_boardGame[row][col].first.point_3 = sf::Vector2f(col * 10, (row * 5) + 5);
	m_boardGame[row][col].first.point_4 = sf::Vector2f(col * 10 + 5, row * 5);

	m_boardGame[row][col].second = getGamebleShape();
}

// this function handles the shapes in the frames 
void Board::hadnleFramesCols(const int& row)
{
	int firstCol = 0;

	// left frame
	m_boardGame[row][firstCol].first.point_1 = { 0, float(row * 5 - 5) };
	m_boardGame[row][firstCol].first.point_2 = { 0, float(row * 5 + 5) };
	m_boardGame[row][firstCol].first.point_3 = { 5, float(row * 5) };
	m_boardGame[row][firstCol].second = frame_t;

	//right frame
	m_boardGame[row][COLS].first.point_1 = { float(COLS * 10), float(row * 5 - 5) };
	m_boardGame[row][COLS].first.point_2 = { float((COLS * 10) - 5), float(row * 5) };
	m_boardGame[row][COLS].first.point_3 = { float(COLS * 10), float(row * 5 + 5) };
	m_boardGame[row][COLS].second = frame_t;
}


// this function returns shapes type randomly
typeShape_t Board::getGamebleShape() const
{
	int i = rand() % 3;

	switch (i)
	{
	case 0:
		return vertical_t;
	case 1:
		return horizontal_t;
	case 2:
		return diamond_t;
	}
}

// this function draws the board
void Board::draw()
{
	// draw shapes on the board
	for (int cell = 0; cell < m_shapes.size(); ++cell)
		m_shapes[cell]->draw(m_window);
}

// this function initializes the neighbors of the shapes
void Board::initializeNeighbors()
{
	for (size_t i = 0; i < m_shapes.size(); ++i)
		addNeighbors(i);
}

// this function adds the neighbors of the sent shape
void Board::addNeighbors(const size_t & checkedShape)
{
	// add all checked shape existing neighbors
	for (int cell = checkedShape + 1; cell < m_shapes.size(); ++cell) {
		if (isNeighbor(checkedShape, cell, NEIGHBOR_1)) {
			m_shapes[checkedShape]->setNeighbor(cell);
			m_shapes[cell]->setNeighbor(checkedShape);
		}
		if (isNeighbor(checkedShape, cell, NEIGHBOR_2)) {
			m_shapes[checkedShape]->setNeighbor(cell);
			m_shapes[cell]->setNeighbor(checkedShape);
		}
		if (isNeighbor(checkedShape, cell, NEIGHBOR_3)) {
			m_shapes[checkedShape]->setNeighbor(cell);
			m_shapes[cell]->setNeighbor(checkedShape);
		}
		if (isNeighbor(checkedShape, cell, NEIGHBOR_4)) {
			m_shapes[checkedShape]->setNeighbor(cell);
			m_shapes[cell]->setNeighbor(checkedShape);
		}
	}
}

// this function checkes if 
bool Board::isNeighbor(const size_t& shape1, const size_t& shape2, const int& line)
{
	if (m_shapes[shape1]->getLine(line).first == sf::Vector2f(-1, -1))
		return false;
	for (int i = 0; i < NUM_OF_NEIGHBORS; ++i)
		if (m_shapes[shape1]->getLine(line) == m_shapes[shape2]->getLine(i))
			return true;
	return false;
}

void Board::resetBoard()
{
	for (int i = 0; i < m_boardGame.size(); ++i)
		for (int j = 0; j < m_boardGame[i].size(); ++j)
			m_boardGame[i].clear();
	isNotFirstGame();//update that board restarts- not first game
	init();
}

size_t Board::getShapesCapacity() const
{
	return m_shapes.size();
}

bool Board::isComputerCaptured(const size_t & numOfShape) const
{
	return m_shapes[numOfShape]->isComputerCaptured();
}


bool Board::isPlayerCaptured(const size_t& numOfShape) const
{
	return m_shapes[numOfShape]->isPlayerCaptured();
}

void Board::setShapeColor(const color_t & color, const size_t& numOfShapes , bool simulation)
{
	
	m_shapes[numOfShapes]->setColor(color , simulation);
}

int Board::getNeighbor(const size_t& numOfShape, const int& numOfNeighbor) const
{
	return m_shapes[numOfShape]->getNeighbor(numOfNeighbor);
}

color_t Board::getShapeColor(const size_t& numOfShape) const
{
	return m_shapes[numOfShape]->getColor();
}

void Board::setShapeAsCapturedPlayer(const size_t& shapeNumber)
{
	m_shapes[shapeNumber]->setAsCapturedPlayer();
}

void Board::setShapeAsCapturedComputer(const size_t & shapeNumber)
{
	m_shapes[shapeNumber]->setAsCapturedComputer();
}

#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "Shape.h"
#include "Triangle.h"
#include "Square.h"
#include "util.h"

const int ROWS = 36; // number of rows 46
const int COLS = 20; // number of columns 30
// shape cut type
enum typeShape_t { vertical_t, horizontal_t, diamond_t, frame_t, framePlayer_t, frameComputer_t, init_t };

class Board
{
public:
	Board(sf::RenderWindow& window);
	~Board();
	void draw(); // draw the board
	void initializeNeighbors(); // initialize shapes neighbors
	void resetBoard();
	size_t getShapesCapacity() const;
	bool isComputerCaptured(const size_t& numOfShape)const;
	bool isPlayerCaptured(const size_t& numOfShape) const;
	void setShapeColor(const color_t & color, const size_t& numOfShapes , bool simulate = false);
	int getNeighbor(const size_t& numOfShape, const int& numOfNeighbor) const; // get neighbor at wanted position
	color_t getShapeColor(const size_t& numOfShape) const;
	void setShapeAsCapturedPlayer(const size_t& shapeNumber);
	void setShapeAsCapturedComputer(const size_t& shapeNumber);

private:
	void isNotFirstGame();
	void replceShapes();
	void init(); //initialize the board
	void creatBoard(); // create empty board 
	void placeShapesPoints(); // place the shape on the board
	void addShapesToBoard(); // add the shapes to the board by their definision (virtically, horizoltally)
	void addVirticalTriangles(const Point& points); // add vertival triangles
	void addHorizontalTriangles(const Point& points); // add horizontal triangles
	void addDiamondSqueares(const Point& points);
	void addFrameTriangles(const Point& points);
	void addFramePlayar(const Point& points);
	void addFrameComputer(const Point& points);
	void initFrameRows(); //initialize first rows
	void initFirstColsFrame(); // init first columns frames
	void initLastColsFrame(); // init last columns frames
	void handleDiamondsOddRow(const int& row, const int& col);
	void handleDiamondsEvenRow(const int& row, const int& col);
	void hadnleFramesCols(const int& row);
	typeShape_t getGamebleShape() const;
	void addNeighbors(const size_t& checkedShape); // add neighbors to sent cell
	bool isNeighbor(const size_t& shape1, const size_t& shape2, const int& line); // check if any similar line

	// initial board game
	std::vector < std::vector<std::pair<Point, typeShape_t>>> m_boardGame;
	std::vector<std::unique_ptr<Shape>> m_shapes; // hold the shapes
	sf::RenderWindow& m_window;
	color_t computerColor;
	bool m_firstGame = true;
};


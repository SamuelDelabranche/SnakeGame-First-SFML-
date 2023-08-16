#include "Snake.h"

using namespace std;

Snake::Snake() {
	this->_dir = Direction::None;
	this->_gridSize = 32;

	this->_snakeShape.setSize(sf::Vector2f(this->_gridSize - 1, this->_gridSize - 1));
	this->_snakeShape.setOrigin(_gridSize / 2, _gridSize / 2);
	this->_snakeShape.setFillColor(sf::Color::Blue);

	this->_snakeBody.push_back(SnakeSegment(0, 0));
}

Snake::~Snake(){}


Direction& Snake::getDirection() { return this->_dir; }
vector<SnakeSegment>& Snake::getSnakeBody() { return this->_snakeBody; }
sf::Drawable& Snake::getSnakeShape() { return this->_snakeShape; }

void Snake::setDirection(Direction& l_newDir) { this->_dir = l_newDir; }


void Snake::setPositionShape(sf::Vector2f l_positionSnakePart) {
	this->_snakeShape.setPosition(l_positionSnakePart);
}
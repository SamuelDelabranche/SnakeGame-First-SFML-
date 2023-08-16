#include "Snake.h"

Snake::Snake() {
	this->_dir = DirectionList::None;
	this->_snakeBody.push_back(SnakeSegment(0, 0));

	this->initShape();
}

void Snake::initShape() {
	this->_snakeShape.setOrigin()
}

Snake::~Snake(){}

DirectionList Snake::getDir() { return _dir; }

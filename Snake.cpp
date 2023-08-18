#include "Snake.h"

using namespace std;

Snake::Snake() {
	this->_dir = Direction::None;
	this->_gridSize = 32;

	this->_snakeShape.setSize(sf::Vector2f(this->_gridSize, this->_gridSize));
	this->_snakeShape.setFillColor(sf::Color::Blue);

	
}

Snake::~Snake(){}


Direction& Snake::getDirection() { return this->_dir; }
vector<SnakeSegment>& Snake::getSnakeBody() { return this->_snakeBody; }
sf::Drawable& Snake::getSnakeShape() { return this->_snakeShape; }
sf::Vector2i Snake::getPosition() { return this->_snakeBody[0].position; }

void Snake::setDirection(Direction l_newDir) { this->_dir = l_newDir; }


void Snake::setPositionShape(sf::Vector2f l_positionSnakePart) {
	this->_snakeShape.setPosition(l_positionSnakePart);
}

void Snake::tick(sf::Time& t_dt) {
	if (this->_snakeBody.empty()) { return; }
	if (this->_dir == Direction::None) { return; }
	this->move();

	//cout << "Head Position: " << this->_snakeBody[0].position.x << " " << this->_snakeBody[0].position.y << endl;
}

void Snake::move() {
	if (this->_dir == Direction::Top) { this->_snakeBody[0].position.y--; }
	if (this->_dir == Direction::Down) { this->_snakeBody[0].position.y++; }
	if (this->_dir == Direction::Left) { this->_snakeBody[0].position.x--; }
	if (this->_dir == Direction::Right) { this->_snakeBody[0].position.x++; }

}
#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include "SFML/Graphics.hpp"

#include <vector>

enum Direction{None, Top, Down, Right, Left};

struct SnakeSegment {
	SnakeSegment(int x, int y): position(x,y){}
	sf::Vector2i position;
};

class Snake{
	public:
		Snake();
		~Snake();

		Direction& getDirection();
		std::vector<SnakeSegment>& getSnakeBody();
		sf::Drawable& getSnakeShape();

		void setDirection(Direction& l_newDir);
		void setPositionShape(sf::Vector2f l_positionSnakePart);

	private:
		unsigned int _gridSize;
		Direction _dir;

		std::vector<SnakeSegment> _snakeBody;
		sf::RectangleShape _snakeShape;

};

#endif
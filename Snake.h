#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include "SFML/Graphics.hpp"
#include "Game.h"

#include <vector>

enum DirectionList {None, Top, Down, Right, Left};
struct SnakeSegment {
	SnakeSegment(int x, int y): position(x,y){}
	sf::Vector2u position;
};

class Snake{
	public:
		Snake();
		~Snake();

		DirectionList getDir();

	private:
		void initShape();

		DirectionList _dir;
		std::vector<SnakeSegment> _snakeBody;

		sf::RectangleShape _snakeShape;

};

#endif
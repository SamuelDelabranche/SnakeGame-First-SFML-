#pragma once
#ifndef FRUIT_H
#define FRUIT_H

#include "SFML/Graphics.hpp"
#include <time.h>
#include <iostream>

class Fruit{
	public:
		Fruit();
		~Fruit();
		sf::Vector2i getPosition() const;
		sf::Sprite getSprite() const;

		void randomPosition(const sf::Vector2u& l_gridSize);
	private:
		float _size;

		
		void initVariables();
		sf::Vector2i _position;

		sf::Texture _spriteTexture;
		sf::Sprite _fruitSprite;
};

#endif
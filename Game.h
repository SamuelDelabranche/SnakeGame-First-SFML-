#pragma once
#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "Snake.h"
#include "Fruit.h"

#include <vector>

class Game{
	public:
		Game(const std::string l_title = "No Title", const sf::Vector2u l_size = { 800, 600 });
		~Game();
		Window* getWindow();
		sf::Vector2u getWindSizeGrid();
		sf::Vector2i getMiddleWindSize();


		void update(); // update positions (game logic)
		void render(); // update the renders
		bool isRunning();


	private:
		void initBorderRender();
		void initVariables();
		void drawBorder();
		void drawSnake();

		bool checkCollision();

		void drawFPS();
		void drawScore();
		void drawFruit();

		void checkDirectionKey();


		sf::Vector2u _windSize;

		Window _window;
		Snake _snake;
		Fruit _fruit;

		sf::RectangleShape _borderSide[4];

		sf::Clock _clock;
		sf::Time _dt;
		sf::Time _movementTimer;
		float _delay;

		unsigned int _score;

		bool _end;



};

#endif
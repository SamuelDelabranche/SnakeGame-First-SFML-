#pragma once
#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "Snake.h"

#include <vector>

class Game{
	public:
		Game(const std::string l_title = "No Title", const sf::Vector2u l_size = { 800, 600 });
		~Game();
		Window* getWindow();

		void update(); // update positions (game logic)
		void render(); // update the renders


	private:
		void initBorderRender();
		void initVariables();
		void drawBorder();

		sf::Vector2u _windSize;

		Window _window;
		Snake _snake;
		sf::RectangleShape _borderSide[4];


};

#endif
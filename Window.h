#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include "SFML/Graphics.hpp"

#include <string>
#include <iostream>

class Window{
	public:
		Window(const std::string l_title = "No Title", const sf::Vector2u l_size = {800, 600});
		~Window();

		void update(); // update the screen

		void clear();
		void display();
		void draw(const sf::Drawable& l_object);

		bool isDone();

		sf::Vector2u getWindSize() const;
		unsigned int getObjectSize() const;
		void printElement(const std::string& element) const ;


	private:
		void initVariables(const std::string l_title, const sf::Vector2u l_size);
		void destroy();

		void windowSizeAdapter();

		void pollEvents(sf::Event& l_event);

		sf::RenderWindow _window;

		sf::Vector2u _windSize;
		unsigned int _gameObjectSize;


		std::string _title;

		bool _isDone;
};

#endif
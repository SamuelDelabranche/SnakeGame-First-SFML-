#include "Game.h"

using namespace std;

Game::Game(const string l_title, const sf::Vector2u l_size) : _window(l_title, l_size){
	this->initVariables();
	this->initBorderRender();
}

void Game::initVariables() {

	this->_windSize = { 
		this->_window.getWindSize().x / this->_window.getObjectSize(), 
		this->_window.getWindSize().y / this->_window.getObjectSize() };


}

void Game::initBorderRender() {
	float tempGameObjectSize = static_cast<float>(this->_window.getObjectSize());

	for (auto& object : this->_borderSide) {
		object.setSize(sf::Vector2f(tempGameObjectSize, tempGameObjectSize));
		object.setFillColor(sf::Color::Red);
		object.setOrigin(0.f, 0.f);
	}


}

void Game::drawBorder() {
	float tempGameObjectSize = static_cast<float>(this->_window.getObjectSize());
	sf::Vector2i tempPos;

	for (int i = 0; i <= this->_windSize.x; ++i) { // Top / bottom layer
		this->_borderSide[0].setPosition(sf::Vector2f(
			tempPos.x,
			0));
		this->_borderSide[2].setPosition(sf::Vector2f(
			tempPos.x,
			this->_window.getWindSize().y - tempGameObjectSize));

		if (i > 0 && i < (this->_windSize.y-1)) { 
;
		}

		tempPos.x += tempGameObjectSize ;
		this->_window.draw(this->_borderSide[0]);
		this->_window.draw(this->_borderSide[2]);
	}

	tempPos.x = tempGameObjectSize; 
	tempPos.y = tempGameObjectSize;

	for (int i = 1; i <= this->_windSize.y-2; ++i) { // Left / right layer
		this->_borderSide[1].setPosition(sf::Vector2f(
			0,
			tempPos.y));
		this->_borderSide[3].setPosition(sf::Vector2f(
			this->_window.getWindSize().x - tempGameObjectSize,
			tempPos.y));


		tempPos.y += tempGameObjectSize;
		this->_window.draw(this->_borderSide[1]);
		this->_window.draw(this->_borderSide[3]);

	}

}

Game::~Game(){}

Window* Game::getWindow() { return& this->_window; }

void Game::render() {
	this->_window.clear();
	this->drawBorder();
	this->_window.display();
}

void Game::update() {
	this->_window.update();	

}
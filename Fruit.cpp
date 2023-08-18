#include "Fruit.h"

using namespace std;
Fruit::Fruit() { this->initVariables(); }

void Fruit::initVariables() {
	if (this->_spriteTexture.loadFromFile("Sprite/Apple.png")) {
		this->_size = 32.f;

		this->_fruitSprite.setTexture(this->_spriteTexture);
		this->_fruitSprite.scale(static_cast<float>(this->_size / this->_spriteTexture.getSize().x), static_cast<float>(this->_size / this->_spriteTexture.getSize().y));
	} 
}


sf::Vector2i Fruit::getPosition() const { return this->_position; }
sf::Sprite Fruit::getSprite() const { return this->_fruitSprite; }

Fruit::~Fruit(){}

void Fruit::randomPosition(const sf::Vector2u& l_gridSize) {
	srand(time(NULL));

	this->_position = sf::Vector2i(
		static_cast<int>((rand() % (l_gridSize.x - 2)) + 1),
		static_cast<int>((rand() % (l_gridSize.y - 2)) + 1));

	this->_fruitSprite.setPosition(this->_position.x * this->_size, this->_position.y* this->_size);

	cout << "Fruit : W[" << this->_fruitSprite.getPosition().x / this->_size << "] | H[" << this->_fruitSprite.getPosition().y / this->_size << "]" << endl;

}
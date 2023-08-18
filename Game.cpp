#include "Game.h"

using namespace std;

Game::Game(const string l_title, const sf::Vector2u l_size) : _window(l_title, l_size){
	this->initVariables();
	this->initBorderRender();

}

void Game::initVariables() {
	this->_end = false;
	this->_movementTimer = sf::Time::Zero;


	this->_windSize = { 
		this->_window.getWindSize().x / this->_window.getObjectSize(), 
		this->_window.getWindSize().y / this->_window.getObjectSize() };

	cout << "GridSize : W[" << this->_windSize.x << "] | H[" << this->_windSize.y << "]" << endl;
	this->_snake.getSnakeBody().push_back(SnakeSegment(this->_windSize.x / 2, this->_windSize.y / 2)); // Head Snake

	this->_delay = 0.2f;
	this->_score = 0;

	// Fruit
	this->_fruit.randomPosition(this->_windSize);


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

void Game::drawSnake(){
	vector<SnakeSegment> tempSnakeBody = this->_snake.getSnakeBody();
	
	for (auto& snakePart : tempSnakeBody) {
		this->_snake.setPositionShape(sf::Vector2f(tempSnakeBody[0].position.x * this->_window.getObjectSize(),
			tempSnakeBody[0].position.y * this->_window.getObjectSize()));
		this->_window.draw(this->_snake.getSnakeShape());
	}
	
}

void Game::drawFPS() {
	sf::Font t_font;

	if (t_font.loadFromFile("./Font/Ruwudu-Medium.ttf")) {
		sf::Text t_FpsText;

		t_FpsText.setFont(t_font);
		t_FpsText.setString("FPS: " + std::to_string(static_cast<int>(1.f / this->_dt.asSeconds())));
		t_FpsText.setCharacterSize(24);

		t_FpsText.setPosition(10,0);
		
		this->_window.draw(t_FpsText);
	}

}

void Game::drawScore() {
	sf::Font t_font;

	if (t_font.loadFromFile("./Font/Ruwudu-Medium.ttf")) {
		sf::Text t_scoreText;

		t_scoreText.setFont(t_font);
		t_scoreText.setString("Score: " + to_string(this->_score));
		t_scoreText.setCharacterSize(24);

		t_scoreText.setPosition(this->_window.getWindSize().x / 2, 0);

		this->_window.draw(t_scoreText);
	}

}


void Game::drawFruit() {
	if(this->_snake.getPosition().x == this->_fruit.getPosition().x &&
		this->_snake.getPosition().y == this->_fruit.getPosition().y) 
	{
		this->_fruit.randomPosition(this->_windSize);
		this->_score += 10;

		cout << "+" << this->_score << endl;
	}

	this->_window.draw(this->_fruit.getSprite());
}

Game::~Game(){}

Window* Game::getWindow() { return& this->_window; }
sf::Vector2u Game::getWindSizeGrid() { return this->_windSize; }
sf::Vector2i Game::getMiddleWindSize() { return sf::Vector2i(this->getWindSizeGrid().x / 2, this->getWindSizeGrid().y / 2); }
bool Game::isRunning() { return !this->_end; }


void Game::render() {
	this->_window.clear();
	this->drawSnake();

	this->drawBorder();
	this->drawFPS();
	this->drawScore();
	this->drawFruit();

	this->_window.display();
}

void Game::update() {
	this->_dt = this->_clock.restart();

	if (!(this->_end)) {

		this->_movementTimer += this->_dt;
		this->checkDirectionKey();
		if (this->checkCollision()) { this->_end = true; }
		if (this->_movementTimer >= sf::seconds(this->_delay)) {
			this->_snake.tick(this->_dt);
			this->_movementTimer = sf::Time::Zero;
		}
	}

	this->_window.update();	
}

void Game::checkDirectionKey() {
	if (!(this->_window.isDone())) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			this->_snake.setDirection(Direction::None);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (this->_snake.getDirection() != Direction::Down) { this->_snake.setDirection(Direction::Top); }
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (this->_snake.getDirection() != Direction::Top) { this->_snake.setDirection(Direction::Down); }
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			if (this->_snake.getDirection() != Direction::Right) { this->_snake.setDirection(Direction::Left); }
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			if (this->_snake.getDirection() != Direction::Left) { this->_snake.setDirection(Direction::Right); }
		}
	}
	else { this->_snake.setDirection(Direction::None); }
}

bool Game::checkCollision() {
	if (this->_snake.getPosition().x  <= 0 || 
		this->_snake.getPosition().x >= this->_windSize.x || 
		this->_snake.getPosition().y <= 0 ||
		this->_snake.getPosition().y >= this->_windSize.y) {
		return true; cout << "Border Touched! " << endl;
	}
return false;
}
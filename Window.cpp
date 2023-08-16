#include "Window.h"

using namespace std;

Window::Window(const string l_title, const sf::Vector2u l_size) { this->initVariables(l_title, l_size); }
Window::~Window() { this->destroy(); }
void Window::destroy() { this->_window.close(); }

void Window::initVariables(const string l_title, const sf::Vector2u l_size) {
	this->_windSize = l_size;
	this->_title = l_title;
	this->_gameObjectSize = 32;

	windowSizeAdapter();
	_window.create({_windSize.x, _windSize.y}, _title, sf::Style::Titlebar | sf::Style::Close);

	this->_isDone = false;
}

void Window::windowSizeAdapter() {
	struct checkSize { checkSize(): _w(false), _h(false){} 
		bool _w, _h;
	};

	checkSize tempcheckSize;

	while (!(tempcheckSize._w && tempcheckSize._h)) {
		if (this->_windSize.x % this->_gameObjectSize != 0) { ++this->_windSize.x; }
		else { tempcheckSize._w = true; }

		if (this->_windSize.y % this->_gameObjectSize != 0) { ++this->_windSize.y; }
		else { tempcheckSize._h = true; }
	
	}
	printElement("windSize");
}

void Window::printElement(const string& l_element) const {
	if (l_element == "windSize") { cout << "Window Size: W[" << this->_windSize.x << "] H[" << this->_windSize.y << "]" << endl; }
}



void Window::update() {
	sf::Event _event;

	this->pollEvents(_event);

}

bool Window::isDone() { return this->_isDone; }
sf::Vector2u Window::getWindSize() const { return this->_windSize; }
unsigned int Window::getObjectSize() const { return this->_gameObjectSize; }


void Window::pollEvents(sf::Event& l_event) {
	while (_window.pollEvent(l_event)) {
		if (l_event.type == sf::Event::Closed) { this->_isDone = true; }
	}
}

void Window::draw(const sf::Drawable& l_object) { this->_window.draw(l_object); }
void Window::clear() { this->_window.clear(sf::Color::Black); }
void Window::display() { this->_window.display(); }



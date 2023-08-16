#include "Game.h"

int main() {
	Game game;
	while (!(game.getWindow()->isDone())) { // is Game working
		game.update(); // update game ( characters.. )
		game.render(); // set render to characters.. )
	}

	return 0;
}
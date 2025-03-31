// Assignment 1; Dead Man's Draw++.cpp : Defines the entry point for the application.
//

#include "Assignment 1; Dead Man's Draw++.h"

using namespace std;

class Game {
public:
	Game(); 
	~Game(); 

	void run() {
		std::cout << "works" << std::endl;
	}
};

Game::Game() {

}
Game::~Game() {

}

// Application Entry Point
int main()
{
	Game game = new Game(); // Create game instance
	game.run() // Run game
	delete game; // Free memory once game is finished
	return 0;
}

// DeadMansDraw.cpp : Defines the entry point for the application.
//

#include "DeadMansDraw.h"

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
	Game* game = new Game(); // Create game instance
	game->run(); // Run game
	delete game; // Free memory once game is finished
	return 0;
}

// DeadMansDraw.cpp : Defines the entry point for the application.

#include <iostream>
#include <random>

#include "DeadMansDraw.h"
#include "Deck.h"
#include "Player.h"

// Constructor and destructor
Game::Game() : _deck(new Deck), _turn(0), _round(1), _currentPlayer(nullptr) {
}
Game::~Game() {
	delete _deck;

	for (Player* player : _players) {
		delete player;
	}
	_player.clear();
}

// Game functions
void Game::startGame() {

}

void Game::switchPlayer()
{
}

bool Game::playTurn()
{
	return false;
}

void Game::endGame()
{
}

Player* Game::getWinner()
{
	return nullptr;
}

// Getters
Deck* Game::getDeck()
{
	return nullptr;
}

int Game::getTurn()
{
	return 0;
}

int Game::getRound()
{
	return 0;
}

Player* Game::getCurrentPlayer()
{
	return nullptr;
}

std::vector<Player*>& Game::getPlayers()
{
	// TODO: insert return statement here
}



// Application Entry Point
int main()
{
	Game* game = new Game(); // Create game instance
	game->run(); // Run game
	delete game; // Free memory once game is finished
	return 0;
}

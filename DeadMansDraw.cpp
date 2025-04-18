// DeadMansDraw.cpp : Defines the entry point for the application.

#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <iterator>

#include "DeadMansDraw.h"
#include "Deck.h"
#include "Player.h"

// Constructor and destructor
Game::Game() : _deck(new Deck(*this)), _turn(0), _round(0), _currentPlayer(nullptr) {
}
Game::~Game() {
	delete _deck;

	for (Player* player : _players) {
		delete player;
	}
	_players.clear();
}

// Game functions
void Game::startGame() {
	// Create and shuffle deck
	_deck->createDeck();
	_deck->shuffle();

	// Create new players
	_players.push_back(new Player());
	_players.push_back(new Player());

	_currentPlayer = _players[0];

	// Begin Round
	while (true) {
		// Increment round
		_round++;

		// Check if game is over
		if (getDeck()->isEmpty() or _turn > 20) {
			break;
		}
		// Play turn
		playTurn();

		// Switch player
		switchPlayer();
	}
	// End game
	endGame();

}

void Game::switchPlayer() 
{
	if (_players.empty()) {
		std::cout << "Error: No players available to switch." << std::endl;
		return;
	}

	// Find the current player's index
	auto it = std::find(_players.begin(), _players.end(), _currentPlayer);

	// If the current player is found in the vector and not the final entry
	if (it != _players.end()) {
		// Calculate the next player's index, wrapping around if necessary
		++it;
		_currentPlayer = *it;
	}
	// Set current player to the first player
	else {
		_currentPlayer = _players[0];
	}
}


bool Game::playTurn()
{
	// Increment turn
	++_turn;

	// Draw a card for the current player
	_currentPlayer->play(_deck->drawCard());

	// Loop while the player has not busted
	while (!_currentPlayer->hasBusted()) {
		// Ask the player if they want to draw again
		std::cout << "Draw again? (y/n): ";
		char choice;
		std::cin >> choice;

		// Convert input to a boolean
		bool drawAgain = (choice == 'y' || choice == 'Y');

		// If the player chooses not to draw, exit the loop
		if (!drawAgain) {
			_currentPlayer->bankCards();
			break;
		}

		// Otherwise, draw another card
		_currentPlayer->play(_deck->drawCard());
	}

	return false;
}

void Game::endGame()
{
	std::cout << "--- Game Over ---" << std::endl;
	// Display each players banlk
	for (Player* player : _players) {
		player->printBank();
	}
	// Print winners name
	std::cout << getWinner()->getName() << " wins!" << std::endl;
}

Player* Game::getWinner()
{
	// Find the player with the highest score
	Player* winner = nullptr;
	for (Player* player : _players) {
		if (winner == nullptr || player->getScore() > winner->getScore()) {
			winner = player;
		}
	}
	return winner;
}

// Getters
Deck* Game::getDeck()
{
	return _deck;
}

int Game::getTurn()
{
	return _turn;
}

int Game::getRound()
{
	return _round;
}

Player* Game::getCurrentPlayer()
{
	return _currentPlayer;
}

std::vector<Player*>& Game::getPlayers()
{
	return _players;
}



// Application Entry Point
int main()
{
	Game* game = new Game(); // Create game instance
	game->startGame(); // Run game
	delete game; // Free memory once game is finished
	return 0;
}

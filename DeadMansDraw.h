// DeadMansDraw.h : Include file for standard system include files,
// or project specific include files.
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>

class Deck;

class DiscardPile;

class Player;

class Game {
private:
	// Variables
	Deck* _deck;
	int _turn;
	int _round;
	Player* _currentPlayer;
	std::vector<Player*> _players;
	DiscardPile* _discardPile;

public:
	// Constructor and destructor
	Game();
	~Game();

	// Game functions
	void startGame();
	void switchPlayer();
	bool playTurn();
	void endGame();
	Player* getWinner();

	// Getters
	Deck* getDeck();
	int getTurn();
	int getRound();
	Player* getCurrentPlayer();
	std::vector<Player*>& getPlayers();
};

#endif GAME_H

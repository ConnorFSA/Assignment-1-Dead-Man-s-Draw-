#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "Bank.h"
#include "PlayArea.h"

class Player
{
private:
	// Variables
	int _score;
	Bank* _bank;
	PlayArea* _playArea;
	std::string _name;

public:
	// Constructor and destructor
	Player();
	~Player();

	// Player functions
	void play();
	void bankCards(std::vector<Card*>);
	bool hasBusted();

	// Display functions
	void printPlayArea();
	void printBank();

	// Getters
	int getScore();
	std::string& getName();
};

#endif PLAYER_H
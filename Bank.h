#ifndef BANK_H
#define BANK_H

#include <vector>

#include "GameCards/Card.h"

class Bank
{
private:
	//Variables
	std::vector<Card*> _cards;

public:
	// Constructor and destructor
	Bank();
	~Bank();

	// Bank functions
	int calculateScore(std::vector<Card*>);

	// Getters
	std::vector<Card*> getCards();
};

#endif BANK_H
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
	int calculateScore();
	void addCards(std::vector<Card*> cards);

	// Getters
	std::vector<Card*> getCards();
};

#endif BANK_H
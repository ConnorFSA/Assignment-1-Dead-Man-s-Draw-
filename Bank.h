#ifndef BANK_H
#define BANK_H

#include <vector>

class Bank
{
private:
	//Variables
	std::vector<Card*> cards;

public:
	// Constructor and destructor
	Bank();
	~Bank();

	// Bank functions
	int calculateScore();

	// Getters
	std::vector<Card*> getCards();
};

#endif BANK_H
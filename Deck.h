#ifndef DECK_H
#define DECK_H

#include <vector>

#include "GameCards/Card.h" 

class Deck
{
private:
	std::vector<Card*>& _cards;
public:
	// Constructor and destructor
	Deck();
	~Deck();

	// Deck Functions
	void shuffle();
	Card* drawCard();
	void createDeck();
	bool isEmpty();
	int remaningCards();

	// Getters
	std::vector<Card*>& getCards();
};

#endif DECK_H
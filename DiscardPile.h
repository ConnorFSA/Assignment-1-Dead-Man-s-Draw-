#ifndef DISCARD_PILE_H
#define DISCARD_PILE_H

#include <vector>

#include "Card.h"

class DiscardPile
{
private:
	// Variables
	std::vector<Card*> _discardedCards;

public:
	// Constructor and destructor
	DiscardPile();
	~DiscardPile();

	// DiscardPile functions
	void addCard(Card*);
	bool isEmpty();
	

	// Getters
	std::vector<Card*>& getCards();
};

#endif DISCARD_PILE_H
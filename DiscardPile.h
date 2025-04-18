#ifndef DISCARD_PILE_H
#define DISCARD_PILE_H

#include <vector>

#include "GameCards/Card.h"

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
	void addCards(std::vector<Card*> cards);
	bool isEmpty();
	

	// Getters
	std::vector<Card*>& getCards();
};

#endif DISCARD_PILE_H
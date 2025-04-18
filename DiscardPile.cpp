#include <vector>

#include "DiscardPile.h"

// Constructor and destructor
DiscardPile::DiscardPile() {
	_discardedCards = std::vector<Card*>();
}

DiscardPile::~DiscardPile() {
}

// DiscardPile functions
void DiscardPile::addCards(std::vector<Card*> cards)
{
	for (Card* card : cards) {
		_discardedCards.push_back(card);
	}

	for (Card* card : cards) {
		card->isDiscarded();
	}
}

bool DiscardPile::isEmpty()
{
	return false;
}

// Getters
std::vector<Card*>& DiscardPile::getCards()
{
	// TODO: insert return statement here
}

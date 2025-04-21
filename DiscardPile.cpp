#include <vector>

#include "DiscardPile.h"

// Constructor and destructor
DiscardPile::DiscardPile() {
	_discardedCards = std::vector<Card*>();
}

DiscardPile::~DiscardPile() {
	for (Card* card : _discardedCards) {
		delete card;
	}
	_discardedCards.clear();
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
	return _discardedCards;
}

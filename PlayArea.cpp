#include <vector>

#include "GameCards/Card.h"
#include "PlayArea.h"
#include "DiscardPile.h"

// Constructor and destructor
PlayArea::PlayArea(DiscardPile* discardPile) : _count(0), _cards(), _discardPile(discardPile) {

}

PlayArea::~PlayArea() {
	for (Card* card : _cards) {
		delete card;
	}
	_cards.clear();
}

// PlayArea functions
void PlayArea::addCard(Card* card) 
{
	_cards.push_back(card);
	_count++;
}

void PlayArea::discardCards()
{
	// Add cards to the discard pile
	_discardPile->addCards(_cards);
}

void PlayArea::clearCards()
{
	// Remove cards from the play area
	_cards.clear();
	_count = 0;
}

// Getters
std::vector<Card*> PlayArea::getCards()
{
	return _cards;
}

std::vector<Card*>& PlayArea::getCardsRef()
{
	return _cards;
}

DiscardPile* PlayArea::getDiscardPile()
{
	return _discardPile;
}
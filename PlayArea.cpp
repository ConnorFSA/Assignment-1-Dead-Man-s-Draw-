#include <vector>

#include "GameCards/Card.h"
#include "PlayArea.h"
#include "DiscardPile.h"

// Constructor and destructor
PlayArea::PlayArea() : _count(0), _cards(), _discardPile(new DiscardPile) {

}

PlayArea::~PlayArea() {
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
	// Call the isDiscarded function for each card
	for (Card* card : _cards) {
		card->isDiscarded();
	}

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
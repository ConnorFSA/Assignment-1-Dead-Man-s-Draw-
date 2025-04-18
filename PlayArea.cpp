#include <vector>

#include "GameCards/Card.h"
#include "PlayArea.h"

// Constructor and destructor
PlayArea::PlayArea() {
}

PlayArea::~PlayArea() {
}

// PlayArea functions
void PlayArea::addCard(Card* card) 
{
	_cards.push_back(card);
	_count++;
}

// Getters
std::vector<Card*> PlayArea::getCards()
{
    // TODO: insert return statement here
}
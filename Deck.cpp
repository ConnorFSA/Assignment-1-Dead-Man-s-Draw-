#include <random>
#include <vector>

#include "Deck.h"
#include "GameCards/CardTypes.h"
#include "DeadMansDraw.h"

// Constructor and destructor
Deck::Deck(Game& game) : _cards(), _game(game) {
}

Deck::~Deck() 
{
	for (Card* card : _cards) {
		delete card;
	}
	_cards.clear();
}

// Deck functions
void Deck::shuffle()
{
}

Card* Deck::drawCard()
{
    // Return null if empty
    if (isEmpty()) {
        return nullptr;
    }

    // Get the last element in the vector
    Card* drawnCard = _cards.back();

    // Remove the last element in the vector
    _cards.pop_back();

    return drawnCard;
}

void Deck::createDeck(Game* game)
{
    // Cannons: 2-7
    for (int value = 2; value <= 7; value++) {
        _cards.push_back(new Cannon(game, value));
    }

    // Chests: 2-7
    for (int value = 2; value <= 7; value++) {
        _cards.push_back(new Chest(game, value));
    }

    // Keys: 2-7
    for (int value = 2; value <= 7; value++) {
        _cards.push_back(new Key(game, value));
    }

    // Swords: 2-7
    for (int value = 2; value <= 7; value++) {
        _cards.push_back(new Sword(game, value));
    }

    // Hooks: 2-7
    for (int value = 2; value <= 7; value++) {
        _cards.push_back(new Hook(game, value));
    }

    // Oracles: 2-7
    for (int value = 2; value <= 7; value++) {
        _cards.push_back(new Oracle(game, value));
    }

    // Maps: 2-7
    for (int value = 2; value <= 7; value++) {
        _cards.push_back(new Map(game, value));
    }

    // Mermaids: 4-9
    for (int value = 4; value <= 9; value++) {
        _cards.push_back(new Mermaid(game, value));
    }

    // Krakens: 2-7
    for (int value = 2; value <= 7; value++) {
        _cards.push_back(new Kraken(game, value));
    }

    // Bonus task
    /*
    for (int value = 2; value <= 7; value++) {
        _cards.push_back(new Anchor(game, value));
    }
    */
}

bool Deck::isEmpty()
{
    return _cards.empty();
}

int Deck::remainingCards()
{
    return _cards.size();
}

// Getters
const std::vector<Card*>& Deck::getCards()
{
	return _cards;
}

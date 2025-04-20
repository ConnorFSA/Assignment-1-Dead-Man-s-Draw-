#include "CardTypes.h"  
#include "Card.h"  

Chest::Chest(Game* game, int value) : Card(game, value) {
	_cardType = CardType::Chest;
}

Chest::~Chest() {
}

std::string Chest::toString() const {
	return "Chest(" + std::to_string(getValue()) + ")";
}

void Chest::isPlayed() {
	std::cout << "No immediate effect. If banked with a key, draw as many cards from the discard pile as you moved into your bank" << std::endl;
}

#include "CardTypes.h"  
#include "Card.h"  

Chest::Chest(Game& game, int value) : Card(game, value) {
	_cardType = CardType::Chest;
}

Chest::~Chest() {
}

std::string Chest::toString() const {
	return "Chest(" + std::to_string(getValue()) + ")";
}


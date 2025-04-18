#include "CardTypes.h"  
#include "Card.h"  

Sword::Sword(Game& game, int value) : Card(game, value) {
	_cardType = CardType::Sword;
}

Sword::~Sword() {
}

std::string Sword::toString() const {
	return "Sword(" + std::to_string(getValue()) + ")";
}

void Sword::isPlayed() {

}

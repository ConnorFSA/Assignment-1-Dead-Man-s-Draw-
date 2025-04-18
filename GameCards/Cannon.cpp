#include "CardTypes.h"  
#include "Card.h"  

Cannon::Cannon(Game* game, int value) : Card(game, value) {
	_cardType = CardType::Cannon;
}

Cannon::~Cannon() {
}

std::string Cannon::toString() const {
	return "Cannon(" + std::to_string(getValue()) + ")";
}

void Cannon::isPlayed() {

}

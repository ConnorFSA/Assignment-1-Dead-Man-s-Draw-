#include "CardTypes.h"  
#include "Card.h"  

Kraken::Kraken(Game* game, int value) : Card(game, value) {
	_cardType = CardType::Kraken;
}

Kraken::~Kraken() {
}

std::string Kraken::toString() const {
	return "Kraken(" + std::to_string(getValue()) + ")";
}

void Kraken::isPlayed() {

}

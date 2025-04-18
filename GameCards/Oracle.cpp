#include "CardTypes.h"  
#include "Card.h"  

Oracle::Oracle(Game& game, int value) : Card(game, value) {
	_cardType = CardType::Oracle;
}

Oracle::~Oracle() {
}

std::string Oracle::toString() const {
	return "Oracle(" + std::to_string(getValue()) + ")";
}

void Oracle::isPlayed() {

}

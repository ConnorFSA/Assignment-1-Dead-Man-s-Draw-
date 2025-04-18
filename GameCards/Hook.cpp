#include "CardTypes.h"  
#include "Card.h"  

Hook::Hook(Game* game, int value) : Card(game, value) {
	_cardType = CardType::Hook;
}

Hook::~Hook() {
}

std::string Hook::toString() const {
	return "Hook(" + std::to_string(getValue()) + ")";
}

void Hook::isPlayed() {

}

#include "CardTypes.h"  
#include "Card.h"  

Key::Key(Game& game, int value) : Card(game, value) {
	_cardType = CardType::Key;
}

Key::~Key() {
}

std::string Key::toString() const {
	return "Key(" + std::to_string(getValue()) + ")";
}

void Key::isBanked() {

}

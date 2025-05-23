#include "CardTypes.h"  
#include "Card.h"  

Oracle::Oracle(Game* game, int value) : Card(game, value) {
	_cardType = CardType::Oracle;
}

Oracle::~Oracle() {
}

std::string Oracle::toString() const {
	return "Oracle(" + std::to_string(getValue()) + ")";
}

void Oracle::isPlayed() {  
	std::vector<Card*>& cards = _game->getDeck()->getCards();
	Card* nextCard = cards.back();
	std::cout << "The Oracle sees the next card is: " << nextCard->toString() << std::endl;
}

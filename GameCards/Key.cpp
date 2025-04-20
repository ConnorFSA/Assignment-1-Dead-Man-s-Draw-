#include "CardTypes.h"  
#include "Card.h"  
#include "../PlayArea.h"
#include "../Player.h"

Key::Key(Game* game, int value) : Card(game, value) {
	_cardType = CardType::Key;
}

Key::~Key() {
}

std::string Key::toString() const {
	return "Key(" + std::to_string(getValue()) + ")";
}


void Key::isPlayed() {
	std::cout << "No immediate effect. If banked with a Chest, draw as many cards from the discard pile as you moved into your bank" << std::endl;
}

void Key::isBanked() {
	Player* currentPlayer = _game->getCurrentPlayer();
	PlayArea* playArea = currentPlayer->getPlayArea();
	Bank* bank = currentPlayer->getbank();
	std::vector<Card*>& deckCards = _game->getDeck()->getCards();

	std::vector<Card*> cards = playArea->getCards();
	std::vector<Card*> drawnCards;

	int size = cards.size();

	for (Card* card : cards) {
		if (card->type() == CardType::Chest) {
			for (int i = 0; i < size; i++) {
				drawnCards.push_back(deckCards.back());
				deckCards.pop_back();
			}
			std::cout << "Chest and key activated. Added ";
			for (Card* drawnCard : drawnCards) {
				std::cout << drawnCard->toString() << " ";
			}
			std::cout << std::endl;

			bank->addCards(drawnCards);
		}
	}
}
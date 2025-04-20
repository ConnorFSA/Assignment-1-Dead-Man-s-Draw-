#include "CardTypes.h"  
#include "Card.h"
#include "../Player.h"

Kraken::Kraken(Game* game, int value) : Card(game, value) {
	_cardType = CardType::Kraken;
}

Kraken::~Kraken() {
}

std::string Kraken::toString() const {
	return "Kraken(" + std::to_string(getValue()) + ")";
}

void Kraken::isPlayed() {
    Player* currentPlayer = _game->getCurrentPlayer();
    std::vector<Card*>& cards = _game->getDeck()->getCards();
    std::vector<Card*>& discardCards = currentPlayer->getPlayArea()->getDiscardPile()->getCards();

    for (int i = 0; i < 3 && !cards.empty(); i++) {
		Card* card = cards.back();
        cards.pop_back();

        // Add to current player's play area
        currentPlayer->getPlayArea()->addCard(card);
        std::cout << "The kraken has draw a " << card->toString() << " card." << std::endl;

        // Call the isPlayed function for the chosen card is player hasnt busted
        if (currentPlayer->hasBusted()) {
            return;
        }
        card->isPlayed();
    }
}

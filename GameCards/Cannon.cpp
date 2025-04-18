#include "CardTypes.h"  
#include "Card.h" 
#include "../Player.h"

Cannon::Cannon(Game* game, int value) : Card(game, value) {
	_cardType = CardType::Cannon;
}

Cannon::~Cannon() {
}

std::string Cannon::toString() const {
	return "Cannon(" + std::to_string(getValue()) + ")";
}

void Cannon::isPlayed() {
	std::vector<Player*> players = _game->getPlayers();
	Player* currentPlayer = _game->getCurrentPlayer();
	Player* nextPlayer = nullptr;

	// Find the current player's index
	auto it = std::find(players.begin(), players.end(), currentPlayer);
	// If the current player is found in the vector and not the final entry
	if (it != players.end()) {
		// Calculate the next player's index, wrapping around if necessary
		++it;
		if (it == players.end()) {
			nextPlayer = players[0];
		}
		else {
			nextPlayer = *it;
		}
	}
	
	// Get a reference to the original vector, not a copy
	std::vector<Card*>& cards = nextPlayer->getbank()->getCardsRef();

	// Find the highest value card and its position
	Card* highestValueCard = nullptr;
	std::vector<Card*>::iterator highestCardPosition;

	for (auto it = cards.begin(); it != cards.end(); ++it) {
		Card* card = *it;
		if (highestValueCard == nullptr || card->getValue() > highestValueCard->getValue()) {
			highestValueCard = card;
			highestCardPosition = it;
		}
	}

	// Remove the card directly from the vector
	if (highestValueCard != nullptr) {
		cards.erase(highestCardPosition);
		nextPlayer->getPlayArea()->getDiscardPile()->getCards().push_back(highestValueCard);
		std::cout << nextPlayer->getName() << " has lost their " << highestValueCard->toString() << " card: " << highestValueCard->toString() << std::endl;
	}
	else {
		std::cout << nextPlayer->getName() << " has nothing in their bank to discard." << std::endl;
	}
}

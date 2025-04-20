#include <map>
#include <vector>
#include <string>

#include "CardTypes.h"  
#include "Card.h" 
#include "../Player.h"


Hook::Hook(Game* game, int value) : Card(game, value) {
	_cardType = CardType::Hook;
}

Hook::~Hook() {
}

std::string Hook::toString() const {
	return "Hook(" + std::to_string(getValue()) + ")";
}

void Hook::isPlayed() {
	Player* currentPlayer = _game->getCurrentPlayer();

	if (currentPlayer->getbank()->getCards().empty()) {
		std::cout << "The you have no cards in your bank." << std::endl;
		return;
	}
	else {

		std::vector<Card*>& cards = currentPlayer->getbank()->getCardsRef();

		// Find the highest value card and its position
		std::map<Card::CardType, Card*> highestCards;

		for (Card* card : cards) {
			if (card) {
				Card::CardType type = card->type();
				int value = card->getValue();

				// Check if this type isn't in map yet OR if this card has higher value than stored one
				if (highestCards.find(type) == highestCards.end() ||
					card->getValue() > highestCards[type]->getValue()) {
					highestCards[type] = card;
				}
			}
		}

		// Print the map values in a numbered list  
		std::cout << "Select a highest value card from any of the suits in your bank:\n";
		int index = 1;
		for (const auto& [type, card] : highestCards) {
			std::cout << "(" << index++ << ")" << card->toString() << "\n";
		}

		// Prompt the user for input  
		int choice;
		std::cout << "Which card do you pick? ";
		std::cin >> choice;

		// Add the chosen card to the current player's play area and remove from the next players bank 
		for (const auto& [type, card] : highestCards) {
			if (index == choice) {
				// Add to current player's play area
				currentPlayer->getPlayArea()->addCard(card);
				// Remove from next player's bank
				auto it = std::find(cards.begin(), cards.end(), card);
				if (it != cards.end()) {
					cards.erase(it);
				}
				break;
			}
			index++;
		}
	}
}
#include <map>

#include "CardTypes.h"  
#include "Card.h"  
#include "../Player.h"

Sword::Sword(Game* game, int value) : Card(game, value) {
	_cardType = CardType::Sword;
}

Sword::~Sword() {
}

std::string Sword::toString() const {
	return "Sword(" + std::to_string(getValue()) + ")";
}

void Sword::isPlayed() {
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

	if (nextPlayer->getbank()->getCards().empty()) {
		std::cout << "The next player has no cards in their bank." << std::endl;
		return;
	}
	else {

		std::vector<Card*>& cards = nextPlayer->getbank()->getCardsRef();

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
		std::cout << "Steal the top card of any suit from the other player's bank into your play Area:\n";
		int index = 1;
		for (const auto& [type, card] : highestCards) {
			std::cout << "(" << index++ << ")" << card->toString() << "\n";
		}

		// Prompt the user for input  
		int choice;
		index = 1;
		std::cout << "Which card do you pick? ";
		std::cin >> choice;

		// Add the chosen card to the current player's play area and remove from the next players bank 
		for (const auto& [type, card] : highestCards) {
			if (index == choice) {
				// Add to current player's play area
				currentPlayer->getPlayArea()->addCard(card);

				std::cout << currentPlayer->getName() << " has picked the " << card->toString() << " card." << std::endl;
				// Play ability
				if (!currentPlayer->hasBusted()) {
					card->isPlayed();
				}
				
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

#include "CardTypes.h"  
#include "Card.h"  
#include "../PlayArea.h"
#include "../Player.h"

Map::Map(Game* game, int value) : Card(game, value) {
	_cardType = CardType::Map;
}

Map::~Map() {
}

std::string Map::toString() const {
	return "Map(" + std::to_string(getValue()) + ")";
}

void Map::isPlayed() {  
    Player* currentPlayer = _game->getCurrentPlayer();
    std::vector<Card*>& discardCards = currentPlayer->getPlayArea()->getDiscardPile()->getCards();

	if (discardCards.empty()) {
		std::cout << "The discard pile is empty map cant draw any cards." << std::endl;
		return;
	}

    // Remove the last 3 cards from the discard pile and store them in a temporary vector  
    std::vector<Card*> tempCards;
    for (int i = 0; i < 3 && !discardCards.empty(); ++i) {
        tempCards.push_back(discardCards.back());
        discardCards.pop_back();
    }

    // Display the cards for the user
    std::cout << "Cards available:" << std::endl;
    for (int i = 0; i < tempCards.size(); i++) {
        std::cout << "(" << (i + 1) << ") " << tempCards[i]->toString() << std::endl;
    }

    // Prompt the user for input 
    int choice;
    std::cout << "Which card do you pick? (1-" << tempCards.size() << "): ";
    std::cin >> choice;

    // Validate input
    if (choice < 1 || choice > tempCards.size()) {
        std::cout << "Invalid choice. Discarding all cards." << std::endl;
        // Add all cards to discard pile
        for (Card* card : tempCards) {
            discardCards.push_back(card);
        }
        return;
    }

    // Add the chosen card to the current player's play area and the rest to discard
    for (int i = 0; i < tempCards.size(); i++) {
        if (i == choice - 1) {
            // Add to current player's play area
            currentPlayer->getPlayArea()->addCard(tempCards[i]);
            std::cout << currentPlayer->getName() << " has picked the " << tempCards[i]->toString() << " card." << std::endl;
			
            // Call the isPlayed function for the chosen card is player hasnt busted
            if (!currentPlayer->hasBusted()) {
                tempCards[i]->isPlayed();
            }
			
        }
        else {
            // Add to discard pile
            discardCards.push_back(tempCards[i]);
        }
    }
}

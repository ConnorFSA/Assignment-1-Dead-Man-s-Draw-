#include <map>
#include <vector>
#include <string>

#include "Bank.h"
#include "GameCards/Card.h"

// Constructor and destructor
Bank::Bank() : _cards(){
}

Bank::~Bank() {
    for (Card* card : _cards) {
        delete card;
    }
    _cards.clear();
}

// Bank functions
int Bank::calculateScore()
{
    std::map<Card::CardType, int> highestValues;  

    for (const Card* card : _cards) {  
        if (card) {  
            Card::CardType type = card->type();  
            int value = card->getValue();  

			// Check if the type is already in the map and update the value if it's higher
            if (highestValues.find(type) == highestValues.end() || highestValues[type] < value) {  
                highestValues[type] = value;  
            }  
        }  
    }  

	// Calculate the total score by summing the highest values for each type
    int totalScore = 0;  
    for (const auto& [type, value] : highestValues) {  
        totalScore += value;  
    }

    return totalScore;  
}

void Bank::addCards(std::vector<Card*> cards)
{
	for (Card* card : cards) {
		_cards.push_back(card);
	}
	// Call the isBanked function for each card
	for (Card* card : cards) {
		card->isBanked();
	}
}

// Getters
std::vector<Card*> Bank::getCards()
{
	return _cards;
}

std::vector<Card*>& Bank::getCardsRef()
{
	return _cards;
}
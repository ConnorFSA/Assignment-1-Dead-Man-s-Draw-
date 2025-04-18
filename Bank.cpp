#include "Bank.h"
#include "GameCards/Card.h"

// Constructor and destructor
Bank::Bank() : _cards(){
}

Bank::~Bank() {
}

// Bank functions
int Bank::calculateScore()
{
   int totalScore = 0;
   for (const Card* card : _cards) {
       if (card) {
           totalScore += card->getValue();
       }
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

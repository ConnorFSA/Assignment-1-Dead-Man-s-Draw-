#include <vector>
#include <map>
#include <string>
#include <algorithm>

#include "Player.h"
#include "GameCards/Card.h"
#include "Bank.h"
#include "PlayArea.h"
#include "DiscardPile.h"

Player::Player(DiscardPile* discardPile) : _bank(new Bank()), _playArea(new PlayArea(discardPile)), _score(0) {
_name = _names[rand() % 10];
}

Player::~Player() {  
   delete _bank;  
   delete _playArea;  
}

// Player functions
bool Player::play(Card* card) 
{
	// Check if the card is null
	if (card == nullptr) {
		std::cout << "Error: Attempted to play a null card." << std::endl;
		return true;
	}

	std::cout << this->_name << " Draws a " << card->toString() << std::endl;
	
	// Add the card to the play area
	_playArea->addCard(card);

	// Check if the player has busted
	if (this->hasBusted()) {
		std::cout << "BUST! " << this->_name << " loses all cards in teh play area." << std::endl;
        _playArea->discardCards();
		_playArea->clearCards();
        // Return true if busted
        return true;
    }
    else {
		card->isPlayed();
    }

    if (this->hasBusted()) {
		std::cout << "BUST! " << this->_name << " loses all cards in the play area." << std::endl;
		_playArea->discardCards();
		_playArea->clearCards();
		// Return true if busted
		return true;
    }
    else {
        // Return false if not busted
        return false;
    }

}

void Player::bankCards() 
{
    // Get the cards from the play area
	std::vector<Card*> cards = _playArea->getCards();

	// Add the cards to the bank
    _bank->addCards(cards);

    // Clear the cards from the play area
    _playArea->clearCards();
}

bool Player::hasBusted() 
{
   std::vector<Card*> cards = _playArea->getCards();
   std::map<Card::CardType, int> cardTypeCount;

   // Count occurrences of each card type
   for (Card* card : cards) {
       cardTypeCount[card->type()]++;
       // If any card type appears more than once, return true
       if (cardTypeCount[card->type()] > 1) {
           return true;
       }
   }

   return false; // No duplicates found
}

// Display functions
void Player::printPlayArea() 
{
  std::map<Card::CardType, std::vector<Card*>> suitMap;

  // Group cards by suit
  for (Card* card : _playArea->getCards()) {
      suitMap[card->type()].push_back(card);
  }

  // Sort cards in each suit by value (highest to lowest)
  for (auto& [suit, cards] : suitMap) {
      std::sort(cards.begin(), cards.end(), [](Card* a, Card* b) {
          return a->getValue() > b->getValue();
      });
  }

  std::cout << _name << "'s Play Area:" << std::endl;

  // Print each suit and its cards on the same line
  for (const auto& [suit, cards] : suitMap) {
	  std::cout << "    ";
      for (Card* card : cards) {
          std::cout << card->toString() << " ";
      }
      std::cout << std::endl;
  }
}

void Player::printBank() 
{
  std::map<Card::CardType, std::vector<Card*>> suitMap;

  std::cout << _name << "'s Bank:" << std::endl;

  // Group cards by suit
  for (Card* card : _bank->getCards()) {
      suitMap[card->type()].push_back(card);
  }

  // Sort cards in each suit by value (highest to lowest)
  for (auto& [suit, cards] : suitMap) {
      std::sort(cards.begin(), cards.end(), [](Card* a, Card* b) {
          return a->getValue() > b->getValue();
      });}

  // Print each suit and its cards on the same line
  for (const auto& [suit, cards] : suitMap) {
      std::cout << "    ";
      for (Card* card : cards) {
          std::cout << card->toString() << " ";
      }
      std::cout << std::endl;
  }
  std::cout << "| Score: " << _bank->calculateScore() << std::endl;
}

// Getters
int Player::getScore() 
{
    return _bank->calculateScore();
}

std::string& Player::getName() 
{
	return _name;
}

Bank* Player::getbank()
{
    return _bank;
}

PlayArea* Player::getPlayArea()
{
	return _playArea;
}

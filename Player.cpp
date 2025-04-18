#include <vector>
#include <map>
#include <string>
#include <algorithm>

#include "Player.h"
#include "GameCards/Card.h"
#include "Bank.h"
#include "PlayArea.h"

Player::Player() : _bank(new Bank()), _playArea(new PlayArea()), _score(0) {
_name = _names[rand() % 10];
}

Player::~Player() {  
   delete _bank;  
   delete _playArea;  
}

// Player functions
void Player::play(Card* card) 
{
	// Check if the card is null
	if (card == nullptr) {
		std::cout << "Error: Attempted to play a null card." << std::endl;
		return;
	}
	// Add the card to the play area
	_playArea->addCard(card);

	// Check if the player has busted
	if (this->hasBusted()) {
		std::cout << "BUST! " << this->_name << " loses all cards in teh play area." << std::endl;
        
		return;
	}
}

void Player::bankCards() 
{
   if (!hasBusted()) {
       // Get the cards from the play area
	   std::vector<Card*> cards = _playArea->getCards();

       // Pass the cards to the Bank's calculateScore method
       int score = _bank->calculateScore(cards);

       // Add the score to the player's total score
       _score += score;

       // Clear the cards from the play area
       _playArea->getCards().clear();
   }
}

bool Player::hasBusted() 
{
    return false;
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

  // Print each suit and its cards on the same line
  for (const auto& [suit, cards] : suitMap) {
      for (Card* card : cards) {
          std::cout << card->toString() << " ";
      }
      std::cout << std::endl;
  }
}

void Player::printBank() 
{
  std::map<Card::CardType, std::vector<Card*>> suitMap;

  // Group cards by suit
  for (Card* card : _bank->getCards()) {
      suitMap[card->type()].push_back(card);
  }

  // Sort cards in each suit by value (highest to lowest)
  for (auto& [suit, cards] : suitMap) {
      std::sort(cards.begin(), cards.end(), [](Card* a, Card* b) {
          return a->getValue() > b->getValue();
      });
  }

  // Print each suit and its cards on the same line
  for (const auto& [suit, cards] : suitMap) {
      for (Card* card : cards) {
          std::cout << card->toString() << " ";
      }
      std::cout << std::endl;
  }
}

// Getters
int Player::getScore() 
{
    return 0;
}

std::string& Player::getName() 
{
	return _name;
}

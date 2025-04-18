#include <string>

#include "Card.h"

// Constructor and destructor
Card::Card(Game* game, int value) : _game(game), _value(value){

}

Card::~Card()
{
}

// Pure abstract functions
std::string Card::toString() const
{
	return std::string();
}

// Card Abstract functions
void Card::isPlayed()
{
}

void Card::isDiscarded()
{
}

void Card::isBanked()
{
}

std::string Card::printAbility()
{
	return "temp";
}

const Card::CardType& Card::type() const
{
	return _cardType;
}

// Getters
const int Card::getValue() const
{
	return _value;
}

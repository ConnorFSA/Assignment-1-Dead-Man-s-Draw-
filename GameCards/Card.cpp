#include <string>

#include "Card.h"

// Constructor and destructor
Card::Card(Game& game, int value) : _game(game), int _value(value){

}

Card::~Card()
{
}

// Pure abstract functions
str::string Card::toString() const
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

const CardType& Card::type() const
{
	return _type;
}

// Getters
const int Card::getValue() const
{
	return _value;
}

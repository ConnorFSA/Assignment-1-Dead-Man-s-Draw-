#include <string>

#include "Card.h"

// Constructor and destructor
Card::Card()
{
}

Card::~Card()
{
}

// Pure abstract functions
str::string Card::toString()
{
	return str::string();
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

// Getters
int Card::getValue()
{
	return 0;
}

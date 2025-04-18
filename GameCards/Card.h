#ifndef CARD_H
#define CARD_H

#include <string>

#include "../DeadMansDraw.h"

class Card {
public:
	// Card type enum
	enum class CardType { // Fixed by adding 'class' to make it a scoped enum
		Cannon,
		Chest,
		Key,
		Sword,
		Hook,
		Oracle,
		Map,
		Mermaid,
		Kraken,
		Anchor
	};

protected:
	// Variables
	CardType _cardType;
	const int _value;
	const Game* _game;

public:
	// Constructor and destructor
	Card(Game* game, int value);
	virtual ~Card();

	// Pure abstract functions
	virtual std::string toString() const = 0;

	// Card abstract functions
	virtual void isPlayed();
	virtual void isDiscarded();
	virtual void isBanked();

	// Card functions
	const CardType& type() const;

	// Getters
	const int getValue() const;
};

#endif // CARD_H
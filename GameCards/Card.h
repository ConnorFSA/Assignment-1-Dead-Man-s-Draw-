#ifndef CARD_H
#define CARD_H

#include <string>

#include "../DeadMansDraw.h"

class Card {
protected:
	// Card type enum
	enum CardType {
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

	// Variables
	CardType _cardType;
	const int _value;
	const Game& _game;

public:
	// Constructor and destuctor
	Card (Game& game, int value);
	virtual ~Card ();

	// Pure abstract functions
	virtual std::string toString() const = 0;

	// Card abstract functions
	virtual void isPlayed();
	virtual void isDiscarded();
	virtual void isBanked();

	// Card functions
	const CardType& type() const;

	// getters
	const int getValue() const;
};

#endif // CARD_H
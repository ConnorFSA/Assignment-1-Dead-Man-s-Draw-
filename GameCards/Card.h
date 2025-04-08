#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
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

private:
	// Variables
	CardType _cardType;
	int value;

public:
	// Constructor and destuctor
	Card ();
	virtual ~Card ();

	// Pure abstract functions
	virtual std::string toString() = 0;

	// Card abstract functions
	virtual void isPlayed();
	virtual void isDiscarded();
	virtual void isBanked();

	// getters
	int getValue();
};

#endif CARD_H
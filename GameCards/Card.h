#ifndef CARD_H
#define CARD_H

#include <string>

#include "../DeadMansDraw.h"

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
	const Game& _game;

public:
	// Constructor and destuctor
	Card (Game& game);
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
	int getValue() const;
};

#endif CARD_H
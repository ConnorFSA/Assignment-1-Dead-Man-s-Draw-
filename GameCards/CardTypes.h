#ifndef CARD_TYPES_H
#define CARD_TYPES_H

#include "Card.h"
#include "../PlayArea.h"
#include "../Bank.h"
#include "../Deck.h"
#include "../DiscardPile.h"

class Cannon : public Card {
private:

public:
	std::string toString() const override;
	void isPlayed();
};

class Chest : public Card {
private:

public:
	std::string toString() const override;
};

class Hook : public Card {
private:

public:
	std::string toString() const override;
	void isPlayed();
};

class Key : public Card {
private:

public:
	std::string toString() const override;
	void isBanked();

};

class Kraken : public Card {
private:

public:
	std::string toString() const override;
	void isPlayed();
};

class Map : public Card {
private:

public:
	std::string toString() const override;
	void isPlayed();
};

class Mermaid : public Card {
private:

public:
	std::string toString() const override;
};

class Oracle : public Card {
private:

public:
	std::string toString() const override;
	void isPlayed();
};

class Sword : public Card {
private:

public:
	std::string toString() const override;
	void isPlayed();
};

// Bonus task
/*
class Anchor : public Card {
private:

public:
	std::string toString() const override;
	void isPlayed();
};
*/

#endif CARD_TYPES_H
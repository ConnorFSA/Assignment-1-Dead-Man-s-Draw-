#ifndef CARD_TYPES_H
#define CARD_TYPES_H

#include "Card.h"
#include "../PlayArea.h"
#include "../DeadMansDraw.h"
#include "../Bank.h"
#include "../Deck.h"
#include "../DiscardPile.h"

class Cannon : public Card {
private:

public:
	Cannon(Game& game, int value);
	~Cannon();
	std::string toString() const override;
	void isPlayed();
};

class Chest : public Card {
private:

public:
	Chest(Game& game, int value);
	~Chest();
	std::string toString() const override;
};

class Hook : public Card {
private:

public:
	Hook(Game& game, int value);
	~Hook();
	std::string toString() const override;
	void isPlayed();
};

class Key : public Card {
private:

public:
	Key(Game& game, int value);
	~Key();
	std::string toString() const override;
	void isBanked();

};

class Kraken : public Card {
private:

public:
	Kraken(Game& game, int value);
	~Kraken();
	std::string toString() const override;
	void isPlayed();
};

class Map : public Card {
private:

public:
	Map(Game& game, int value);
	~Map();
	std::string toString() const override;
	void isPlayed();
};

class Mermaid : public Card {
private:

public:
	Mermaid(Game& game, int value);
	~Mermaid();
	std::string toString() const override;
};

class Oracle : public Card {
private:

public:
	Oracle(Game& game, int value);
	~Oracle();
	std::string toString() const override;
	void isPlayed();
};

class Sword : public Card {
private:

public:
	Sword(Game& game, int value);
	~Sword();
	std::string toString() const override;
	void isPlayed();
};

// Bonus task
/*
class Anchor : public Card {
private:

public:
	Anchor(Game& game, int value);
	std::string toString() const override;
	void isPlayed();
};
*/

#endif CARD_TYPES_H
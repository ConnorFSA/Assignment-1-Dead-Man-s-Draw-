#ifndef PLAY_AREA_H
#define PLAY_AREA_H

#include <vector>

class DiscardPile;

class PlayArea
{
private:
	// Variables
	std::vector<Card*> _cards;
	int _count;
	DiscardPile* _discardPile;

public:
	// Constructor and destructor
	PlayArea();
	~PlayArea();

	// PlayArea functions
	void addCard(Card*);
	void discardCards();
	void clearCards();

	// Getters
	std::vector<Card*> getCards();
};

#endif PLAY_AREA_H
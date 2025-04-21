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
	PlayArea(DiscardPile* discardPile);
	~PlayArea();

	// PlayArea functions
	void addCard(Card*);
	void discardCards();
	void clearCards();

	// Getters
	std::vector<Card*> getCards();
	std::vector<Card*>& getCardsRef();
	DiscardPile* getDiscardPile();
};

#endif PLAY_AREA_H
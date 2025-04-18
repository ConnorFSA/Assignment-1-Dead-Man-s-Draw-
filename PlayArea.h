#ifndef PLAY_AREA_H
#define PLAY_AREA_H

#include <vector>

class PlayArea
{
private:
	// Variables
	std::vector<Card*> _cards;
	int _count;

public:
	// Constructor and destructor
	PlayArea();
	~PlayArea();

	// PlayArea functions
	void addCard(Card*);

	// Getters
	std::vector<Card*> getCards();
};

#endif PLAY_AREA_H
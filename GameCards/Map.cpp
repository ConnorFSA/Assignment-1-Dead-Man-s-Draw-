#include "CardTypes.h"  
#include "Card.h"  

Map::Map(Game* game, int value) : Card(game, value) {
	_cardType = CardType::Map;
}

Map::~Map() {
}

std::string Map::toString() const {
	return "Map(" + std::to_string(getValue()) + ")";
}

void Map::isPlayed() {

}

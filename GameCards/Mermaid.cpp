#include "CardTypes.h"  
#include "Card.h"  

Mermaid::Mermaid(Game* game, int value) : Card(game, value) {
	_cardType = CardType::Mermaid;
}  

Mermaid::~Mermaid() {  
}  

std::string Mermaid::toString() const {  
return "Mermaid(" + std::to_string(getValue()) + ")";  
}

void Mermaid::isPlayed() {
	std::cout << "No effect but Mermaids are worth more" << std::endl;
}

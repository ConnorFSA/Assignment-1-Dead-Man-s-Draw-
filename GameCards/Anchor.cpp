#include "CardTypes.h"
#include "../Player.h"

Anchor::Anchor(Game* game, int value) : Card(game, value)
{
	_cardType = CardType::Anchor;
}

Anchor::~Anchor()
{
}

std::string Anchor::toString() const
{
	return "Anchor(" + std::to_string(getValue()) + ")";
}

void Anchor::isPlayed()
{
	std::cout << "Has no immediate effect but will potect all cards below it if you bust." << std::endl;
}

void Anchor::isDiscarded() {
    Player* currentPlayer = _game->getCurrentPlayer();
    PlayArea* playArea = currentPlayer->getPlayArea();
    std::vector<Card*>& playAreaCards = playArea->getCardsRef();
    std::vector<Card*>& discardCards = playArea->getDiscardPile()->getCards();

    // If the anchor was the card that caused the bust, skip its effect
    if (!playAreaCards.empty() && playAreaCards.back() == this) {
        return;
    }

    // Find the anchor in the play area 
    auto anchorIt = std::find(playAreaCards.begin(), playAreaCards.end(), this);
    if (anchorIt == playAreaCards.end()) {
        return; // Anchor not in play area — shouldnt happen
    }

    // Collect all cards drawn this turn before the anchor
    std::vector<Card*> cardsToRescue(playAreaCards.begin(), anchorIt);

    if (!cardsToRescue.empty()) {
        std::cout << "Anchor ability activated: " << cardsToRescue.size() << " cards drawn before Anchor are safe!" << std::endl;

        // Add the rescued cards to the player's bank
        currentPlayer->getbank()->addCards(cardsToRescue);

        for (Card* card : cardsToRescue) {
            std::cout << "Anchor saved " << card->toString() << std::endl;

            // Remove the card from the discard pile
            auto discardIt = std::find(discardCards.begin(), discardCards.end(), card);
            if (discardIt != discardCards.end()) {
                discardCards.erase(discardIt);
            }
        }
    }
}
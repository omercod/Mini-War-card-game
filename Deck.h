#pragma once
#include <iostream>
#include <Windows.h>
#include "Card.h"
#include "Clubs.h"
#include "Hearts.h"
class Deck {
private:
	int numOfCards;
	Card** cards;
public:
	Deck() :numOfCards(0), cards(NULL) {}
	~Deck();
	Deck& operator += (Card* nCard);
	Card* operator [](int index) { return cards[index]; }
	void ClearMainDeck() { numOfCards = 0, cards = NULL; }
	Deck& operator -= (Card*);
	Card** GetdeckCards() { return cards; }
	int GetNumCdeck() { return numOfCards; }
};
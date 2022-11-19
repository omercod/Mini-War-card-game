#pragma once
#include <iostream>
#include <Windows.h>
#include "Card.h"
class Player {
private:
	string name;
	int numOfCards = 0;
	int pDeckNum = 0;
	Card** pDeckCards;
	Card** cards;
public:
	Player() : name("Unknown"), numOfCards(0), pDeckNum(0), pDeckCards(NULL), cards(NULL) {}
	~Player();
	string getName() { return name; }
	void setName(string n);
	void SetNoC(int num) { numOfCards = num; }
	int GetNofC() { return numOfCards; }
	Card** getPdeckCards() { return pDeckCards; }
	Card** getCards() { return cards; }
	int getPdeckNum() { return pDeckNum; }
	Card* operator [](int index) { return cards[index]; }
	void winCards (Card** , int);
	Player& operator -= (Card*);
	void Print() {
		for (int i = 0; i < numOfCards; i++)
		{
			cards[i]->Print();
		}
	}
	void newGame() { numOfCards = 0, pDeckNum = 0, cards = NULL; }
	void gainCards(Card**, int);
	void gainWarCard(Card*);
	void clearPdeck() { pDeckNum = 0, pDeckCards = NULL; }
	void pWarCard();
};

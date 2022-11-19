#pragma once
#include <iostream>
#include <Windows.h>
#include "Player.h"
#include "Hearts.h"
#include "Clubs.h"
#include "Diamonds.h"
#include "Spades.h"
#include "Deck.h"
using namespace std;
class WarGame {
private:
	Player p1;
	Player p2;
	Card** cardsP1;
	Card** cardsP2;
	Deck CardsDeck;
	int numOfCards;
public:
	WarGame(int nCards);
	~WarGame(){}
	void Shuffle();
	void Status();
	void Round();
	void War(int warNum);
	void Menu();
	void Winner(int Winner);
	void NewGame(int nCards);
	void GainCards();
};
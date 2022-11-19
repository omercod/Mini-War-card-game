#pragma once
#include <iostream>
#include <Windows.h>
#include "Deck.h"
Deck::~Deck()
{
	if (cards)
	{
		for (int i = 0; i < numOfCards; i++)
		{
			delete cards[i];
		}
		delete[] cards;
	}
}
Deck& Deck::operator += (Card* nCard)
{
	int k = 0;
	Card** temp = new Card * [++numOfCards];
	for (int i = 0; i < numOfCards - 1; i++)
		temp[k++] = cards[i];
	temp[k] = nCard;
	if(numOfCards > 2)
		delete[] cards;
	cards = temp;
	return *this;
}
Deck& Deck::operator -= (Card* lostCard)
{
	int k = 0;
	if (numOfCards == 1)
	{
		numOfCards--;
		cards = NULL;
		return *this;
	}
	Card** temp = new Card * [--numOfCards];
	for (int i = 0; i < numOfCards + 1; i++)
	{
		if (cards[i] == lostCard)
			continue;
		temp[k++] = cards[i];
	}
	if (cards)
		delete[] cards;
	cards = temp;
	return *this;
}



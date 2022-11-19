#pragma once
#include <iostream>
#include <Windows.h>
#include "Player.h"
int turn = 0;
Player::~Player()
{
	if (cards){
		for (int i = 0; i < numOfCards; i++)
			delete cards[i];
		delete[] cards;
	}
	if (pDeckCards){
		for (int i = 0; i < pDeckNum; i++)
			delete pDeckCards[i];
		delete[] pDeckCards;
	}
}
void Player::setName(string n){
	for (int i = 0; i < n.size(); i++)
	{
		if (n[i] >= 'a' && n[i] <= 'z')
			n[i] -= 32;
	}
	name = n; 
}
void Player::winCards (Card** newCards,int num){
	int k = 0;
	numOfCards += num;
	Card** temp = new Card * [numOfCards];
	for (int i = 0; i < numOfCards; i++)
		temp[k++] = newCards[i];
	if(cards)
		delete[] cards;
	cards = temp;
}
Player& Player::operator -= (Card* lostCard)
{
	int k = 0;
	if (numOfCards == 1 && pDeckNum == 0)
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
	if(cards)
		delete[] cards;
	cards = temp;
	return *this;
}
void Player::gainCards(Card** newCards, int num)
{
	int k = 0;
	pDeckNum += num;
	Card** temp = new Card * [pDeckNum];
	for (int i = 0; i < pDeckNum - num; i++)
		temp[k++] = pDeckCards[i];
	for (int i = 0; i < num; i++)
		temp[k++] = newCards[i];
	if(pDeckCards)
		delete[] pDeckCards;
	pDeckCards = temp;
}
void Player::gainWarCard(Card* newCard) {
	int k = 0;
	Card** temp = new Card * [pDeckNum ++];
	for (int i = 0; i < pDeckNum - 1; i++)
		temp[k++] = pDeckCards[i];
	temp[k] = newCard;
	if(pDeckCards)
		delete[] pDeckCards;
	pDeckCards = temp;
}
void Player::pWarCard()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	if (turn % 2 == 0) {
		SetConsoleTextAttribute(h, 3);
		cout << "   Card: ";
		SetConsoleTextAttribute(h, 15);
		cout << "Hidden card\n";
		cout << "\n   ******************" << endl;
		cout << "   *";
		cout << " ?";
		cout << "              * \n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *    ";
		cout << "|Hidden|";
		cout << "    *\n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *             ";
		cout << " ? ";
		cout << "* \n";
		cout << "   ******************\n" << endl;
	}
	else {
		SetConsoleTextAttribute(h, 6);
		cout << "   Card: ";
		SetConsoleTextAttribute(h, 15);
		cout << "Hidden card\n";
		cout << "\n   ******************" << endl;
		cout << "   *";
		cout << " ?";
		cout << "              * \n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *    ";
		cout << "|Hidden|";
		cout << "    *\n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *             ";
		cout << " ? ";
		cout << "* \n";
		cout << "   ******************\n" << endl;
	}
	turn++; 
}

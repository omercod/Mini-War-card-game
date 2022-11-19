#pragma once
#include <iostream>
#include "Card.h"
class Spades : public Card {
private:
	string suit = "Spades";
	int suitNum = 4;
public:
	Spades(int);
	void Print() const;
	int GetSuitNum() { return suitNum; }
};
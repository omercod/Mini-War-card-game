#pragma once
#include <iostream>
#include "Card.h"
class Diamonds : public Card {
private:
	string suit = "Diamonds";
	int suitNum = 3;
public:
	Diamonds(int);
	void Print() const;
	int GetSuitNum() { return suitNum; }
};
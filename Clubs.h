#pragma once
#include <iostream>
#include "Card.h"
class Clubs : public Card {
private:
	string suit = "Clubs";
	int suitNum = 2;
public:
	Clubs(int);
	void Print() const;
	int GetSuitNum() { return suitNum; }
};
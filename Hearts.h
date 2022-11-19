#pragma once
#include <iostream>
#include "Card.h"
class Hearts: public Card{
private:
	string suit = "Hearts";
	int suitNum = 1;
public:
	Hearts(int);
	void Print() const;
	int GetSuitNum() { return suitNum; }
};
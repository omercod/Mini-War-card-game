#pragma once
#include <iostream>
#include <Windows.h>
#include "WarGame.h"
int main() 
{
	int Cards = 10;
	WarGame WarGame(Cards);
	WarGame.Shuffle();
	WarGame.Menu();
	return 0;
}
#pragma once
#include <iostream>
using namespace std;
class Card {
private:
	int value;
	string name;
public:
	virtual void Print() const {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); 
		cout << "   Card: ";
		SetConsoleTextAttribute(h, 15);
		cout << name;
	}
	void SetVal(int v) { value=v; }
	void SetName(string s) { name =s; }
	int getVal() const { return value; }
};
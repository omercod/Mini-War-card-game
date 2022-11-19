#pragma once
#include <iostream>
#include <Windows.h>
#include "Hearts.h"
using namespace std; 
Hearts::Hearts(int val)
{
	switch (val)
	{
	case 10:
		SetVal(val);
		SetName("Ten");
		break;
	case 11:
		SetVal(val);
		SetName("Jack");
		break;
	case 12:
		SetVal(val);
		SetName("Queen");
		break;
	case 13:
		SetVal(val);
		SetName("King");
		break;
	case 14:
		SetVal(val);
		SetName("Ace");
		break;
	}
}
void Hearts::Print() const
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); 
	switch (getVal())
	{
	case 10:
		Card::Print(); cout << " of " << suit << endl;
		cout << "\n   ******************" << endl;
		cout << "   *";
		SetConsoleTextAttribute(h, 4);
		cout << " 10";
		SetConsoleTextAttribute(h, 15);
		cout << "             * \n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *    ";
		SetConsoleTextAttribute(h, 4);
		cout << "|Hearts|";
		SetConsoleTextAttribute(h, 15);
		cout << "    *\n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *             ";
		SetConsoleTextAttribute(h, 4);
		cout << "10 ";
		SetConsoleTextAttribute(h, 15);
		cout << "* \n";
		cout << "   ******************\n" << endl;
		break;
	case 11:
		Card::Print(); cout << " of " << suit << endl;
		cout << "\n   ******************" << endl;
		cout << "   *";
		SetConsoleTextAttribute(h, 4);
		cout << " J";
		SetConsoleTextAttribute(h, 15);
		cout << "              * \n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *    ";
		SetConsoleTextAttribute(h, 4);
		cout << "|Hearts|";
		SetConsoleTextAttribute(h, 15);
		cout << "    *\n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *             ";
		SetConsoleTextAttribute(h, 4);
		cout << " J ";
		SetConsoleTextAttribute(h, 15);
		cout << "* \n";
		cout << "   ******************\n" << endl;
		break;
	case 12:
		Card::Print(); cout << " of " << suit << endl;
		cout << "\n   ******************" << endl;
		cout << "   *";
		SetConsoleTextAttribute(h, 4);
		cout << " Q";
		SetConsoleTextAttribute(h, 15);
		cout << "              * \n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *    ";
		SetConsoleTextAttribute(h, 4);
		cout << "|Hearts|";
		SetConsoleTextAttribute(h, 15);
		cout << "    *\n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *             ";
		SetConsoleTextAttribute(h, 4);
		cout << " Q";
		SetConsoleTextAttribute(h, 15);
		cout << " * \n";
		cout << "   ******************\n" << endl;
		break;
	case 13:
		Card::Print(); cout << " of " << suit << endl;
		cout << "\n   ******************" << endl;
		cout << "   *";
		SetConsoleTextAttribute(h, 4);
		cout << " K";
		SetConsoleTextAttribute(h, 15);
		cout << "              * \n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *    ";
		SetConsoleTextAttribute(h, 4);
		cout << "|Hearts|";
		SetConsoleTextAttribute(h, 15);
		cout << "    *\n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *             ";
		SetConsoleTextAttribute(h, 4);
		cout << " K";
		SetConsoleTextAttribute(h, 15);
		cout << " *\n";
		cout << "   ******************\n" << endl;
		break;
	case 14:
		Card::Print(); cout << " of " << suit << endl;
		cout << "\n   ******************" << endl;
		cout << "   *";
		SetConsoleTextAttribute(h, 4);
		cout << " A";
		SetConsoleTextAttribute(h, 15);
		cout << "              * \n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *    ";
		SetConsoleTextAttribute(h, 4);
		cout << "|Hearts|";
		SetConsoleTextAttribute(h, 15);
		cout << "    *\n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *                *\n";
		cout << "   *             ";
		SetConsoleTextAttribute(h, 4);
		cout << " A";
		SetConsoleTextAttribute(h, 15);
		cout << " *\n";
		cout << "   ******************\n" << endl;
		break;
	}
}

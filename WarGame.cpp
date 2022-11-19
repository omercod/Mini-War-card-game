#pragma once
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread> 
#include "WarGame.h"
using namespace std;
using namespace this_thread;
using namespace chrono_literals;
using chrono::system_clock;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); 
int  P1card, P2card, nCards = 10, Gameflag, lastC = 0, deckCard, roundNum = 0;
WarGame::WarGame(int nCards):numOfCards(nCards){
	cardsP1 = new Card * [nCards];
	cardsP2 = new Card * [nCards];
}
void WarGame::Shuffle(){
	srand(time(NULL));
	int arr[4][5],arr2[4], pamNum, pamSuit, flag = 1, suitFalg = 0;
	int sf1 = 0, sf2 = 0, sf3 = 0, sf4 = 0;
	int s1 = 0, s2 = 0, s3 = 0, s4 = 0,sDex = 0; //suits
	int p1dex = 0, p2dex = 0; // players arrays
	int playerCard = 0 + rand() % 2;
	for (int i = 0; i < numOfCards * 2; i++)
	{
		while (flag == 1)
		{
			flag = 0;
			pamSuit = 1 + rand() % 4;
			pamNum = 10 + rand() % 5;
			if (s1 == numOfCards / 2 && sf1 == 0) {
				arr2[sDex++] = 1, sf1 = 1;
			}
			if (s2 == numOfCards / 2 && sf2 == 0) {
				arr2[sDex++] = 2, sf2 = 1;
			}
			if (s3 == numOfCards / 2 && sf3 == 0) {
				arr2[sDex++] = 3, sf3 = 1;
			}
			if (s4 == numOfCards / 2 && sf4 == 0) {
				arr2[sDex++] = 4, sf4 = 1;
			}
			suitFalg = 0;
			if (sDex > 0)
			{
				pamSuit = 1;
				while (suitFalg == 0) {
					suitFalg = 1;
					for (int i = 0; i < sDex; i++) {
						if (arr2[i] == pamSuit) {
							suitFalg = 0;
							pamSuit++;
							break;
						}
					}
				}
			}
			if (pamSuit == 1)
			{
				for (int i = 0; i < s1; i++) {
					if (pamNum == arr[0][i])
						flag = 1;
				}
			}
			if (pamSuit == 2) {
				for (int i = 0; i < s2; i++) {
					if (pamNum == arr[1][i])
						flag = 1;
				}
			}
			if (pamSuit == 3)
			{
				for (int i = 0; i < s3; i++) {
					if (pamNum == arr[2][i])
						flag = 1;
				}
			}
			if (pamSuit == 4)
			{
				for (int i = 0; i < s4; i++) {
					if (pamNum == arr[3][i])
						flag = 1;
				}
			}
		}
		if (playerCard % 2 == 0) {
			if (pamSuit == 1) {
				cardsP1[p1dex++] = new Hearts(pamNum);
				arr[0][s1++] = pamNum;
				flag = 1;
				playerCard++; 
			}
			if (pamSuit == 2){
				cardsP1[p1dex++] = new Clubs(pamNum);
				arr[1][s2++] = pamNum;
				flag = 1;
				playerCard++;
			}
			if (pamSuit == 3) {
				cardsP1[p1dex++] = new Diamonds(pamNum);
				arr[2][s3++] = pamNum;
				flag = 1;
				playerCard++;
			}
			if (pamSuit == 4) {
				cardsP1[p1dex++] = new Spades(pamNum);
				arr[3][s4++] = pamNum;
				flag = 1;
				playerCard++;
			}
		}
		else {
			if (pamSuit == 1) {
				cardsP2[p2dex++] = new Hearts(pamNum);
				arr[0][s1++] = pamNum;
				flag = 1;
				playerCard++;
			}
			if (pamSuit == 2) {
				cardsP2[p2dex++] = new Clubs(pamNum);
				arr[1][s2++] = pamNum;
				flag = 1;
				playerCard++;
			}
			if (pamSuit == 3) {
				cardsP2[p2dex++] = new Diamonds(pamNum);
				arr[2][s3++] = pamNum;
				flag = 1;
				playerCard++;
			}
			if (pamSuit == 4) {
				cardsP2[p2dex++] = new Spades(pamNum);
				arr[3][s4++] = pamNum;
				flag = 1;
				playerCard++;
			}
		}
	}
	p1.winCards(cardsP1, numOfCards);
	p2.winCards(cardsP2, numOfCards);
}
void WarGame::Status() {
	cout << "   || STATUS ||"; SetConsoleTextAttribute(h, 4);
	cout << " #" << roundNum << endl; SetConsoleTextAttribute(h, 3);
	cout << "   * " << p1.getName(); SetConsoleTextAttribute(h, 15); 
	cout << "  Cards on hand : "; SetConsoleTextAttribute(h, 4);
	cout << p1.GetNofC() + p1.getPdeckNum() << endl; SetConsoleTextAttribute(h, 6);
	cout << "   * " << p2.getName(); SetConsoleTextAttribute(h, 15);
	cout << "  Cards on hand : "; SetConsoleTextAttribute(h, 4);
	cout << p2.GetNofC() + p2.getPdeckNum() << endl; SetConsoleTextAttribute(h, 15);
	cout << "   ||  MENU  ||" << endl; SetConsoleTextAttribute(h, 4);
	cout << "   # Enter 1";
	SetConsoleTextAttribute(h, 15);
	cout << "  for WAR!" << endl;
	SetConsoleTextAttribute(h, 5);
	cout << "   # Enter 9";
	SetConsoleTextAttribute(h, 15);
	cout << "  for EXIT " << endl;
	SetConsoleTextAttribute(h, 15);
}
void WarGame::Round() {
	srand(time(NULL));
	int  P1card, P2card, WarNum;
	deckCard = 1, roundNum++;
	if ((p1.GetNofC() == 0 && p1.getPdeckNum() > 0) || (p2.GetNofC() == 0 && p2.getPdeckNum() > 0))
		GainCards();
	if (p1.GetNofC() == 1 && p1.getPdeckNum() == 0 || p2.GetNofC() == 1 && p2.getPdeckNum() == 0) {
		if (p1.GetNofC() == 1 && p1.getPdeckNum() == 0) {
			P1card = 0;
			P2card = rand() % p2.GetNofC();
			SetConsoleTextAttribute(h, 4);
			cout << "\n***** " << p1.getName() <<" LAST card! *****\n\n";
			sleep_until(system_clock::now() + 2s);
			SetConsoleTextAttribute(h, 15);
			cout << "********* Are you ready? *********\n";
			sleep_until(system_clock::now() + 0.7s);
			cout << "             *** 3 ***\n";
			sleep_until(system_clock::now() + 0.7s);
			cout << "              ** 2 **\n";
			sleep_until(system_clock::now() + 0.7s);
			cout << "               * 1 *\n";
			sleep_until(system_clock::now() + 0.7s);
			SetConsoleTextAttribute(h, 4);
			sleep_until(system_clock::now() + 0.2s);
			cout << "************ LAST WAR? ***********\n\n";
			sleep_until(system_clock::now() + 1s);
			SetConsoleTextAttribute(h, 3);
			cout << "   *****| "; cout << p1.getName() << " | *****" << endl;
			p1[P1card]->Print();
			SetConsoleTextAttribute(h, 6);
			cout << "   *****| "; cout << p2.getName() << " | *****" << endl;
			p2[P2card]->Print();
			CardsDeck += (p1[P1card]); CardsDeck += (p2[P2card]);
			p1 -= (p1[P1card]); p2 -= (p2[P2card]);
			WarNum = CardsDeck.GetdeckCards()[0]->getVal() - CardsDeck.GetdeckCards()[1]->getVal();
			sleep_until(system_clock::now() + 2.5s);
			if (WarNum > 0)
				War(1);
			if (WarNum < 0)
				War(2);
			if (WarNum == 0){
				p1.gainWarCard(CardsDeck[0]);
				CardsDeck -= CardsDeck[0];
				lastC = 1;
				War(3);
			}
			return;  
		}
		else {
			P2card = 0;
			P1card = rand() % p1.GetNofC();
			SetConsoleTextAttribute(h, 4);
			cout << "\n***** " << p2.getName() << " LAST card! *****\n\n";
			sleep_until(system_clock::now() + 2s);
			SetConsoleTextAttribute(h, 15);
			cout << "********* Are you ready? *********\n";
			sleep_until(system_clock::now() + 0.7s);
			cout << "             *** 3 ***\n";
			sleep_until(system_clock::now() + 0.7s);
			cout << "              ** 2 **\n";
			sleep_until(system_clock::now() + 0.7s);
			cout << "               * 1 *\n";
			sleep_until(system_clock::now() + 0.7s);
			SetConsoleTextAttribute(h, 4);
			sleep_until(system_clock::now() + 0.2s);
			cout << "************ LAST WAR? ***********\n\n";
			sleep_until(system_clock::now() + 1s);
			SetConsoleTextAttribute(h, 3);
			cout << "   *****| "; cout << p1.getName() << " | *****" << endl;
			p1[P1card]->Print();
			SetConsoleTextAttribute(h, 6);
			cout << "   *****| "; cout << p2.getName() << " | *****" << endl;
			p2[P2card]->Print();
			CardsDeck += (p1[P1card]); CardsDeck += (p2[P2card]);
			p1 -= (p1[P1card]); p2 -= (p2[P2card]);
			WarNum = CardsDeck.GetdeckCards()[0]->getVal() - CardsDeck.GetdeckCards()[1]->getVal();
			if (WarNum > 0)
				War(1);
			if (WarNum < 0)
				War(2);
			if (WarNum == 0) {
				p2.gainWarCard(CardsDeck[1]);
				CardsDeck -= CardsDeck[1];
				lastC = 1;
				War(3);
			}
			return;
		}
	}
	sleep_until(system_clock::now() + 0.7s); 
	cout << "       *** 3 ***\n";
	sleep_until(system_clock::now() + 0.7s);
	cout << "        ** 2 **\n";
	sleep_until(system_clock::now() + 0.7s);
	cout << "         * 1 *\n";
	sleep_until(system_clock::now() + 0.7s);
	SetConsoleTextAttribute(h, 4);
	sleep_until(system_clock::now() + 0.2s);
	cout << "********* WAR! ********\n\n";
	sleep_until(system_clock::now() + 1s);
	SetConsoleTextAttribute(h, 15);
	P1card = rand() % p1.GetNofC();
	P2card = rand() % p2.GetNofC();
	SetConsoleTextAttribute(h, 3);
	sleep_until(system_clock::now() + 0.3s);
	cout << "   *****| "; cout << p1.getName() << " | *****" << endl;
	p1[P1card]->Print();
	SetConsoleTextAttribute(h, 6);
	cout << "   *****| "; cout << p2.getName() << " | *****" << endl;
	p2[P2card]->Print();
	sleep_until(system_clock::now() + 3s);
	CardsDeck += (p1[P1card]); CardsDeck += (p2[P2card]);
	p1 -= (p1[P1card]); p2 -= (p2[P2card]); 
	WarNum = CardsDeck.GetdeckCards()[0]->getVal() - CardsDeck.GetdeckCards()[1]->getVal();
	if (WarNum > 0)
		War(1);
	if (WarNum < 0)
		War(2);
	if (WarNum == 0)
		War(3);
}
void WarGame::War(int warNum) {
	int WarNum;
	switch (warNum){
	case 1:
		p1.gainCards(CardsDeck.GetdeckCards(), CardsDeck.GetNumCdeck());
		CardsDeck.ClearMainDeck();
		SetConsoleTextAttribute(h, 10);
		cout << "*** "; SetConsoleTextAttribute(h, 3); cout << p1.getName();
		SetConsoleTextAttribute(h, 10); cout <<" WINS this round! ***\n\n";
		sleep_until(system_clock::now() + 3s);
		SetConsoleTextAttribute(h, 15);
		break;
	case 2:
		p2.gainCards(CardsDeck.GetdeckCards(), CardsDeck.GetNumCdeck());
		CardsDeck.ClearMainDeck(); 
		SetConsoleTextAttribute(h, 10);
		cout << "*** "; SetConsoleTextAttribute(h, 6); cout << p2.getName();
		SetConsoleTextAttribute(h, 10); cout << " WINS this round! ***\n\n";
		sleep_until(system_clock::now() + 3s);
		SetConsoleTextAttribute(h, 15);
		break;
	case 3:
		SetConsoleTextAttribute(h, 4);
		cout << "****** WOW we have a WAR! ******\n\n"; SetConsoleTextAttribute(h, 15);
		sleep_until(system_clock::now() + 2s);
		if ((p1.GetNofC() == 0 && p1.getPdeckNum() > 0) || (p2.GetNofC() == 0 && p2.getPdeckNum() > 0))
			GainCards();
		if (p1.GetNofC() == 1 && p1.getPdeckNum() == 0 || p2.GetNofC() == 1 && p2.getPdeckNum() == 0) {
			if (p1.GetNofC() == 1 && p1.getPdeckNum() == 0) {
				deckCard += 2; 
				P1card = 0;
				P2card = rand() % p2.GetNofC();
				SetConsoleTextAttribute(h, 4);
				cout << "\n***** " << p1.getName() << " LAST card! *****\n\n";
				sleep_until(system_clock::now() + 2s);
				SetConsoleTextAttribute(h, 15);
				cout << "********* Are you ready? *********\n";
				sleep_until(system_clock::now() + 0.7s);
				cout << "             *** 3 ***\n";
				sleep_until(system_clock::now() + 0.7s);
				cout << "              ** 2 **\n";
				sleep_until(system_clock::now() + 0.7s);
				cout << "               * 1 *\n";
				sleep_until(system_clock::now() + 0.7s);
				SetConsoleTextAttribute(h, 4);
				sleep_until(system_clock::now() + 0.2s);
				cout << "************ LAST WAR? ***********\n\n";
				sleep_until(system_clock::now() + 1s);
				SetConsoleTextAttribute(h, 3);
				cout << "   *****| "; cout << p1.getName() << " | *****" << endl;
				p1[P1card]->Print();
				SetConsoleTextAttribute(h, 6);
				cout << "   *****| "; cout << p2.getName() << " | *****" << endl;
				p2[P2card]->Print();
				CardsDeck += (p1[P1card]); CardsDeck += (p2[P2card]);
				p1 -= (p1[P1card]); p2 -= (p2[P2card]);
				WarNum = CardsDeck.GetdeckCards()[deckCard - 1]->getVal() - CardsDeck.GetdeckCards()[deckCard + lastC]->getVal();
				sleep_until(system_clock::now() + 2.5s);
				if (WarNum > 0)
					War(1);
				if (WarNum < 0)
					War(2);
				if (WarNum == 0) {
					lastC = 0;
					p1.gainWarCard(CardsDeck[deckCard - 1]);
					CardsDeck -= CardsDeck[deckCard];
					deckCard--;
					War(3);
				}
				return;
			}
			else {
				deckCard += 2;
				P2card = 0;
				P1card = rand() % p1.GetNofC();
				SetConsoleTextAttribute(h, 4);
				cout << "\n***** " << p2.getName() << " LAST card! *****\n\n";
				sleep_until(system_clock::now() + 2s);
				SetConsoleTextAttribute(h, 15);
				cout << "********* Are you ready? *********\n";
				sleep_until(system_clock::now() + 0.7s);
				cout << "             *** 3 ***\n";
				sleep_until(system_clock::now() + 0.7s);
				cout << "              ** 2 **\n";
				sleep_until(system_clock::now() + 0.7s);
				cout << "               * 1 *\n";
				sleep_until(system_clock::now() + 0.7s);
				SetConsoleTextAttribute(h, 4);
				sleep_until(system_clock::now() + 0.2s);
				cout << "************ LAST WAR? ***********\n\n";
				sleep_until(system_clock::now() + 1s);
				SetConsoleTextAttribute(h, 3);
				cout << "   *****| "; cout << p1.getName() << " | *****" << endl;
				p1[P1card]->Print();
				SetConsoleTextAttribute(h, 6);
				cout << "   *****| "; cout << p2.getName() << " | *****" << endl;
				p2[P2card]->Print();
				CardsDeck += (p1[P1card]); CardsDeck += (p2[P2card]);
				p1 -= (p1[P1card]); p2 -= (p2[P2card]);
				WarNum = CardsDeck.GetdeckCards()[deckCard - 1 - lastC]->getVal() - CardsDeck.GetdeckCards()[deckCard - lastC]->getVal();
				sleep_until(system_clock::now() + 2.5s);
				if (WarNum > 0)
					War(1);
				if (WarNum < 0)
					War(2);
				if (WarNum == 0) {
					lastC = 0;
					p2.gainWarCard(CardsDeck[deckCard]);
					CardsDeck -= CardsDeck[deckCard];
					deckCard--;
					War(3);
				}
				return;
			}
		}
		deckCard += 2;
		P1card = rand() % p1.GetNofC();
		P2card = rand() % p2.GetNofC();
		CardsDeck += (p1[P1card]); CardsDeck += (p2[P2card]);  
		p1 -= (p1[P1card]); p2 -= (p2[P2card]);   
		SetConsoleTextAttribute(h, 14);
		cout << "** Each player turns one card face DOWN **\n\n";
		sleep_until(system_clock::now() + 3s);
		SetConsoleTextAttribute(h, 3);
		cout << "   *****| "; cout << p1.getName() << " | *****" << endl;
		p1.pWarCard();
		SetConsoleTextAttribute(h, 6);
		cout << "   *****| "; cout << p2.getName() << " | *****" << endl;
		p2.pWarCard();
		sleep_until(system_clock::now() + 4s);
		if ((p1.GetNofC() == 0 && p1.getPdeckNum() > 0) || (p2.GetNofC() == 0 && p2.getPdeckNum() > 0))
			GainCards();
		if (p1.GetNofC() == 1 && p1.getPdeckNum() == 0 || p2.GetNofC() == 1 && p2.getPdeckNum() == 0) {
			if (p1.GetNofC() == 1 && p1.getPdeckNum() == 0) {
				deckCard += 2; 
				P1card = 0;
				P2card = rand() % p2.GetNofC();
				SetConsoleTextAttribute(h, 4);
				cout << "\n***** " << p1.getName() << " LAST card! *****\n\n";
				sleep_until(system_clock::now() + 2s);
				SetConsoleTextAttribute(h, 15);
				cout << "********* Are you ready? *********\n";
				sleep_until(system_clock::now() + 0.7s);
				cout << "             *** 3 ***\n";
				sleep_until(system_clock::now() + 0.7s);
				cout << "              ** 2 **\n";
				sleep_until(system_clock::now() + 0.7s);
				cout << "               * 1 *\n";
				sleep_until(system_clock::now() + 0.7s);
				SetConsoleTextAttribute(h, 4);
				sleep_until(system_clock::now() + 0.2s);
				cout << "************ LAST WAR? ***********\n\n";
				sleep_until(system_clock::now() + 1s);
				SetConsoleTextAttribute(h, 3);
				cout << "   *****| "; cout << p1.getName() << " | *****" << endl;
				p1[P1card]->Print();
				SetConsoleTextAttribute(h, 6);
				cout << "   *****| "; cout << p2.getName() << " | *****" << endl;
				p2[P2card]->Print();
				CardsDeck += (p1[P1card]); CardsDeck += (p2[P2card]);
				p1 -= (p1[P1card]); p2 -= (p2[P2card]);
				WarNum = CardsDeck.GetdeckCards()[deckCard - 1]->getVal() - CardsDeck.GetdeckCards()[deckCard]->getVal();
				sleep_until(system_clock::now() + 2.5s);
				if (WarNum > 0)
					War(1);
				if (WarNum < 0)
					War(2);
				if (WarNum == 0) {
					p1.gainWarCard(CardsDeck[deckCard - 1]);
					CardsDeck -= CardsDeck[deckCard];
					deckCard--;
					War(3);
				}
				return;
			}
			else {
				deckCard += 2;
				P2card = 0;
				P1card = rand() % p1.GetNofC();
				SetConsoleTextAttribute(h, 4);
				cout << "\n***** " << p2.getName() << " LAST card! *****\n\n";
				sleep_until(system_clock::now() + 2s);
				SetConsoleTextAttribute(h, 15);
				cout << "********* Are you ready? *********\n";
				sleep_until(system_clock::now() + 0.7s);
				cout << "             *** 3 ***\n";
				sleep_until(system_clock::now() + 0.7s);
				cout << "              ** 2 **\n";
				sleep_until(system_clock::now() + 0.7s);
				cout << "               * 1 *\n";
				sleep_until(system_clock::now() + 0.7s);
				SetConsoleTextAttribute(h, 4);
				sleep_until(system_clock::now() + 0.2s);
				cout << "************ LAST WAR? ***********\n\n";
				sleep_until(system_clock::now() + 1s);
				SetConsoleTextAttribute(h, 3);
				cout << "   *****| "; cout << p1.getName() << " | *****" << endl;
				p1[P1card]->Print();
				SetConsoleTextAttribute(h, 6);
				cout << "   *****| "; cout << p2.getName() << " | *****" << endl;
				p2[P2card]->Print();
				CardsDeck += (p1[P1card]); CardsDeck += (p2[P2card]);
				p1 -= (p1[P1card]); p2 -= (p2[P2card]);
				WarNum = CardsDeck.GetdeckCards()[deckCard - 1]->getVal() - CardsDeck.GetdeckCards()[deckCard]->getVal();
				sleep_until(system_clock::now() + 2.5s);
				if (WarNum > 0)
					War(1);
				if (WarNum < 0)
					War(2);
				if (WarNum == 0) {
					p2.gainWarCard(CardsDeck[deckCard]);
					CardsDeck -= CardsDeck[deckCard];
					deckCard--;
					War(3);
				}
				return;
			}
		}
		SetConsoleTextAttribute(h, 14);
		cout << "** Each player turns one card face UP **\n\n";
		sleep_until(system_clock::now() + 4s);
		deckCard += 2;
		P1card = rand() % p1.GetNofC(); P2card = rand() % p2.GetNofC();
		SetConsoleTextAttribute(h, 3);
		cout << "   *****| "; cout << p1.getName() << " | *****" << endl;
		p1[P1card]->Print();
		SetConsoleTextAttribute(h, 6);
		cout << "   *****| "; cout << p2.getName() << " | *****" << endl;
		p2[P2card]->Print();
		CardsDeck += (p1[P1card]); CardsDeck += (p2[P2card]); 
		p1 -= (p1[P1card]); p2 -= (p2[P2card]);   
		sleep_until(system_clock::now() + 3s);
		WarNum = CardsDeck.GetdeckCards()[deckCard - 1]->getVal() - CardsDeck.GetdeckCards()[deckCard]->getVal();
		if (WarNum > 0)
			War(1);
		if (WarNum < 0)
			War(2);
		if (WarNum == 0)
			War(3);
		break;
	}
}
void WarGame::Winner(int Winner){
	int choice;
	Gameflag = 0; 
	switch (Winner)
	{
	case 1:
		SetConsoleTextAttribute(h, 14);
		cout << "****** And the WINNER of the game is: ******" << endl;
		sleep_until(system_clock::now() + 2s);
		cout << "\nDrums please....\n";
		sleep_for(10ns);
		sleep_until(system_clock::now() + 2s);
		cout << "***************** " << p1.getName() << " *****************\n\n" << endl;
		sleep_until(system_clock::now() + 3s);
		SetConsoleTextAttribute(h, 15);
		do
		{
			cout << "   || STATUS ||"; SetConsoleTextAttribute(h, 4);
			cout << " #" << roundNum << endl; SetConsoleTextAttribute(h, 3);
			cout << "   * " << p1.getName(); SetConsoleTextAttribute(h, 15);
			cout << " Cards on hand : "; SetConsoleTextAttribute(h, 4);
			cout << p1.GetNofC() + p1.getPdeckNum() << endl; SetConsoleTextAttribute(h, 6);
			cout << "   * " << p2.getName(); SetConsoleTextAttribute(h, 15);
			cout << " Cards on hand : "; SetConsoleTextAttribute(h, 4);
			cout << p2.GetNofC() + p2.getPdeckNum() << endl; SetConsoleTextAttribute(h, 15);
			cout << "   ||  MENU  ||" << endl; SetConsoleTextAttribute(h, 4);
			cout << "   # Enter 1"; SetConsoleTextAttribute(h, 15);
			cout << " for NEW GAME!" << endl; SetConsoleTextAttribute(h, 5);
			cout << "   # Enter 9"; SetConsoleTextAttribute(h, 15);
			cout << " for EXIT " << endl; SetConsoleTextAttribute(h, 15);
			cout << "   # Your choice: ";cin >> choice;
			if (cin.fail()) {
				cin.clear(); cin.ignore(512, '\n');
			}
			if (choice != 1 && choice != 9) {
				SetConsoleTextAttribute(h, 4);
				cout << "\nENTER only 1 or 9!\n" << endl;
				SetConsoleTextAttribute(h, 15);
			}
		} while (choice != 1 && choice != 9);
		if (choice == 1)
		{
			NewGame(nCards);
			Shuffle();	
			SetConsoleTextAttribute(h, 14);
			cout << "\n\n*** NEW GAME ***\n\n" << endl;
			sleep_until(system_clock::now() + 2s);
			SetConsoleTextAttribute(h, 15);
			Gameflag = 1;
			roundNum = 0;
			return;
		}
		else {
			Gameflag = 0;
			return;
		}
		break;
	case 2:
		SetConsoleTextAttribute(h, 14);
		cout << "****** And the WINNER of the game is: ******" << endl;
		sleep_for(10ns);
		sleep_until(system_clock::now() + 2s);
		cout << "\nDrums please....\n";
		sleep_for(10ns);
		sleep_until(system_clock::now() + 2s);
		cout << "***************** " << p2.getName() << " *****************\n\n" << endl;
		sleep_for(10ns);
		sleep_until(system_clock::now() + 2s);
		SetConsoleTextAttribute(h, 15);
		do
		{
			cout << "   || STATUS ||"; SetConsoleTextAttribute(h, 4);
			cout << " #" << roundNum << endl; SetConsoleTextAttribute(h, 3);
			cout << "   * " << p1.getName(); SetConsoleTextAttribute(h, 15);
			cout << " Cards on hand : "; SetConsoleTextAttribute(h, 4);
			cout << p1.GetNofC() + p1.getPdeckNum() << endl; SetConsoleTextAttribute(h, 6);
			cout << "   * " << p2.getName(); SetConsoleTextAttribute(h, 15);
			cout << " Cards on hand : "; SetConsoleTextAttribute(h, 4);
			cout << p2.GetNofC() + p2.getPdeckNum() << endl; SetConsoleTextAttribute(h, 15);
			cout << "   ||  MENU  ||" << endl; SetConsoleTextAttribute(h, 4);
			cout << "   # Enter 1"; SetConsoleTextAttribute(h, 15);
			cout << " for NEW GAME!" << endl; SetConsoleTextAttribute(h, 5);
			cout << "   # Enter 9"; SetConsoleTextAttribute(h, 15);
			cout << " for EXIT " << endl; SetConsoleTextAttribute(h, 15);
			cout << "   # Your choice: ";cin >> choice;
			if (cin.fail()) {
				cin.clear(); cin.ignore(512, '\n');
			}
			if (choice != 1 && choice != 9) {
				SetConsoleTextAttribute(h, 4);
				cout << "\nENTER only 1 or 9!\n" << endl;
				SetConsoleTextAttribute(h, 15);
			}
		} while (choice != 1 && choice != 9);
		if (choice == 1)
		{
			NewGame(nCards);
			Shuffle();
			SetConsoleTextAttribute(h, 14);
			cout << "\n\n*** NEW GAME ***\n\n" << endl;
			sleep_until(system_clock::now() + 2s);
			SetConsoleTextAttribute(h, 15);
			Gameflag = 1;
			roundNum = 0; 
			return;
		}
		else {
			Gameflag = 0;
			return;
		}
		break;
	}
}
void WarGame::NewGame(int nCards){
	Card** newP1 = new Card * [nCards];
	Card** newP2 = new Card * [nCards];
	if (p1.GetNofC() > 0)
		delete[] cardsP1;
	if (p2.GetNofC() > 0)
		delete[] cardsP2;
	CardsDeck.ClearMainDeck();
	cardsP1 = newP1;
	cardsP2 = newP2;
	p1.newGame();
	p2.newGame();
}
void WarGame::GainCards() {
	if (p1.GetNofC() == 0 && p1.getPdeckNum() > 0) {
		p1.winCards(p1.getPdeckCards(),p1.getPdeckNum());
		p1.clearPdeck();
	}
	if (p2.GetNofC() == 0 && p2.getPdeckNum() > 0) {
		p2.winCards(p2.getPdeckCards(), p2.getPdeckNum());
		p2.clearPdeck();
	}
}
void WarGame::Menu(){
	using namespace this_thread;   
	using namespace chrono_literals; 
	using chrono::system_clock;
	int choice, deckNum = 0, P1card, P2card, WarNum;
	string p1Name, p2Name; 
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(NULL)); 
	SetConsoleTextAttribute(h, 15);
	cout << "*** Welcome to"; SetConsoleTextAttribute(h, 4);
	cout << " Mini WAR"; SetConsoleTextAttribute(h, 15);
	cout << " Card Game! ***\n" << endl;
	cout << "# The cards deck include 10, J, Q, K, and Ace of all 4 suits:";
	SetConsoleTextAttribute(h, 4); cout << " Hearts, ";
	SetConsoleTextAttribute(h, 1); cout << "Clubs,";
	SetConsoleTextAttribute(h, 4); cout << " Diamonds ";
	SetConsoleTextAttribute(h, 15); cout << "and ";
	SetConsoleTextAttribute(h, 1); cout << "Spades.\n";
	SetConsoleTextAttribute(h, 15);
	cout << "# Each player get 10 cards from the deck.\n";
	cout << "# The player who got all 20 cards WIN.\n\n";
	cout << "# Enter the players names please.\n\n";
	sleep_until(system_clock::now() + 3s);
	SetConsoleTextAttribute(h, 3); cout << "# Enter Player 1 Name: ";
	SetConsoleTextAttribute(h, 15); cin >> p1Name;
	SetConsoleTextAttribute(h, 6); cout << "# Enter Player 2 Name: ";
	SetConsoleTextAttribute(h, 15); cin >> p2Name; cout << "\n";
	if (p1Name.size() != p2Name.size()) {
		if (p1Name.size() < p2Name.size()) {
			for (int i = p1Name.size(); i < p2Name.size(); i++){
				p1Name.insert(p1Name.size(), " ");
			}
		}
		else {
			for (int i = p2Name.size(); i < p1Name.size(); i++) {
				p2Name.insert(p2Name.size(), " ");
			}
		}
	}
	p1.setName(p1Name); p2.setName(p2Name);
	sleep_until(system_clock::now() + 2s);
	do
	{
		Status();
		cout << "   # Your choice: ";
		cin >> choice;
		if (cin.fail()) {
			cin.clear(); cin.ignore(512, '\n');
		}
		if (choice == 1)
		{
			Round();
			if ((p1.GetNofC() == 0 && p1.getPdeckNum() == 0) || (p2.GetNofC() == 0 && p2.getPdeckNum() == 0)) {
				if (p2.GetNofC() == 0 && p2.getPdeckNum() == 0) {
					Winner(1);
					if (Gameflag == 0)
						break;
				}
				else {
					Winner(2);
					if (Gameflag == 0)
						break;
				}
			}
		}
		if (choice != 1 && choice != 9) {
			SetConsoleTextAttribute(h, 4);
			cout << "\nENTER only 1 or 9!\n" << endl;
			SetConsoleTextAttribute(h, 15);
		}

	} while (choice != 9);
	SetConsoleTextAttribute(h, 5);
	cout << "\nGoodbye! Thank you for playing Mini WAR Card Game" << endl;
	SetConsoleTextAttribute(h, 15);
}


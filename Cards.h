//Made By Francisco Pedrosa (N0883131)
#pragma once
#include <../../Header.h>

const int TOTAL_CARDS = 53;

class Cards
{
public:
	Cards();

	void setNum(int);
	int getNum();
	char getFigure();
	char getSuit();
	int getPoints();
	string getName();


private:
	int cardNum = 0;

	struct CardStruct
	{
		char figure;
		char suit;
		int points;
	};	

	CardStruct card[TOTAL_CARDS];
	
	void cardsList();
};




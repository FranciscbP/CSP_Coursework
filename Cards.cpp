//Made By Francisco Pedrosa (N0883131)
#include <../../Cards.h>

//When Class Used -> Iniciate Cards List
Cards::Cards()
{
	Cards::cardsList();
}

//Cards List
void Cards::cardsList()
{
	//Not Shown
	card[0].figure = 'X'; card[0].suit = 'X'; card[0].points = 0;
	//Spades
	card[1].figure = 'A'; card[1].suit = 'S'; card[1].points = 11;
	card[2].figure = '2'; card[2].suit = 'S'; card[2].points = 2;
	card[3].figure = '3'; card[3].suit = 'S'; card[3].points = 3;
	card[4].figure = '4'; card[4].suit = 'S'; card[4].points = 4;
	card[5].figure = '5'; card[5].suit = 'S'; card[5].points = 5;
	card[6].figure = '6'; card[6].suit = 'S'; card[6].points = 6;
	card[7].figure = '7'; card[7].suit = 'S'; card[7].points = 7;
	card[8].figure = '8'; card[8].suit = 'S'; card[8].points = 8;
	card[9].figure = '9'; card[9].suit = 'S'; card[9].points = 9;
	card[10].figure = 'T'; card[10].suit = 'S'; card[10].points = 10;
	card[11].figure = 'J'; card[11].suit = 'S'; card[11].points = 10;
	card[12].figure = 'Q'; card[12].suit = 'S'; card[12].points = 10;
	card[13].figure = 'K'; card[13].suit = 'S'; card[13].points = 10;
	//Clubs
	card[14].figure = 'A'; card[14].suit = 'C'; card[14].points = 11;
	card[15].figure = '2'; card[15].suit = 'C'; card[15].points = 2;
	card[16].figure = '3'; card[16].suit = 'C'; card[16].points = 3;
	card[17].figure = '4'; card[17].suit = 'C'; card[17].points = 4;
	card[18].figure = '5'; card[18].suit = 'C'; card[18].points = 5;
	card[19].figure = '6'; card[19].suit = 'C'; card[19].points = 6;
	card[20].figure = '7'; card[20].suit = 'C'; card[20].points = 7;
	card[21].figure = '8'; card[21].suit = 'C'; card[21].points = 8;
	card[22].figure = '9'; card[22].suit = 'C'; card[22].points = 9;
	card[23].figure = 'T'; card[23].suit = 'C'; card[23].points = 10;
	card[24].figure = 'J'; card[24].suit = 'C'; card[24].points = 10;
	card[25].figure = 'Q'; card[25].suit = 'C'; card[25].points = 10;
	card[26].figure = 'K'; card[26].suit = 'C'; card[26].points = 10;
	//Hearts
	card[27].figure = 'A'; card[27].suit = 'H'; card[27].points = 11;
	card[28].figure = '2'; card[28].suit = 'H'; card[28].points = 2;
	card[29].figure = '3'; card[29].suit = 'H'; card[29].points = 3;
	card[30].figure = '4'; card[30].suit = 'H'; card[30].points = 4;
	card[31].figure = '5'; card[31].suit = 'H'; card[31].points = 5;
	card[32].figure = '6'; card[32].suit = 'H'; card[32].points = 6;
	card[33].figure = '7'; card[33].suit = 'H'; card[33].points = 7;
	card[34].figure = '8'; card[34].suit = 'H'; card[34].points = 8;
	card[35].figure = '9'; card[35].suit = 'H'; card[35].points = 9;
	card[36].figure = 'T'; card[36].suit = 'H'; card[36].points = 10;
	card[37].figure = 'J'; card[37].suit = 'H'; card[37].points = 10;
	card[38].figure = 'Q'; card[38].suit = 'H'; card[38].points = 10;
	card[39].figure = 'K'; card[39].suit = 'H'; card[39].points = 10;
	//Diamonds
	card[40].figure = 'A'; card[40].suit = 'D'; card[40].points = 11;
	card[41].figure = '2'; card[41].suit = 'D'; card[41].points = 2;
	card[42].figure = '3'; card[42].suit = 'D'; card[42].points = 3;
	card[43].figure = '4'; card[43].suit = 'D'; card[43].points = 4;
	card[44].figure = '5'; card[44].suit = 'D'; card[44].points = 5;
	card[45].figure = '6'; card[45].suit = 'D'; card[45].points = 6;
	card[46].figure = '7'; card[46].suit = 'D'; card[46].points = 7;
	card[47].figure = '8'; card[47].suit = 'D'; card[47].points = 8;
	card[48].figure = '9'; card[48].suit = 'D'; card[48].points = 9;
	card[49].figure = 'T'; card[49].suit = 'D'; card[49].points = 10;
	card[50].figure = 'J'; card[50].suit = 'D'; card[50].points = 10;
	card[51].figure = 'Q'; card[51].suit = 'D'; card[51].points = 10;
	card[52].figure = 'K'; card[52].suit = 'D'; card[52].points = 10;
}

//Set Card Number
void Cards::setNum(int num)
{
	cardNum = num;
}

//Get Card Number
int Cards::getNum()
{
	return cardNum;
}

//Get Suit
char Cards::getSuit()
{
	char suit;
	suit = card[cardNum].suit;

	return suit;
}

//Get Figure
char Cards::getFigure()
{
	char figure;
	figure = card[cardNum].figure;

	return figure;
}

//Get Points
int Cards::getPoints()
{
	int points;
	points = card[cardNum].points;

	return points;
}

//Get Card Name
string Cards::getName()
{
	string name;
	char figure;
	char suit;

	name = "";
	figure = getFigure();
	suit = getSuit();

	switch (figure)
	{
	case 'A':
		name = "Ace of ";
		break;
	case '2':
		name = "Two of ";
		break;
	case '3':
		name = "Three of ";
		break;
	case '4':
		name = "Four of ";
		break;
	case '5':
		name = "Five of ";
		break;
	case '6':
		name = "Six of ";
		break;
	case '7':
		name = "Seven of ";
		break;
	case '8':
		name = "Eight of ";
		break;
	case '9':
		name = "Nine of ";
		break;
	case 'T':
		name = "Ten of ";
		break;
	case 'J':
		name = "Jack of ";
		break;
	case 'Q':
		name = "Queen of ";
		break;
	case 'K':
		name = "King of ";
		break;
	default:
		break;
	}

	switch (suit)
	{
	case 'S':
		name = name + "Spades";
		break;
	case 'C':
		name = name + "Clubs";
		break;
	case 'D':
		name = name + "Diamonds";
		break;
	case 'H':
		name = name + "Hearts";
		break;
	default:
		break;
	}

	return name;
}
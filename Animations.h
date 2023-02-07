#pragma once
#include <../../Header.h>
#include <../../Cards.h>
#include <../../Users.h>

//Colors
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

const int NUM_COLS = 35;
const int NUM_ROWS = 5;

//Main Image
void mainImage(int location)
{
	//Set Color
	SetConsoleTextAttribute(color, 14);
	cout << "\t\t\t\t      ____  _            _       _            _    \n";
	cout << "\t\t\t\t     | __ )| | __ _  ___| | __  | | __ _  ___| | __\n";
	cout << "\t\t\t\t     |  _ \\| |/ _` |/ __| |/ /  | |/ _` |/ __| |/ /\n";
	cout << "\t\t\t\t     | |_) | | (_| | (__|   < |_| | (_| | (__|   < \n";

	//Change Main Image Location
	switch (location)
	{
		case 0:
			cout << "\t\t\t\t     |____/|_|\\__,_|\\___|_|\\_\\___/ \\__,_|\\___|_|\\_\\\n";
			break;
		case 1:
			cout << "\t\t\t\t     |____/|_|\\__,_|\\___|_|\\_\\___/ \\__,_|\\___|_|\\_\\ Table\n";
			break;
		case 2:
			cout << "\t\t\t\t     |____/|_|\\__,_|\\___|_|\\_\\___/ \\__,_|\\___|_|\\_\\ Account Menu\n";
			break;
		case 3:
			cout << "\t\t\t\t     |____/|_|\\__,_|\\___|_|\\_\\___/ \\__,_|\\___|_|\\_\\ Log In\n";
			break;
		case 4:
			cout << "\t\t\t\t     |____/|_|\\__,_|\\___|_|\\_\\___/ \\__,_|\\___|_|\\_\\ Register\n";
			break;
		case 5:
			cout << "\t\t\t\t     |____/|_|\\__,_|\\___|_|\\_\\___/ \\__,_|\\___|_|\\_\\ Add Money\n";
			break;
	}

	cout << "\n";
	SetConsoleTextAttribute(color, 15);
}

//Exit Animation
void exit()
{
	cout << "\n\n\t\t\t\t\t\t******  *     * *******    ***\n";
	Sleep(10);
	system("cls");
	cout << "\n\n\t\t\t\t\t\t******  *     * *******    ***\n";
	cout << "\t\t\t\t\t\t*     *  *   *  *          ***\n";
	Sleep(10);
	system("cls");
	cout << "\n\n\t\t\t\t\t\t******  *     * *******    ***\n";
	cout << "\t\t\t\t\t\t*     *  *   *  *          ***\n";
	cout << "\t\t\t\t\t\t*     *   * *   *          *** \n";
	Sleep(10);
	system("cls");
	cout << "\n\n\t\t\t\t\t\t******  *     * *******    ***\n";
	cout << "\t\t\t\t\t\t*     *  *   *  *          ***\n";
	cout << "\t\t\t\t\t\t*     *   * *   *          *** \n";
	cout << "\t\t\t\t\t\t******     *    *****      ***\n";
	Sleep(10);
	system("cls");
	cout << "\n\n\t\t\t\t\t\t******  *     * *******    ***\n";
	cout << "\t\t\t\t\t\t*     *  *   *  *          ***\n";
	cout << "\t\t\t\t\t\t*     *   * *   *          *** \n";
	cout << "\t\t\t\t\t\t******     *    *****      ***\n";
	cout << "\t\t\t\t\t\t*     *    *    *\n";
	Sleep(10);
	system("cls");
	cout << "\n\n\t\t\t\t\t\t******  *     * *******    ***\n";
	cout << "\t\t\t\t\t\t*     *  *   *  *          ***\n";
	cout << "\t\t\t\t\t\t*     *   * *   *          *** \n";
	cout << "\t\t\t\t\t\t******     *    *****      ***\n";
	cout << "\t\t\t\t\t\t*     *    *    *\n";
	cout << "\t\t\t\t\t\t*     *    *    *          ***\n";
	Sleep(10);
	system("cls");
	cout << "\n\n\t\t\t\t\t\t******  *     * *******    ***\n";
	cout << "\t\t\t\t\t\t*     *  *   *  *          ***\n";
	cout << "\t\t\t\t\t\t*     *   * *   *          *** \n";
	cout << "\t\t\t\t\t\t******     *    *****      ***\n";
	cout << "\t\t\t\t\t\t*     *    *    *\n";
	cout << "\t\t\t\t\t\t*     *    *    *          ***\n";
	cout << "\t\t\t\t\t\t******     *    *******    ***\n";

	cout << "\n\t\t\t\t\t\tThank you for Playing...\n\n\n";
}

//Cards Animation
void cardsAnimation(int numOfCards, int cardNum1, int cardNum2, int cardNum3, int cardNum4, int cardNum5, int cardNum6)
{
	//Set Cards
	Cards card1, card2, card3, card4, card5 , card6;
	card1.setNum(cardNum1);
	card2.setNum(cardNum2);
	card3.setNum(cardNum3);
	card4.setNum(cardNum4);
	card5.setNum(cardNum5);
	card6.setNum(cardNum6);

	//Create Card Image
	char cards[NUM_ROWS][NUM_COLS];

	//Clear Card Image
	for (int count1 = 0; count1 < NUM_ROWS; count1++)
	{
		for (int count2 = 0; count2 < NUM_COLS; count2++)
		{
			cards[count1][count2] = ' ';
		}
	}

	//Set Card Image
	switch (numOfCards)
	{
		case 1:
			//Card1
			cards[0][13] = '_';
			cards[0][14] = '_';
			cards[0][15] = '_';
			cards[1][12] = '|';
			cards[1][16] = '|';
			cards[2][12] = '|';
			cards[2][14] = card1.getFigure();
			cards[2][16] = '|';
			cards[3][12] = '|';
			cards[3][14] = card1.getSuit();
			cards[3][16] = '|';
			cards[4][12] = '|';
			cards[4][13] = '_';
			cards[4][14] = '_';
			cards[4][15] = '_';
			cards[4][16] = '|';
			break;

		case 2:
			//Card1
			cards[0][13] = '_';
			cards[0][14] = '_';
			cards[0][15] = '_';
			cards[1][12] = '|';
			cards[1][16] = '|';
			cards[2][12] = '|';
			cards[2][14] = card1.getFigure();
			cards[2][16] = '|';
			cards[3][12] = '|';
			cards[3][14] = card1.getSuit();
			cards[3][16] = '|';
			cards[4][12] = '|';
			cards[4][13] = '_';
			cards[4][14] = '_';
			cards[4][15] = '_';
			cards[4][16] = '|';
			//Card2
			cards[0][19] = '_';
			cards[0][20] = '_';
			cards[0][21] = '_';
			cards[1][18] = '|';
			cards[1][22] = '|';
			cards[2][18] = '|';
			cards[2][20] = card2.getFigure();
			cards[2][22] = '|';
			cards[3][18] = '|';
			cards[3][20] = card2.getSuit();
			cards[3][22] = '|';
			cards[4][18] = '|';
			cards[4][19] = '_';
			cards[4][20] = '_';
			cards[4][21] = '_';
			cards[4][22] = '|';
			break;

		case 3:
			//Card1
			cards[0][7] = '_';
			cards[0][8] = '_';
			cards[0][9] = '_';
			cards[1][6] = '|';
			cards[1][10] = '|';
			cards[2][6] = '|';
			cards[2][8] = card1.getFigure();
			cards[2][10] = '|';
			cards[3][6] = '|';
			cards[3][8] = card1.getSuit();
			cards[3][10] = '|';
			cards[4][6] = '|';
			cards[4][7] = '_';
			cards[4][8] = '_';
			cards[4][9] = '_';
			cards[4][10] = '|';
			//Card2
			cards[0][13] = '_';
			cards[0][14] = '_';
			cards[0][15] = '_';
			cards[1][12] = '|';
			cards[1][16] = '|';
			cards[2][12] = '|';
			cards[2][14] = card2.getFigure();
			cards[2][16] = '|';
			cards[3][12] = '|';
			cards[3][14] = card2.getSuit();
			cards[3][16] = '|';
			cards[4][12] = '|';
			cards[4][13] = '_';
			cards[4][14] = '_';
			cards[4][15] = '_';
			cards[4][16] = '|';
			//Card3
			cards[0][19] = '_';
			cards[0][20] = '_';
			cards[0][21] = '_';
			cards[1][18] = '|';
			cards[1][22] = '|';
			cards[2][18] = '|';
			cards[2][20] = card3.getFigure();
			cards[2][22] = '|';
			cards[3][18] = '|';
			cards[3][20] = card3.getSuit();
			cards[3][22] = '|';
			cards[4][18] = '|';
			cards[4][19] = '_';
			cards[4][20] = '_';
			cards[4][21] = '_';
			cards[4][22] = '|';
			break;

		case 4:
			//Card1
			cards[0][7] = '_';
			cards[0][8] = '_';
			cards[0][9] = '_';
			cards[1][6] = '|';
			cards[1][10] = '|';
			cards[2][6] = '|';
			cards[2][8] = card1.getFigure();
			cards[2][10] = '|';
			cards[3][6] = '|';
			cards[3][8] = card1.getSuit();
			cards[3][10] = '|';
			cards[4][6] = '|';
			cards[4][7] = '_';
			cards[4][8] = '_';
			cards[4][9] = '_';
			cards[4][10] = '|';
			//Card2
			cards[0][13] = '_';
			cards[0][14] = '_';
			cards[0][15] = '_';
			cards[1][12] = '|';
			cards[1][16] = '|';
			cards[2][12] = '|';
			cards[2][14] = card2.getFigure();
			cards[2][16] = '|';
			cards[3][12] = '|';
			cards[3][14] = card2.getSuit();
			cards[3][16] = '|';
			cards[4][12] = '|';
			cards[4][13] = '_';
			cards[4][14] = '_';
			cards[4][15] = '_';
			cards[4][16] = '|';
			//Card3
			cards[0][19] = '_';
			cards[0][20] = '_';
			cards[0][21] = '_';
			cards[1][18] = '|';
			cards[1][22] = '|';
			cards[2][18] = '|';
			cards[2][20] = card3.getFigure();
			cards[2][22] = '|';
			cards[3][18] = '|';
			cards[3][20] = card3.getSuit();
			cards[3][22] = '|';
			cards[4][18] = '|';
			cards[4][19] = '_';
			cards[4][20] = '_';
			cards[4][21] = '_';
			cards[4][22] = '|';
			//Card4
			cards[0][25] = '_';
			cards[0][26] = '_';
			cards[0][27] = '_';
			cards[1][24] = '|';
			cards[1][28] = '|';
			cards[2][24] = '|';
			cards[2][26] = card4.getFigure();
			cards[2][28] = '|';
			cards[3][24] = '|';
			cards[3][26] = card4.getSuit();
			cards[3][28] = '|';
			cards[4][24] = '|';
			cards[4][25] = '_';
			cards[4][26] = '_';
			cards[4][27] = '_';
			cards[4][28] = '|';
			break;

		case 5:
			//Card1
			cards[0][1] = '_';
			cards[0][2] = '_';
			cards[0][3] = '_';
			cards[1][0] = '|';
			cards[1][4] = '|';
			cards[2][0] = '|';
			cards[2][2] = card1.getFigure();
			cards[2][4] = '|';
			cards[3][0] = '|';
			cards[3][2] = card1.getSuit();
			cards[3][4] = '|';
			cards[4][0] = '|';
			cards[4][1] = '_';
			cards[4][2] = '_';
			cards[4][3] = '_';
			cards[4][4] = '|';
			//Card2
			cards[0][7] = '_';
			cards[0][8] = '_';
			cards[0][9] = '_';
			cards[1][6] = '|';
			cards[1][10] = '|';
			cards[2][6] = '|';
			cards[2][8] = card2.getFigure();
			cards[2][10] = '|';
			cards[3][6] = '|';
			cards[3][8] = card2.getSuit();
			cards[3][10] = '|';
			cards[4][6] = '|';
			cards[4][7] = '_';
			cards[4][8] = '_';
			cards[4][9] = '_';
			cards[4][10] = '|';
			//Card3
			cards[0][13] = '_';
			cards[0][14] = '_';
			cards[0][15] = '_';
			cards[1][12] = '|';
			cards[1][16] = '|';
			cards[2][12] = '|';
			cards[2][14] = card3.getFigure();
			cards[2][16] = '|';
			cards[3][12] = '|';
			cards[3][14] = card3.getSuit();
			cards[3][16] = '|';
			cards[4][12] = '|';
			cards[4][13] = '_';
			cards[4][14] = '_';
			cards[4][15] = '_';
			cards[4][16] = '|';
			//Card4
			cards[0][19] = '_';
			cards[0][20] = '_';
			cards[0][21] = '_';
			cards[1][18] = '|';
			cards[1][22] = '|';
			cards[2][18] = '|';
			cards[2][20] = card4.getFigure();
			cards[2][22] = '|';
			cards[3][18] = '|';
			cards[3][20] = card4.getSuit();
			cards[3][22] = '|';
			cards[4][18] = '|';
			cards[4][19] = '_';
			cards[4][20] = '_';
			cards[4][21] = '_';
			cards[4][22] = '|';
			//Card5
			cards[0][25] = '_';
			cards[0][26] = '_';
			cards[0][27] = '_';
			cards[1][24] = '|';
			cards[1][28] = '|';
			cards[2][24] = '|';
			cards[2][26] = card5.getFigure();
			cards[2][28] = '|';
			cards[3][24] = '|';
			cards[3][26] = card5.getSuit();
			cards[3][28] = '|';
			cards[4][24] = '|';
			cards[4][25] = '_';
			cards[4][26] = '_';
			cards[4][27] = '_';
			cards[4][28] = '|';
			break;

		case 6:
			//Card1
			cards[0][1] = '_';
			cards[0][2] = '_';
			cards[0][3] = '_';
			cards[1][0] = '|';
			cards[1][4] = '|';
			cards[2][0] = '|';
			cards[2][2] = card1.getFigure();
			cards[2][4] = '|';
			cards[3][0] = '|';
			cards[3][2] = card1.getSuit();
			cards[3][4] = '|';
			cards[4][0] = '|';
			cards[4][1] = '_';
			cards[4][2] = '_';
			cards[4][3] = '_';
			cards[4][4] = '|';
			//Card2
			cards[0][7] = '_';
			cards[0][8] = '_';
			cards[0][9] = '_';
			cards[1][6] = '|';
			cards[1][10] = '|';
			cards[2][6] = '|';
			cards[2][8] = card2.getFigure();
			cards[2][10] = '|';
			cards[3][6] = '|';
			cards[3][8] = card2.getSuit();
			cards[3][10] = '|';
			cards[4][6] = '|';
			cards[4][7] = '_';
			cards[4][8] = '_';
			cards[4][9] = '_';
			cards[4][10] = '|';
			//Card3
			cards[0][13] = '_';
			cards[0][14] = '_';
			cards[0][15] = '_';
			cards[1][12] = '|';
			cards[1][16] = '|';
			cards[2][12] = '|';
			cards[2][14] = card3.getFigure();
			cards[2][16] = '|';
			cards[3][12] = '|';
			cards[3][14] = card3.getSuit();
			cards[3][16] = '|';
			cards[4][12] = '|';
			cards[4][13] = '_';
			cards[4][14] = '_';
			cards[4][15] = '_';
			cards[4][16] = '|';
			//Card4
			cards[0][19] = '_';
			cards[0][20] = '_';
			cards[0][21] = '_';
			cards[1][18] = '|';
			cards[1][22] = '|';
			cards[2][18] = '|';
			cards[2][20] = card4.getFigure();
			cards[2][22] = '|';
			cards[3][18] = '|';
			cards[3][20] = card4.getSuit();
			cards[3][22] = '|';
			cards[4][18] = '|';
			cards[4][19] = '_';
			cards[4][20] = '_';
			cards[4][21] = '_';
			cards[4][22] = '|';
			//Card5
			cards[0][25] = '_';
			cards[0][26] = '_';
			cards[0][27] = '_';
			cards[1][24] = '|';
			cards[1][28] = '|';
			cards[2][24] = '|';
			cards[2][26] = card5.getFigure();
			cards[2][28] = '|';
			cards[3][24] = '|';
			cards[3][26] = card5.getSuit();
			cards[3][28] = '|';
			cards[4][24] = '|';
			cards[4][25] = '_';
			cards[4][26] = '_';
			cards[4][27] = '_';
			cards[4][28] = '|';
			//Card6
			cards[0][31] = '_';
			cards[0][32] = '_';
			cards[0][33] = '_';
			cards[1][30] = '|';
			cards[1][34] = '|';
			cards[2][30] = '|';
			cards[2][32] = card6.getFigure();
			cards[2][34] = '|';
			cards[3][30] = '|';
			cards[3][32] = card6.getSuit();
			cards[3][34] = '|';
			cards[4][30] = '|';
			cards[4][31] = '_';
			cards[4][32] = '_';
			cards[4][33] = '_';
			cards[4][34] = '|';
			break;

		default:
			break;
	}

	//Show Cards
	for (int i = 0; i < NUM_ROWS; i++)
	{
		cout << "\t\t|\t\t\t  ";
		for (int j = 0; j < NUM_COLS; j++)
		{
			cout << cards[i][j];
		}
		cout << "\t\t\t     |\n";
	}
}

//Show Money
void showMoney(int bettedMoney, int totalMoney)
{	
	//Betted Money
	if (bettedMoney < 10)
	{
		cout << "\t\t|\t\t\t\t    Betted Money: " << bettedMoney << "$\t\t\t\t     |\n";
	}
	else if (bettedMoney >= 10 && bettedMoney < 100)
	{
		cout << "\t\t|\t\t\t\t   Betted Money: " << bettedMoney << "$\t\t\t\t     |\n";
	}
	else if (bettedMoney >= 100 && bettedMoney < 1000)
	{
		cout << "\t\t|\t\t\t\t   Betted Money: " << bettedMoney << "$\t\t\t\t     |\n";
	}
	else if (bettedMoney >= 1000 && bettedMoney < 10000)
	{
		cout << "\t\t|\t\t\t\t  Betted Money: " << bettedMoney << "$\t\t\t\t     |\n";
	}
	else if (bettedMoney >= 10000 && bettedMoney < 100000)
	{
		cout << "\t\t|\t\t\t\t  Betted Money: " << bettedMoney << "$\t\t\t\t     |\n";
	}
	else
	{
		cout << "\t\t|\t\t\t\t Betted Money: " << bettedMoney << "$\t\t\t\t     |\n";
	}

	//Total Money
	if (totalMoney < 10)
	{
		cout << "\t\t|\t\t\t\t     Total Money: " << totalMoney << "$\t\t\t\t     |\n";
	}
	else if (totalMoney >= 10 && totalMoney < 100)
	{
		cout << "\t\t|\t\t\t\t    Total Money: " << totalMoney << "$\t\t\t\t     |\n";
	}
	else if (totalMoney >= 100 && totalMoney < 1000)
	{
		cout << "\t\t|\t\t\t\t    Total Money: " << totalMoney << "$\t\t\t\t     |\n";
	}
	else if (totalMoney >= 1000 && totalMoney < 10000)
	{
		cout << "\t\t|\t\t\t\t   Total Money: " << totalMoney << "$\t\t\t\t     |\n";
	}
	else if (totalMoney >= 10000 && totalMoney < 100000)
	{
		cout << "\t\t|\t\t\t\t   Total Money: " << totalMoney << "$\t\t\t\t     |\n";
	}
	else
	{
		cout << "\t\t|\t\t\t\t  Total Money: " << totalMoney << "$\t\t\t\t     |\n";
	}
}

//Loading
void loading()
{
	int dots = 1;

	for (int count = 0; count <= 10; count++)
	{
		system("cls");
		mainImage(0);
		switch (dots)
		{
			case 1:
				cout << "\n\n\n\t\t\t\t\t\t\tLoading.\n\n";
				dots = dots + 1;
				break;
			case 2:
				cout << "\n\n\n\t\t\t\t\t\t\tLoading..\n\n";
				dots = dots + 1;
				break;
			case 3:
				cout << "\n\n\n\t\t\t\t\t\t\tLoading...\n\n";
				dots = 1;
				break;
		}
		Sleep(500);
	}
}


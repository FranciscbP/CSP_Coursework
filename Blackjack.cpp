//Made By Francisco Pedrosa (N0883131)
#include <../../Header.h>
#include <../../Cards.h>
#include <../../Animations.h>
#include <../../Users.h>

const int MAX_CARDS = 6;
const int BLACKJACK = 21;

int userLogged = 0;

//Declare Functions
void mainMenu();
void game();
void table( int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
int calcPoints(int, int, int, int, int, int);
void accountMenu(int accountIsLogged);
void accountRegister(string);
void accountLogIn();
void accountAddMoney();
void accountShowMoney();

//Main
int main()
{
	/*Change Console Title and Size*/
	SetConsoleTitle(TEXT("BlackJack"));
	system("MODE 119,35");

	mainMenu();
	getch();
	return 0;

}

//Main Menu
void mainMenu()
{
	int menuOption = 0;

	system("cls");
	mainImage(0);
	Sleep(300);
	cout << "\n\n\t\t\t\t\t\t\t1 - Play";
	Sleep(300);
	cout << "\n\t\t\t\t\t\t\t2 - Account";
	Sleep(300);
	cout << "\n\t\t\t\t\t\t\t3 - Exit";

	cout << "\n\n\t\t\t\t     Option => ";
	cin >> menuOption;

	switch (menuOption)
	{
		case 1:		
			if (userLogged == 0)
			{	
				//Account Is not Logged
				cout << "\n\t\t\t\t     You need to Log In First!";
				getch();
				accountMenu(userLogged);
			}
			else
			{
				Users user;
				user.setNum(userLogged);

				int userMoney;
				userMoney = user.getMoney();

				if (userMoney == 0)
				{
					//Account has no Money
					cout << "\n\t\t\t\t     You don't have any money!";
					getch();
					accountMenu(userLogged);
				}
				else
				{
					//Loagin Screen -> Game
					loading();
					game();
				}
			}
			break;
		case 2:
			accountMenu(userLogged);
			break;
		case 3:
			exit();
			break;
		default:
			mainMenu();
			break;
	}
}

//Game
void game()
{
	Users user;
	user.setNum(userLogged);

	int optionPlayAgain = 1;

	//Play
	do
	{
		// Variables
		vector <int> usedCards;
		Cards dealerCards[MAX_CARDS], playerCards[MAX_CARDS];
		int dealerPoints = 0;
		int dealerNumOfCards = 0;
		int playerPoints = 0;
		int playerNumOfCards = 0;
		int bettedMoney = 0;
		int playerCalcPoints = 0;
		int dealerCalcPoints = 0;
		int playOption = 0;
		int playerCardPosition = 0;
		int dealerCardPosition = 0;
		int money = 0;

		money = user.getMoney();

		//Money To Bet
		system("cls");
		table(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		cout << "\n\t\t Money to Bet -> ";
		cin >> bettedMoney;

		if (bettedMoney > money)
		{
			cout << "\n\t\t You Cannot Bet More Money Than You Have!";
			getch();
			bettedMoney = money;
		}

		user.updateMoney(money - bettedMoney);

		//Deal First Cards
		for (int count = 1; count <= 4; count++)
		{
			system("cls");
			
			//Clear Random Number
			srand(time(NULL));
			int randCard = 0;

			switch (count)
			{
				case 1:
					//Player First Card
					randCard = rand() % 52 + 1;
					playerCards[0].setNum(randCard);

					usedCards.push_back(playerCards[0].getNum());

					playerCalcPoints = calcPoints(playerCards[0].getNum(), playerCards[1].getNum(), playerCards[2].getNum(), playerCards[3].getNum(), playerCards[4].getNum(), playerCards[5].getNum());
					
					table(0, dealerCalcPoints, dealerCards[0].getNum(), dealerCards[1].getNum(), dealerCards[2].getNum(), dealerCards[3].getNum(), dealerCards[4].getNum(), dealerCards[5].getNum(), 1, playerCalcPoints, playerCards[0].getNum(), playerCards[1].getNum(), playerCards[2].getNum(), playerCards[3].getNum(), playerCards[4].getNum(), playerCards[5].getNum(), bettedMoney);
					cout << "\n\t\tGAME: You got a " << playerCards[0].getName() << "!\n";
					getch();
					break;
				case 2:
					//Dealer First Card
					do
					{
						int totalUsedCards = 0;
						int sameCard = 0;

						totalUsedCards = usedCards.size();
						randCard = rand() % 52 + 1;
						 
						for (int i = 0; i < totalUsedCards; i++)
						{
							if (randCard == usedCards[i])
							{
								sameCard = 1;
							}
						}

						if (sameCard != 1)
						{
							dealerCards[0].setNum(randCard);
							usedCards.push_back(dealerCards[0].getNum());
						}

					} while (dealerCards[0].getNum() == 0);

					dealerCalcPoints = calcPoints(dealerCards[0].getNum(), dealerCards[1].getNum(), dealerCards[2].getNum(), dealerCards[3].getNum(), dealerCards[4].getNum(), dealerCards[5].getNum());

					table(1, dealerCalcPoints, dealerCards[0].getNum(), dealerCards[1].getNum(), dealerCards[2].getNum(), dealerCards[3].getNum(), dealerCards[4].getNum(), dealerCards[5].getNum(), 1, playerCalcPoints, playerCards[0].getNum(), playerCards[1].getNum(), playerCards[2].getNum(), playerCards[3].getNum(), playerCards[4].getNum(), playerCards[5].getNum(), bettedMoney);
					cout << "\n\t\tGAME: Dealer got a " << dealerCards[0].getName() << "!\n";
					getch();
					break;
				case 3:
					//Player Second Card
					do
					{
						int totalUsedCards = 0;
						int sameCard = 0;

						totalUsedCards = usedCards.size();
						randCard = rand() % 52 + 1;

						for (int i = 0; i < totalUsedCards; i++)
						{
							if (randCard == usedCards[i])
							{
								sameCard = 1;
							}
						}

						if (sameCard != 1)
						{
							playerCards[1].setNum(randCard);
							usedCards.push_back(playerCards[1].getNum());
						}

					} while (playerCards[1].getNum() == 0);

					playerCalcPoints = calcPoints(playerCards[0].getNum(), playerCards[1].getNum(), playerCards[2].getNum(), playerCards[3].getNum(), playerCards[4].getNum(), playerCards[5].getNum());
					
					table(1, dealerCalcPoints, dealerCards[0].getNum(), dealerCards[1].getNum(), dealerCards[2].getNum(), dealerCards[3].getNum(), dealerCards[4].getNum(), dealerCards[5].getNum(), 2, playerCalcPoints, playerCards[0].getNum(), playerCards[1].getNum(), playerCards[2].getNum(), playerCards[3].getNum(), playerCards[4].getNum(), playerCards[5].getNum(), bettedMoney);
					cout << "\n\t\tGAME: You got a " << playerCards[1].getName() << "!\n";
					getch();
					break;
				case 4:
					//Dealer Second Card, Not Shown
					do
					{
						int totalUsedCards = 0;
						int sameCard = 0;

						totalUsedCards = usedCards.size();
						randCard = rand() % 52 + 1;

						for (int i = 0; i < totalUsedCards; i++)
						{
							if (randCard == usedCards[i])
							{
								sameCard = 1;
							}
						}

						if (sameCard != 1)
						{
							dealerCards[1].setNum(randCard);
							usedCards.push_back(dealerCards[1].getNum());
						}

					} while (dealerCards[1].getNum() == 0);

					dealerCalcPoints = calcPoints(dealerCards[0].getNum(), 0, dealerCards[2].getNum(), dealerCards[3].getNum(), dealerCards[4].getNum(), dealerCards[5].getNum());

					table(2, dealerCalcPoints, dealerCards[0].getNum(), 0, dealerCards[2].getNum(), dealerCards[3].getNum(), dealerCards[4].getNum(), dealerCards[5].getNum(), 2, playerCalcPoints, playerCards[0].getNum(), playerCards[1].getNum(), playerCards[2].getNum(), playerCards[3].getNum(), playerCards[4].getNum(), playerCards[5].getNum(), bettedMoney);
					break;
			}

		}
		
		//Ask player to play
		do 
		{	
			if (playerCalcPoints == BLACKJACK)
			{
				SetConsoleTextAttribute(color, 02);
				cout << "\n\t\tGAME: You got a BlackJack!\n";	
				cout << "\t\tGAME: You Win!";
				SetConsoleTextAttribute(color, 15);
				break;
			}

			cout << "\n\t\t\t\t\t\t  1 - HIT || 2 - STAND ";
			cout << "\n\t\tOption -> ";
			cin >> playOption;

			if (playOption == 1)
			{
				system("cls");

				//Clear Random Number
				srand(time(NULL));
				int randCard = 0;

				//Get Player Card Position
				playerCardPosition = 0;
				for (int cont = 0; cont < 6; cont++)
				{
					if (playerCards[cont].getNum() != 0)
					{
						playerCardPosition = cont + 1;
					}
				}

				//Give Card to Player
				do
				{
					int totalUsedCards = 0;
					int sameCard = 0;

					totalUsedCards = usedCards.size();
					randCard = rand() % 52 + 1;

					for (int i = 0; i < totalUsedCards; i++)
					{
						if (randCard == usedCards[i])
						{
							sameCard = 1;
						}
					}

					if (sameCard != 1)
					{
						playerCards[playerCardPosition].setNum(randCard);
						usedCards.push_back(playerCards[playerCardPosition].getNum());
					}

				} while (playerCards[playerCardPosition].getNum() == 0);

				playerCalcPoints = calcPoints(playerCards[0].getNum(), playerCards[1].getNum(), playerCards[2].getNum(), playerCards[3].getNum(), playerCards[4].getNum(), playerCards[5].getNum());

				table(2, dealerCalcPoints, dealerCards[0].getNum(), 0, dealerCards[2].getNum(), dealerCards[3].getNum(), dealerCards[4].getNum(), dealerCards[5].getNum(), (playerCardPosition + 1), playerCalcPoints, playerCards[0].getNum(), playerCards[1].getNum(), playerCards[2].getNum(), playerCards[3].getNum(), playerCards[4].getNum(), playerCards[5].getNum(), bettedMoney);
				cout << "\n\t\tGAME: You got a " << playerCards[playerCardPosition].getName() << "!\n";
				getch();

				//Show Table with Option & Withowt Game Message
				system("cls");
				table(2, dealerCalcPoints, dealerCards[0].getNum(), 0, dealerCards[2].getNum(), dealerCards[3].getNum(), dealerCards[4].getNum(), dealerCards[5].getNum(), (playerCardPosition + 1), playerCalcPoints, playerCards[0].getNum(), playerCards[1].getNum(), playerCards[2].getNum(), playerCards[3].getNum(), playerCards[4].getNum(), playerCards[5].getNum(), bettedMoney);
			}

			playerCalcPoints = calcPoints(playerCards[0].getNum(), playerCards[1].getNum(), playerCards[2].getNum(), playerCards[3].getNum(), playerCards[4].getNum(), playerCards[5].getNum());
			
			if (playerCalcPoints == BLACKJACK)
			{
				SetConsoleTextAttribute(color, 02);
				cout << "\n\t\tGAME: You got a BlackJack!";
				SetConsoleTextAttribute(color, 15);
				getch();
				break;
			}
			else if (playerCalcPoints > BLACKJACK)
			{
				SetConsoleTextAttribute(color, 12);
				cout << "\n\t\tGAME: You Busted!";
				SetConsoleTextAttribute(color, 15);
				getch();
				break;
			}

		} while (playOption != 2);

		system("cls");

		if (playerCalcPoints >= BLACKJACK)
		{
			//Get Player Card Position
			playerCardPosition = 0;
			for (int cont = 0; cont < 6; cont++)
			{
				if (playerCards[cont].getNum() != 0)
				{
					playerCardPosition = cont + 1;
				}
			}

			dealerCalcPoints = calcPoints(dealerCards[0].getNum(), dealerCards[1].getNum(), dealerCards[2].getNum(), dealerCards[3].getNum(), dealerCards[4].getNum(), dealerCards[5].getNum());
			table(2, dealerCalcPoints, dealerCards[0].getNum(), dealerCards[1].getNum(), dealerCards[2].getNum(), dealerCards[3].getNum(), dealerCards[4].getNum(), dealerCards[5].getNum(), playerCardPosition, playerCalcPoints, playerCards[0].getNum(), playerCards[1].getNum(), playerCards[2].getNum(), playerCards[3].getNum(), playerCards[4].getNum(), playerCards[5].getNum(), bettedMoney);
			
			if (playerCalcPoints == BLACKJACK)
			{
				SetConsoleTextAttribute(color, 02);
				cout << "\n\t\tGAME: You got a BlackJack!";
				SetConsoleTextAttribute(color, 15);
				cout << "\n\t\tGAME: Dealer got a "<< dealerCards[1].getName() <<"!";
				money = user.getMoney();
				user.updateMoney((bettedMoney * 2.5) + money);
			}
			else
			{
				SetConsoleTextAttribute(color, 12);
				cout << "\n\t\tGAME: You Busted!";
				SetConsoleTextAttribute(color, 15);
				cout << "\n\t\tGAME: Dealer got a " << dealerCards[1].getName() << "!";
			}
			getch();
		}
		else
		{
			//Get Player Card Position
			playerCardPosition = 0;
			for (int cont = 0; cont < 6; cont++)
			{
				if (playerCards[cont].getNum() != 0)
				{
					playerCardPosition = cont + 1;
				}
			}

			dealerCalcPoints = calcPoints(dealerCards[0].getNum(), dealerCards[1].getNum(), dealerCards[2].getNum(), dealerCards[3].getNum(), dealerCards[4].getNum(), dealerCards[5].getNum());
			table(2, dealerCalcPoints, dealerCards[0].getNum(), dealerCards[1].getNum(), dealerCards[2].getNum(), dealerCards[3].getNum(), dealerCards[4].getNum(), dealerCards[5].getNum(), playerCardPosition, playerCalcPoints, playerCards[0].getNum(), playerCards[1].getNum(), playerCards[2].getNum(), playerCards[3].getNum(), playerCards[4].getNum(), playerCards[5].getNum(), bettedMoney);
			cout << "\n\t\tGAME: Dealer got a " << dealerCards[1].getName() << "!\n";
			getch();

			do
			{
				system("cls");

				//Clear Random Number
				srand(time(NULL));
				int randCard = 0;

				//Get Dealer Card Position
				dealerCardPosition = 0;
				for (int cont = 0; cont < 6; cont++)
				{
					if (dealerCards[cont].getNum() != 0)
					{
						dealerCardPosition = cont + 1;
					}
				}

				if (dealerCalcPoints >= 17 && dealerCalcPoints < BLACKJACK)
				{
					//Check who has the nearest Points to 21
					playerCalcPoints = calcPoints(playerCards[0].getNum(), playerCards[1].getNum(), playerCards[2].getNum(), playerCards[3].getNum(), playerCards[4].getNum(), playerCards[5].getNum());

					if (dealerCalcPoints > playerCalcPoints)
					{
						
						system("cls");
						table(dealerCardPosition, dealerCalcPoints, dealerCards[0].getNum(), dealerCards[1].getNum(), dealerCards[2].getNum(), dealerCards[3].getNum(), dealerCards[4].getNum(), dealerCards[5].getNum(), playerCardPosition, playerCalcPoints, playerCards[0].getNum(), playerCards[1].getNum(), playerCards[2].getNum(), playerCards[3].getNum(), playerCards[4].getNum(), playerCards[5].getNum(), bettedMoney);
						SetConsoleTextAttribute(color, 12);
						cout << "\n\t\tGAME: Dealer Wins!";
						SetConsoleTextAttribute(color, 15);
					}
					else if (dealerCalcPoints < playerCalcPoints)
					{
						
						system("cls");
						table(dealerCardPosition, dealerCalcPoints, dealerCards[0].getNum(), dealerCards[1].getNum(), dealerCards[2].getNum(), dealerCards[3].getNum(), dealerCards[4].getNum(), dealerCards[5].getNum(), playerCardPosition, playerCalcPoints, playerCards[0].getNum(), playerCards[1].getNum(), playerCards[2].getNum(), playerCards[3].getNum(), playerCards[4].getNum(), playerCards[5].getNum(), bettedMoney);
						SetConsoleTextAttribute(color, 2);
						cout << "\n\t\tGAME: You Win!";
						SetConsoleTextAttribute(color, 15);
						money = user.getMoney();
						user.updateMoney((bettedMoney * 2) + money);
						
					}
					else
					{
						system("cls");
						table(dealerCardPosition, dealerCalcPoints, dealerCards[0].getNum(), dealerCards[1].getNum(), dealerCards[2].getNum(), dealerCards[3].getNum(), dealerCards[4].getNum(), dealerCards[5].getNum(), playerCardPosition, playerCalcPoints, playerCards[0].getNum(), playerCards[1].getNum(), playerCards[2].getNum(), playerCards[3].getNum(), playerCards[4].getNum(), playerCards[5].getNum(), bettedMoney);
						SetConsoleTextAttribute(color, 06);
						cout << "\n\t\tGAME: Draw!";
						SetConsoleTextAttribute(color, 15);
						money = user.getMoney();
						user.updateMoney((bettedMoney * 1) + money);
					}
					break;
				}
				else if (dealerCalcPoints == BLACKJACK)
				{
					system("cls");
					table(dealerCardPosition, dealerCalcPoints, dealerCards[0].getNum(), dealerCards[1].getNum(), dealerCards[2].getNum(), dealerCards[3].getNum(), dealerCards[4].getNum(), dealerCards[5].getNum(), playerCardPosition, playerCalcPoints, playerCards[0].getNum(), playerCards[1].getNum(), playerCards[2].getNum(), playerCards[3].getNum(), playerCards[4].getNum(), playerCards[5].getNum(), bettedMoney);
					SetConsoleTextAttribute(color, 12);
					cout << "\n\t\tGAME: Dealer got a BlackJack!";
					cout << "\n\t\tGAME: Dealer Wins!";
					SetConsoleTextAttribute(color, 15);
					break;
					getch();
				}

				//Give Card to Dealer
				do
				{
					int totalUsedCards = 0;
					int sameCard = 0;

					totalUsedCards = usedCards.size();
					randCard = rand() % 52 + 1;

					for (int i = 0; i < totalUsedCards; i++)
					{
						if (randCard == usedCards[i])
						{
							sameCard = 1;
						}
					}

					if (sameCard != 1)
					{
						dealerCards[dealerCardPosition].setNum(randCard);
						usedCards.push_back(dealerCards[dealerCardPosition].getNum());
					}

				} while (dealerCards[dealerCardPosition].getNum() == 0);

				dealerCalcPoints = calcPoints(dealerCards[0].getNum(), dealerCards[1].getNum(), dealerCards[2].getNum(), dealerCards[3].getNum(), dealerCards[4].getNum(), dealerCards[5].getNum());
				table((dealerCardPosition + 1), dealerCalcPoints, dealerCards[0].getNum(), dealerCards[1].getNum(), dealerCards[2].getNum(), dealerCards[3].getNum(), dealerCards[4].getNum(), dealerCards[5].getNum(), playerCardPosition, playerCalcPoints, playerCards[0].getNum(), playerCards[1].getNum(), playerCards[2].getNum(), playerCards[3].getNum(), playerCards[4].getNum(), playerCards[5].getNum(), bettedMoney);
				
				cout << "\n\t\tGAME: Dealer got a " << dealerCards[dealerCardPosition].getName() << "!\n";
				getch();


				if (dealerCalcPoints > BLACKJACK)
				{
					system("cls");
					table((dealerCardPosition + 1), dealerCalcPoints, dealerCards[0].getNum(), dealerCards[1].getNum(), dealerCards[2].getNum(), dealerCards[3].getNum(), dealerCards[4].getNum(), dealerCards[5].getNum(), playerCardPosition, playerCalcPoints, playerCards[0].getNum(), playerCards[1].getNum(), playerCards[2].getNum(), playerCards[3].getNum(), playerCards[4].getNum(), playerCards[5].getNum(), bettedMoney);
					SetConsoleTextAttribute(color, 02);
					cout << "\n\t\tGAME: Dealer Busted!";
					cout << "\n\t\tGAME: You Win!";
					SetConsoleTextAttribute(color, 15);
					money = user.getMoney();
					user.updateMoney((bettedMoney * 2) + money);
					break;
					getch();
				}
				else if (dealerCalcPoints >= 17 && dealerCalcPoints <= BLACKJACK)
				{
					//Check who has the nearest Points to 21
					dealerCalcPoints = calcPoints(dealerCards[0].getNum(), dealerCards[1].getNum(), dealerCards[2].getNum(), dealerCards[3].getNum(), dealerCards[4].getNum(), dealerCards[5].getNum());
					playerCalcPoints = calcPoints(playerCards[0].getNum(), playerCards[1].getNum(), playerCards[2].getNum(), playerCards[3].getNum(), playerCards[4].getNum(), playerCards[5].getNum());

					if (dealerCalcPoints > playerCalcPoints)
					{
						system("cls");
						table((dealerCardPosition + 1), dealerCalcPoints, dealerCards[0].getNum(), dealerCards[1].getNum(), dealerCards[2].getNum(), dealerCards[3].getNum(), dealerCards[4].getNum(), dealerCards[5].getNum(), playerCardPosition, playerCalcPoints, playerCards[0].getNum(), playerCards[1].getNum(), playerCards[2].getNum(), playerCards[3].getNum(), playerCards[4].getNum(), playerCards[5].getNum(), bettedMoney);
						SetConsoleTextAttribute(color, 12);
						cout << "\n\t\tGAME: Dealer Wins!";
						SetConsoleTextAttribute(color, 15);
					}
					else if(dealerCalcPoints < playerCalcPoints)
					{
						system("cls");
						table((dealerCardPosition + 1), dealerCalcPoints, dealerCards[0].getNum(), dealerCards[1].getNum(), dealerCards[2].getNum(), dealerCards[3].getNum(), dealerCards[4].getNum(), dealerCards[5].getNum(), playerCardPosition, playerCalcPoints, playerCards[0].getNum(), playerCards[1].getNum(), playerCards[2].getNum(), playerCards[3].getNum(), playerCards[4].getNum(), playerCards[5].getNum(), bettedMoney);
						SetConsoleTextAttribute(color, 02);
						cout << "\n\t\tGAME: You Win!";
						SetConsoleTextAttribute(color, 15);
						money = user.getMoney();
						user.updateMoney((bettedMoney * 2) + money);
					}
					else
					{
						system("cls");
						table((dealerCardPosition + 1), dealerCalcPoints, dealerCards[0].getNum(), dealerCards[1].getNum(), dealerCards[2].getNum(), dealerCards[3].getNum(), dealerCards[4].getNum(), dealerCards[5].getNum(), playerCardPosition, playerCalcPoints, playerCards[0].getNum(), playerCards[1].getNum(), playerCards[2].getNum(), playerCards[3].getNum(), playerCards[4].getNum(), playerCards[5].getNum(), bettedMoney);
						SetConsoleTextAttribute(color, 06);
						cout << "\n\t\tGAME: Draw!";
						SetConsoleTextAttribute(color, 15);
						money = user.getMoney();
						user.updateMoney((bettedMoney * 1) + money);
					}
					break;
				}

			} while (true);
			getch();
		}

		//Ask Play Again
		cout << "\n\n\t\tPlay Again ( 1 - Yes || 2 - No )?\n\t\tOption -> ";
		cin >> optionPlayAgain;


	} while (optionPlayAgain == 1);

	mainMenu();

}

//Calculate Points
int calcPoints(int card1, int card2, int card3, int card4, int card5, int card6)
{
	int cardIsAce = 0;
	int points = 0;
	Cards crds[6];
	crds[0].setNum(card1);
	crds[1].setNum(card2);
	crds[2].setNum(card3);
	crds[3].setNum(card4);
	crds[4].setNum(card5);
	crds[5].setNum(card6);

	for (int i = 0; i < 6; i++)
	{
		if (crds[i].getFigure() == 'A')
		{
			cardIsAce = cardIsAce + 1;
		}

		points = points + crds[i].getPoints();
	}

	if (points > BLACKJACK)
	{
		switch (cardIsAce)
		{
			case 1:
				points = points - 10;
				break;
			case 2:
				points = points - 20;
				break;
			case 3:
				points = points - 30;
				break;
			case 4:
				points = points - 40;
				break;
			default:
				break;
		}
	}

	return points ;

}

// Table
void table(int dealerCards, int dealerPoints, int dealerCard1, int dealerCard2, int dealerCard3, int dealerCard4, int dealerCard5, int dealerCard6, int playerCards, int playerPoints, int playerCard1, int playerCard2, int playerCard3, int playerCard4, int playerCard5, int playerCard6, int bettedMoney)
{
	mainImage(1);

	int totalMoney = 0;

	Users user;
	user.setNum(userLogged);

	totalMoney = user.getMoney();

	cout << "\t\t/------------------------------------------------------------------------------------\\\n";
	cout << "\t\t|\t\t\t\t    Dealer Points(" << dealerPoints << ")\t\t\t\t     |\n";
	cardsAnimation(dealerCards, dealerCard1, dealerCard2, dealerCard3, dealerCard4, dealerCard5, dealerCard6);
	cout << "\t\t|\t\t\t\t\t\t\t\t\t\t     |\n";
	cout << "\t\t|\t\t\t\t\t\t\t\t\t\t     |\n";
	cout << "\t\t|\t\t---------------------------+---------------------------\t\t     |\n";
	cout << "\t\t|\t\t\t\t\t\t\t\t\t\t     |\n";
	cardsAnimation(playerCards, playerCard1, playerCard2, playerCard3, playerCard4, playerCard5, playerCard6);
	cout << "\t\t|\t\t\t\t\t\t\t\t\t\t     |\n";
	showMoney(bettedMoney,totalMoney);
	cout << "\t\t|\t\t\t\t\t\t\t\t\t\t     |\n";
	cout << "\t\t|\t\t\t\t     Your Points(" << playerPoints << ")\t\t\t\t     |\n";
	cout << "\t\t\\------------------------------------------------------------------------------------/\n";

}

//Account Menu
void accountMenu(int accountIsLogged)
{
	int menuOption = 0;

	if (accountIsLogged == 0)
	{
		system("cls");
		mainImage(2);
		Sleep(300);
		cout << "\n\n\t\t\t\t\t\t\t1 - Log In\n";
		Sleep(300);
		cout << "\t\t\t\t\t\t\t2 - Register\n";
		Sleep(300);
		cout << "\t\t\t\t\t\t\t3 - Back To Menu\n";

		cout << "\n\n\t\t\t\t     Option => ";
		cin >> menuOption;

		switch (menuOption)
		{
			case 1:
				accountLogIn();
				break;
			case 2:
				accountRegister("");
				break;
			case 3:
				mainMenu();
				break;
			default:
				accountMenu(0);
				break;
		}
	}
	else
	{
		system("cls");
		mainImage(2);
		Sleep(300);
		cout << "\n\n\t\t\t\t\t\t\t1 - Show Money\n";
		Sleep(300);
		cout << "\t\t\t\t\t\t\t2 - Add Money\n";
		Sleep(300);
		cout << "\t\t\t\t\t\t\t3 - Log Out\n";
		Sleep(300);
		cout << "\t\t\t\t\t\t\t4 - Back To Menu\n";

		cout << "\n\n\t\t\t\t     Option => ";
		cin >> menuOption;

		switch (menuOption)
		{
			case 1:
				accountShowMoney();
				break;
			case 2:
				accountAddMoney();
				break;
			case 3:				
				userLogged = 0;
				mainMenu();
				break;
			case 4:
				mainMenu();
				break;
			default:
				accountMenu(1);
				break;
		}
	}
}

//Register Account
void accountRegister( string name)
{
	system("cls");
	mainImage(4);

	Users user;

	int userLine;
	string username;
	string password;
	string repeatPassword;

	if (name == "")
	{
		cout << "\n\n\t\t\t\t\t\tUsername -> ";
		cin >> username;
	}
	else
	{
		cout << "\n\n\t\t\t\t\t\tUsername -> " << name <<"\n";
		username = name;
	}

	if (user.checkUsername(username) != 0)
	{
		cout << "\n\t\t\t\t\t\tUser Already Exists!!";
		getch();
		accountRegister("");
	}
	else
	{
		cout << "\t\t\t\t\t\tPassword -> ";
		cin >> password;
		cout << "\t\t\t\t\t\tRepeat Password -> ";
		cin >> repeatPassword;

		if (password == repeatPassword)
		{
			user.createUser(username,password);
			
			cout << "\n\t\t\t\t\t\tUser Registred Successfully!";
			getch();
			accountLogIn();
		}
		else
		{
			cout << "\n\t\t\t\t\t\tPasswords Don't Match!";
			getch();
			accountRegister(username);
		}

	}
	
	getch();
}

//Log In Account
void accountLogIn()
{
	system("cls");
	mainImage(3);

	Users user;

	int userLine;
	string username;
	string password;

	cout << "\n\n\t\t\t\t\t\tUsername -> ";
	cin >> username;
	cout << "\t\t\t\t\t\tPassword -> ";
	cin >> password;

	userLine = user.logUser(username,password);

	if (userLine != 0)
	{
		cout << "\n\t\t\t\t\t\tUser Logged In Successfully!";
		userLogged = userLine;
		getch();
		mainMenu();
	}
	else
	{
		cout << "\n\t\t\t\t\t\tUser or Password Incorrect!";
		getch();
		accountMenu(userLogged);
	}


}

//Add Money to Account
void accountAddMoney()
{
	Users user;
	user.setNum(userLogged);

	int updateMoney;
	int currentMoney;

	system("cls");
	mainImage(5);

	currentMoney = user.getMoney();

	cout << "\n\n\t\t\t\t\t\tAdd Money -> ";
	cin >> updateMoney;

	

	user.updateMoney(currentMoney + updateMoney);
	cout << "\n\t\t\t\t\t\tMoney Added Successfully!";
	getch();
	accountMenu(userLogged);
}

//Shou Account's Money
void accountShowMoney()
{
	Users user;
	user.setNum(userLogged);

	int currentMoney;

	system("cls");
	mainImage(5);

	currentMoney = user.getMoney();

	cout << "\n\n\t\t\t\t\t\tCurrent Money: " << currentMoney << "$\n";
	getch();
	accountMenu(userLogged);
}
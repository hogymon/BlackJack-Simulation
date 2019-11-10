#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class cards
{
	public:
		int card1;
		int card2;
		int card3;
		int card4;
		int card5;
		
		int sum(int card1, int card2, int card3, int card4, int card5)
		{
			return card1+card2+card3+card4+card5;
		}
		bool bust(int total)
		{
			if (total>21)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool blackjack(int total)
		{
			if (total==21)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};

printSum(int somesum)
{
	cout << "Your current sum is " << somesum << endl;
}

void printCards(int cardvalue, bool suit_type[], int i)
{
		cout << "Your card is ";
		
		if(cardvalue <= 10 && cardvalue !=1)
		{
			cout << cardvalue << " of ";
		}
		else if(cardvalue == 1)
		{
			cout << "Ace of ";
		}
		else if (cardvalue == 11)
		{
			cout <<"Jack of ";
		}
		else if (cardvalue == 12)
		{
			cout <<"Queen of ";
		}
		else if (cardvalue == 13)
		{
			cout <<"King of ";
		}
			if(suit_type [i] == true)
			{
				if (i == 0)
				{
					cout << "Hearts" << endl;
				}
				else if (i == 1)
				{
					cout <<"Clubs" << endl;
				}
				else if (i == 2)
				{
					cout << "Spades" << endl;
				}
				else if (i == 3)
				{
					cout << "Diamonds" << endl;
				}
			}
		
}

void RoyaltoTen(int &Royal)
{
	if (Royal > 10)
	{
		Royal = 10;
	}
}

void Ace(int sum, int &ace)
{
	sum +=10;
	if (ace == 1 && sum <= 21)
	{
		ace = 11;
	}
}

void doubleace(int &sum, int &p1, int&p2, int &p3, int&p4, int &p5)
{
	if (sum >21)
	{
		if(p1 == 11)
		{
			p1 = 1;
		}
		if (p2 == 11)
		{
			p2 = 1;
		}
		if (p3 == 11)
		{
			p3 = 1;
		}
		if (p4 == 11)
		{
			p4 = 1;
		}
		if(p5 == 11)
		{
			p5 = 1;
		}
		sum = p1+p2+p3+p4+p5;
	}
}

int dealer(int previousDcard1, int previousDcard2, int previousDcard3, int previousDcard4, int myCard1, int myCard2, int myCard3, int myCard4,int myCard5)
{
	int count = 0;
	bool accept = false;
	int nextDcard = 0;
	while(accept == false)
	{
		nextDcard = rand()%((13-1)+1) +1;
		if(nextDcard == myCard1)
		{
			count ++;
		}
		if (nextDcard == myCard2)
		{
			count ++;
		}
		if(nextDcard == myCard3)
		{
			count ++;
		}
		if(nextDcard == myCard4)
		{
			count++;
		}
		if(nextDcard == myCard5)
		{
			count++;
		}
		if(nextDcard == previousDcard1)
		{
			count++;
		}
		if(nextDcard == previousDcard2)
		{
			count++;
		}
		if(nextDcard == previousDcard3)
		{
			count++;
		}
		if(count<=3)
		{
			accept = true;
		}
	}
	if(nextDcard >10)
	{
		nextDcard = 10;	
	}
	return nextDcard;
}

void loopSuit(int j, int  (&tempsuit)[5], bool (&suit)[4], int Card1, int Card2, int Card3, int Card4, int Card5)
{
	bool find = false;
	while (find == false)
		{	
			tempsuit[j] = rand()%((3-0)+1) +0;
			bool checkSuit = false;
			
			for(int k = 0; k <j; k++)
			{
				if (suit[tempsuit[1]] == true)
				{
					checkSuit = true;
				}
			}
			
			if(checkSuit = true && Card1 == Card2)
			{
				suit[tempsuit[j]] = true;
				find = true;
			}
			else if (checkSuit = true && Card1 == Card3)
			{
				suit[tempsuit[j]] = true;
				find = true;
			}
			else if (checkSuit = true && Card1 == Card4)
			{
				suit[tempsuit[j]] = true;
				find = true;
			}
			else if (checkSuit = true && Card1 == Card5)
			{
				suit[tempsuit[j]] = true;
				find = true;
			}
			else
			{
				suit[tempsuit[j]] = true;
				find = true;
			}
		}
}
int main()
{
	cout << "Welcome to Hogy's Casino! Today's Hot Event is Blackjack!" << endl;
	cout << "The rules are simple! The objective of the game is to get a sum of 21 from the cards in your hand. This is known as 'Blackjack'. " << endl;
	cout << "Additional Rules: " << endl << "The Buy-in is the total amount of money you initially put into the game. Deductions or additions will be made to this amount after each round." << endl;
	cout << "1) A 'Hit' means to be dealt another card to your hand." << endl; 
	cout << "2) A bust means to exceed a sum of 21. You can no longer win when this happens." << endl;
	cout << "3) If the player gets Blackjack, he/she will automatically win, unless the Dealer also gets Blackjack, in which case the Dealer will win." << endl;
	cout << "4) If neither the player nor the Dealer gets Blackjack, the highest sum that is under 21 will be considered to be the winning hand." << endl;
	cout << "5) If either the player or the Dealer gets a bust, the other person will automatically win." << endl;
	cout << "6) If both the player and the Dealer gets busts, the round ends in a draw. The bet amount will be returned to the player." << endl;
	cout << "7) A minimum bet of 5 dollars must be made per round. A win will return an interest of 100%. If the player wins by Blackjack, the return will be 150%." << endl;
	cout << "8) The player may quit after each round." << endl << endl << "Good luck, and Have Fun!" << endl << endl << endl;
	
	int wallet = 0;
	int buyin = 0;
	int bet = 0;
	bool stop = false;
	cards myCard;
	cards dCard;
	ofstream fout("Receipt.txt");
	bool receipt = false;
	
	cout << "Enter your Buy-In:" << endl;
	cin >> wallet;
	buyin = wallet;
	
	while(wallet >=5  && stop == false)
	{
		bool hitCard = false;
		bool suit[4] = {false};
		int tempsuit[5] = {0};
		int myTempsum = 0;
		int dTempsum = 0;
		int mySum = 0;
		int dSum = 0;
		int count = 0;
		myCard.card1=0, myCard.card2=0, myCard.card3=0, myCard.card4=0, myCard.card5 = 0;
		dCard.card1 =0, dCard.card2=0, dCard.card3=0, dCard.card4=0, dCard.card5 = 0;
		bool bust = false;
		bool blackjack = false;
		bool dbust = false;
		bool dblackjack = false;
		
		
		srand(time(NULL));
		bool dealornot = false;
		cout << "Place your bet:" << endl;
		cin >> bet;
		while(dealornot == false)
		{
			if(bet >= 5)
			{
				wallet -=bet;
				cout << "Deal" << endl << endl;
				dealornot = true;
			}
			else if (bet<5)
			{
				cout << "Insufficient amount" << endl << "Place your bet" << endl;
				cin>>bet;
				
			}
			else
			{
				cout <<"Invalid entry" << endl << "Place your bet" << endl;
				cin >> bet;
			}
		}
		
		myCard.card1 = rand()%((13-1)+1) +1;
		tempsuit[0] = rand()%((3-0)+1) +0;
		suit[tempsuit[0]] = true;
		printCards(myCard.card1, suit, tempsuit[0]);
		RoyaltoTen(myCard.card1);
		myTempsum = myCard.sum(myCard.card1, myCard.card2, myCard.card3, myCard.card4, myCard.card5);
		Ace(myTempsum, myCard.card1);
		mySum = myCard.sum(myCard.card1, myCard.card2, myCard.card3, myCard.card4, myCard.card5);
		myTempsum = mySum;
		
		myCard.card2 = rand()%((13-1)+1) +1;
		loopSuit(1,tempsuit, suit, myCard.card2, myCard.card1, myCard.card3, myCard.card4, myCard.card5);
		printCards(myCard.card2, suit, tempsuit[1]);
		RoyaltoTen(myCard.card2);
		myTempsum = myCard.sum(myCard.card1, myCard.card2, myCard.card3, myCard.card4, myCard.card5);
		Ace(myTempsum, myCard.card2);
		mySum = myCard.sum(myCard.card1, myCard.card2, myCard.card3, myCard.card4, myCard.card5);
		myTempsum = mySum;
		printSum(mySum);
		blackjack = myCard.blackjack(mySum);
		
		dCard.card1 = dealer(0,0,0,0,myCard.card1,myCard.card2,myCard.card3,myCard.card4,myCard.card5);
		cout << "The dealer's first card is a " << dCard.card1 << endl;
		dTempsum = dCard.sum(dCard.card1, dCard.card2, dCard.card3,dCard.card4, dCard.card5);
		Ace(dTempsum, dCard.card1);
		dSum = dCard.sum(dCard.card1, dCard.card2, dCard.card3,dCard.card4, dCard.card5);
		dTempsum = dSum;
		
		dCard.card2 = dealer(dCard.card1,0,0,0,myCard.card1,myCard.card2,myCard.card3,myCard.card4,myCard.card5);
		dTempsum = dCard.sum(dCard.card1, dCard.card2, dCard.card3,dCard.card4, dCard.card5);
		Ace(dTempsum, dCard.card2);
		dSum = dCard.sum(dCard.card1, dCard.card2, dCard.card3,dCard.card4, dCard.card5);
		dTempsum = dSum;
		if(dSum == 21)
		{
			dblackjack = true;
		}
		else if (dSum >21)
		{
			dbust = true;
		}
		
		if(dbust == false && dblackjack == false && dSum <17)
				{
					cout <<"Dealer hits a card to himself" << endl;
					dCard.card3 = dealer(dCard.card1,dCard.card2,0,0,myCard.card1,myCard.card2,myCard.card3,myCard.card4,myCard.card5);
					dTempsum = dCard.sum(dCard.card1, dCard.card2, dCard.card3,dCard.card4, dCard.card5);
					Ace(dTempsum, dCard.card3);
					dSum = dCard.sum(dCard.card1, dCard.card2, dCard.card3,dCard.card4, dCard.card5);
					doubleace(dSum, dCard.card1, dCard.card2, dCard.card3,dCard.card4, dCard.card5);
					dTempsum = dSum;
					if(dSum == 21)
					{
						dblackjack = true;
					}
					else if (dSum >21)
					{
						dbust = true;
					}
				}
		
		cout << "Hit or Stand? (Enter 1 for Hit, 0 for Stand)" << endl;
		cin>>hitCard;
		count = 2;
		
		
		
		while(hitCard == true && bust == false && blackjack == false)
		{	
			if(count == 2)
			{
				myCard.card3 = rand()%((13-1)+1) +1;
				loopSuit(count,tempsuit, suit, myCard.card3, myCard.card1, myCard.card2, myCard.card4, myCard.card5);
				printCards(myCard.card3, suit, tempsuit[count]);
				RoyaltoTen(myCard.card3);
				myTempsum = myCard.sum(myCard.card1, myCard.card2, myCard.card3, myCard.card4, myCard.card5);
				Ace(myTempsum, myCard.card3);
				mySum = myCard.sum(myCard.card1, myCard.card2, myCard.card3, myCard.card4, myCard.card5);
				doubleace(mySum,myCard.card1, myCard.card2, myCard.card3, myCard.card4, myCard.card5);
				myTempsum = mySum;
				printSum(mySum);
				blackjack = myCard.blackjack(mySum);
				bust = myCard.bust(mySum);
			}
			else if(count == 3)
			{
				myCard.card4 = rand()%((13-1)+1) +1;
				loopSuit(count,tempsuit, suit, myCard.card4, myCard.card1, myCard.card2, myCard.card3, myCard.card5);
				printCards(myCard.card4, suit, tempsuit[count]);
				RoyaltoTen(myCard.card4);
				myTempsum = myCard.sum(myCard.card1, myCard.card2, myCard.card3, myCard.card4, myCard.card5);
				Ace(myTempsum, myCard.card4);
				mySum = myCard.sum(myCard.card1, myCard.card2, myCard.card3, myCard.card4, myCard.card5);
				doubleace(mySum,myCard.card1, myCard.card2, myCard.card3, myCard.card4, myCard.card5);
				myTempsum = mySum;
				printSum(mySum);
				blackjack = myCard.blackjack(mySum);
				bust = myCard.bust(mySum);
			}
			else
			{
				myCard.card5 = rand()%((13-1)+1) +1;
				loopSuit(count,tempsuit, suit, myCard.card5, myCard.card1, myCard.card2, myCard.card3, myCard.card4);
				printCards(myCard.card5, suit, tempsuit[count]);
				RoyaltoTen(myCard.card5);
				myTempsum = myCard.sum(myCard.card1, myCard.card2, myCard.card3, myCard.card4, myCard.card5);
				Ace(myTempsum, myCard.card5);
				mySum = myCard.sum(myCard.card1, myCard.card2, myCard.card3, myCard.card4, myCard.card5);
				doubleace(mySum,myCard.card1, myCard.card2, myCard.card3, myCard.card4, myCard.card5);
				myTempsum = mySum;
				printSum(mySum);
				blackjack = myCard.blackjack(mySum);
				bust = myCard.bust(mySum);
			}
			
			count++;
			if(blackjack == false && bust == false)
			{
				cout << "Hit or Stand? (Enter 1 for Hit, 0 for Stand)" << endl;
				cin>>hitCard;
			}
		}
		if(dbust == false && dblackjack == false && dSum <17)
				{
					cout <<"Dealer hits a card to himself" << endl;
					dCard.card4 = dealer(dCard.card1,dCard.card2,dCard.card3,0,myCard.card1,myCard.card2,myCard.card3,myCard.card4,myCard.card5);
					dTempsum = dCard.sum(dCard.card1, dCard.card2, dCard.card3,dCard.card4, dCard.card5);
					Ace(dTempsum, dCard.card4);
					dSum = dCard.sum(dCard.card1, dCard.card2, dCard.card3,dCard.card4, dCard.card5);
					doubleace(dSum, dCard.card1, dCard.card2, dCard.card3,dCard.card4, dCard.card5);
					dTempsum = dSum;
					if(dSum == 21)
					{
						dblackjack = true;
					}
					else if (dSum >21)
					{
						dbust = true;
					}
				}
			
		if(dbust == false && dblackjack == false && dSum <17)
				{
					cout <<"Dealer hits a card to himself" << endl;
					dCard.card5 = dealer(dCard.card1,dCard.card2,dCard.card3,dCard.card4,myCard.card1,myCard.card2,myCard.card3,myCard.card4,myCard.card5);
					dTempsum = dCard.sum(dCard.card1, dCard.card2, dCard.card3,dCard.card4, dCard.card5);
					Ace(dTempsum, dCard.card5);
					dSum = dCard.sum(dCard.card1, dCard.card2, dCard.card3,dCard.card4, dCard.card5);
					doubleace(dSum, dCard.card1, dCard.card2, dCard.card3,dCard.card4, dCard.card5);
					dTempsum = dSum;
					if(dSum == 21)
					{
						dblackjack = true;
					}
					else if (dSum >21)
					{
						dbust = true;
					}
				}
		cout << "Your sum is " << mySum << endl;
		cout << "Dealer's sum is " << dSum << endl;
		
		if (bust == true && dbust == true)
		{
			cout << "Both hands bust. Tie" << endl;
			wallet += bet;
		}
		else if (bust == true && dbust == false)
		{
			cout << "Bust. You lose..." << endl;
		}
		else if (bust == false && dbust == true)
		{
			cout <<"Dealer busts. You win!" << endl;
			if(	blackjack == true)
			{
				cout << "Blackjack! 1.5x Multipler" <<endl;
				wallet += bet*3;
			}
			else
			{
				wallet += bet*2;
			}
		}
		else if (bust == false && dbust == false)
		{
			if (mySum >dSum)
			{
				cout << "Higher sum. You win!" << endl;
				if(	blackjack == true)
				{
					cout << "Blackjack! 1.5x Multipler" <<endl;
					wallet += bet*3;
				}
				else
				{
					wallet += bet*2;
				}
			}
			else if (mySum < dSum)
			{
				cout << "Lower sum. You lose..." << endl;
			}
			if (blackjack == true && dblackjack == true)
			{
			 	cout << "Both sides have Blackjack. House wins by regulation..." << endl;
			}
		}
		
		cout << "You have " << wallet << " dollars left." << endl;
		
		cout << "Quit? (Enter 1 for Yes, 0 for No)" << endl;
		cin>>stop;
	}
	if (stop == true)
	{
		cout << "Thank you for playing!" << endl;
	}
	else if (stop == false)
	{
		cout << "You've run out of money!" << endl;
		cout << "Game over..." << endl;
	}
	
	cout <<"Would you like a receipt? (Enter 1 for Yes, 0 for No)" << endl;
	cin>> receipt;
	if (receipt == true)
	{
		fout << "Your net profit: $" << wallet-buyin << endl;
		fout << "Thank you for playing at Hogy's Casino. Please come again!" << endl;
		cout << "Your receipt has been sent. Thank you for playing!" << endl;
	}
	
	fout.close();
	return 0;
}

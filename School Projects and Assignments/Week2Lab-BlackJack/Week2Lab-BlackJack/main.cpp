#include <iostream>
#include "Card.h"
#include <vector>
#include <string>

using namespace std;

string showCards(vector<Card> cards);
short sumCardValues(vector<Card> cards);
void playHand(short &cash);

int main()
{
	short cash = 100;

	cout << "Welcome to the BLACKJACK GAME!!!" << endl << "You currently have $" << cash << endl;

	system("pause");

	short input;

	do
	{
		system("cls");
		cout << "What would you like to do?" << endl << "1) Play a hand" << endl << "2) Show cash amount" << endl << "3) Exit" << endl;
		cin >> input;

		switch (input)
		{
		case 1:
			playHand(cash);
			break;
		case 2:
			cout << "Your balance is $" << cash << endl;
			break;
		case 3:
			cout << "Exiting" << endl;
			break;
		default:
			cout << "Not valid" << endl;
			break;
		}

		system("pause");

	} while (input != 3);
}

string showCards(vector<Card> cards)
{
	string output = "";
	for each(Card c in cards)
	{
		output += c.toString() + " ";
	}
	return output;
}

short sumCardValues(vector<Card> cards)
{
	short output = 0;
	for each(Card c in cards)
	{
		output += c.getValue();
	}
	return output;
}

void playHand(short &cash)
{
	vector<Card> dealerCards;
	vector<Card> playerCards;

	short playerTotal = 0;
	short dealerTotal = 0;

	short bet = 0;

	char answer;

	system("cls");

	cout << "Place your bet!!!" << endl;

	cin >> bet;

	dealerCards.push_back(Card());
	dealerCards.push_back(Card());
	dealerTotal = sumCardValues(dealerCards);

	playerCards.push_back(Card());
	playerCards.push_back(Card());
	playerTotal = sumCardValues(playerCards);

	do
	{
		system("cls");
		
		cout << "The dealer's cards: " << dealerCards[0].toString() << endl << endl;

		cout << "Your cards: " << showCards(playerCards) << endl;

		cout << "Your value: " << playerTotal << endl << endl;

		cout << "What would you like to do?" << endl << endl << "Hit (H)" << endl << "Stay (S)" << endl;

		cin >> answer;

		if (toupper(answer) == 'H')
		{
			playerCards.push_back(Card());
			playerTotal = sumCardValues(playerCards);
			if (playerTotal > 21)
			{
				for each(Card c in playerCards)
				{
					if (c.flipAceToOne())
					{
						system("pause");
						break;
					}
				}

				playerTotal = sumCardValues(playerCards);

				if (playerTotal > 21)
				{
					answer = 'S';
				}
			}
		}
		else if (toupper(answer) == 'S')
		{
			//do nothing, just let the loop end
		}
		else
		{
			cout << "That is not a valid action" << endl;
			system("pause");
		}

	} while (toupper(answer) != 'S');
	
	if (playerTotal > 21)
	{
		system("cls");
		
		cout << "The dealer's cards: " << dealerCards[0].toString() << endl << endl;

		cout << "Your cards: " << showCards(playerCards) << endl;

		cout << "Your value: " << playerTotal << endl << endl;

		cout << "You busted!" << endl;

		cash -= bet;

		system("pause");

		return;
	}
	else
	{
		while (dealerTotal < 17)
		{
			dealerCards.push_back(Card());
			dealerTotal = sumCardValues(dealerCards);
		}

		system("cls");

		cout << "The dealer's cards: " << showCards(dealerCards) << endl;

		cout << "The  dealer's total: " << dealerTotal << endl << endl;

		cout << "Your cards: " << showCards(playerCards) << endl;

		cout << "Your value: " << playerTotal << endl << endl;

		if (dealerTotal > 21)
		{
			cout << "The delaer busted! YOU WIN!" << endl;

			cash += bet;
		}
		else if (playerTotal > dealerTotal)
		{
			cout << "YOU WIN!" << endl;
			cash += bet;
		}
		else if (playerTotal < dealerTotal)
		{
			cout << "Looks like you lost. That's ok, I'm sure you'll win next time!" << endl;
			cash -= bet;
		}
		else
		{
			cout << "Looks like it's a push!" << endl;
		}
	}
}
#include "Card.h"

bool Card::randomizerSeed = false;


Card::Card()
{
	if (!randomizerSeed)
	{
		randomizerSeed = true;
		srand(time(NULL));
	}

	suit = rand() % 4 + 3;
	short temp = rand() % 7 + 2;

	if (temp <= 9)
	{
		face = char(48 + temp);
		value = temp;
	}
	else
	{
		switch (temp)
		{
		case 10:
			face = 'T';
			value = 10;
			break;
		case 11:
			face = 'J';
			value = 10;
			break;
		case 12:
			face = 'Q';
			value = 10;
			break;
		case 13:
			face = 'K';
			value = 10;
			break;
		case 14:
			face = 'A';
			value = 11;
			break;
		default:
			cout << endl << endl << "Random number error. Exiting Program" << endl;
			system("pause");
			exit(-1);

		}
	}
}


Card::~Card()
{
}

string Card::toString()
{
	string output = "";
	output += suit;
	output += face;
	return output;
}

bool Card::flipAceToOne()
{
	if (value == 11)
	{
		value = 1;
		cout << endl << "You exceeded 21, but you had an Ace that is now a 1" << endl << endl;
		return true;
	}
	else
	{
		return false;
	}
}

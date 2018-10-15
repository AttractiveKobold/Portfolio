#pragma once

#include <ctime>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Card
{
private:
	char suit;
	char face;
	short value;
	static bool randomizerSeed;
public:
	Card();
	~Card();
	string toString();
	bool flipAceToOne();

	char getSuit() { return suit; }
	char getFace() { return face; }
	short getValue(){ return value; }
};


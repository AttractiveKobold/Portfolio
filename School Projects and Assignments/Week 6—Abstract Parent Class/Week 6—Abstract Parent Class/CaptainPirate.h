#pragma once
#include "Pirate.h"
class CaptainPirate :
	public Pirate
{
private:
	string pet;
public:
	CaptainPirate() : Pirate(), pet("") {}
	CaptainPirate(string n, string m) : Pirate(n), pet(m) {}
	~CaptainPirate() {}

	virtual string speak(void);
	virtual string toString(void);

	string getPet(void) { return pet; }
	void setPet(string n) { pet = n; }
};


#pragma once
#include "Pirate.h"
class ZombiePirate :
	public Pirate
{
private:
	short brainHunger;
public:
	ZombiePirate() : Pirate(), brainHunger(0) {}
	ZombiePirate(string n, short m) : Pirate(n), brainHunger(m) {}
	~ZombiePirate() {}

	virtual string speak(void);
	virtual string toString(void);

	short getBrainHunger(void) { return brainHunger; }
	void setBrainHunger(short n) { brainHunger = n; }
};


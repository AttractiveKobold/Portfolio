#pragma once
#include <string>
using namespace std;
class Pirate
{
protected:
	string name;
public:
	Pirate(void) : name("")  {}
	Pirate(string n) : name(n) {}
	~Pirate(void) {}

	virtual string speak(void) = 0;
	virtual string toString(void);

	string getName(void) { return name; }
	void setName(string n) { name = n; }
};


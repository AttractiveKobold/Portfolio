#include <iostream>
#include "ZombiePirate.h"
#include "CaptainPirate.h"
using namespace std;

void outputPirate(Pirate* p)
{
	CaptainPirate* cp = dynamic_cast<CaptainPirate*>(p);
	ZombiePirate* zp = dynamic_cast<ZombiePirate*>(p);

	cout << "Name: " << p->getName() << endl;

	if (cp != NULL)
		cout << "Pet: " << cp->getPet() << endl;
	else if (zp != NULL)
		cout << "Brain Hunger: " << zp->getBrainHunger() << endl;
}

int main()
{
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	Pirate* pirates[3];

	pirates[0] = new CaptainPirate("Jack", "Sparrow");
	pirates[1] = new ZombiePirate("One-Eye Pete", 3);
	pirates[2] = new ZombiePirate("Other-Eye Pete", 5);

	for (Pirate* p : pirates)
	{
		cout << p->speak() << endl;
	}

	for (Pirate* p : pirates)
	{
		outputPirate(p);
	}

	delete[] pirates;

	system("pause");
	return 0;
}
#include "ZombiePirate.h"

string ZombiePirate::speak(void)
{
	switch (brainHunger)
	{
	case 0:
		return "Yum. I just ate a brain!";
		break;
	case 1:
		return "I'm getting a little hungry... Are there any brains out there?";
		break;
	case 2:
	case 3:
		return "I'm getting very hungry!! I need a brain to eat!!";
		break;
	case 4:
	case 5:
		return "BRAINS!!!! GIVE ME BRAINS NOW!!! I NEED TO EAT BRAINS NOW!!!";
		break;
	default:
		return "Error. Something went wrong.";
		break;
	}
}


string ZombiePirate::toString(void)
{
	string output = Pirate::toString();
	output += ", Brain Hunger: " + brainHunger;
	return output;
}
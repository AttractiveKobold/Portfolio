#include "CaptainPirate.h"

string CaptainPirate::speak(void)
{
	return "Yaaarrr! It be a " + pet + "! \nYaarrr Scallywags! Swab that poop deck!";
}

string CaptainPirate::toString(void)
{
	string output = Pirate::toString();
	output += ", Pet: " + pet;
	return output;
}
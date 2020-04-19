#include "Dice.h"
//Dice Class cpp





Dice Dice::Instance;
void Dice::diceroll()
{
	
	// Calls randomiser function with 0 and 5 as the limits
	Dice::index =(Randomiser(0, 5));
}

// Setter

//Getter
string Dice::getState()
{
    return states[Dice::index];
}

int Dice::getIndex()
{
	return Dice::index;
}

int Dice::getDividor()
{
	return ((int)Dice::states[index].back())-48;
}

Dice& Dice::Get()
{
	return Instance;
}

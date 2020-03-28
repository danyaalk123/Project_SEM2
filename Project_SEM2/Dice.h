#pragma once


#include "Randomiser.h"
#include <string>

using namespace std;


//Dice Class

class Dice
{
private:
	// Enumurated private variable for the possible states the dice can be
	string states[6] = { "White 3", "White 5", "White 7", "Black 3", "Black 5", "Black 6" };
	int index = 0;
		Dice() {};
	~Dice() {};
	static Dice Instance;

public:
	

	//Dice roll fucntion uses random number generator between 0 and 5 to simulate the rolling of a dice
	void diceroll();
	// Setter and Getter for dice state
	string getState();
	int getIndex();
	int getDividor();
	static Dice& Get();
	Dice(const Dice&) = delete;

};


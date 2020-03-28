//Prime number class

#pragma once
#include "Randomiser.h"

//Defines
#define MIN 1
#define MAX 997
class Prime_Number
{
private:

	int Number;

public:

	Prime_Number();
	Prime_Number(int);
	~Prime_Number();
	void SetNumber(int);
	int GetNumber();
	bool CheckPrimeNumber(int);
	int RandomPrimeNumber();
	int DividePrimeNumber(int,int);



};



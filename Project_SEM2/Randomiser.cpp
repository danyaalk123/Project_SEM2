#include "Randomiser.h"


//Random number generator uses the random libary to get closer to true randomisation 
////Code inspired by https://docs.microsoft.com/en-us/cpp/standard-library/random?view=vs-2019
int Randomiser(int lowerbounds, int upperbounds)
{


	std::random_device rd; //Generates a pseudo random number
	std::mt19937 gen(rd()); //Uses previous random number as a seed to generate another random number
	std::uniform_int_distribution<> dist(lowerbounds, upperbounds); // Makes sure the randomom number is inside the bounds

	return dist(gen); // Returns generated number
}

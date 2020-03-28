#include "Prime_Number.h"

Prime_Number::Prime_Number()
{
	this->Number = 0;
}

Prime_Number::Prime_Number(int num)
{
	Prime_Number::Number = num;
}

Prime_Number::~Prime_Number()
{

}

void Prime_Number::SetNumber(int num)
{
	Prime_Number::Number = num;
}

int Prime_Number::GetNumber()
{
	return Prime_Number::Number;
}

bool Prime_Number::CheckPrimeNumber(int num)
{

	for (int i = 2; i <= num / 2; i++) {

		if (num % i == 0) {
			return false;
		}

	}

	if (1 <= num && num <= 997) {
		return true;
	}

	return false;
}

int Prime_Number::RandomPrimeNumber()
{
	int num = 0;
START:
	num = Randomiser(MIN, MAX);

	if (CheckPrimeNumber(num) == 1) {

		return num;
	}
	else {
		goto START;
	}
}

int Prime_Number::DividePrimeNumber(int num1, int num2)
{
	return (num1 % num2);
}

#include "utilityFunction.h"


/*
	randDouble(x, y)

	Preconditions:
	- X and Y must be of type int

	Postconditions:
	- Returns a random value between x and y with a hundredth value added
*/
double randDouble(int x, int y)
{
	int randInt = rand() % (y - x) + x;
	double randHundredth = rand() % 100;
	return randInt + randHundredth / 100;
}

/*
	angleToRadians()

	Postcondition:
	- Returns the angle in radians using 3.14159 as PI 
*/
double angleToRadians(double angle)
{
	return angle * 3.14159 / 180;
}


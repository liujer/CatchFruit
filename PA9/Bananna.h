#ifndef BANANNA_H
#define BANANNA_H

#include "Fruit.h"
#include "utilityFunction.h"
class Bananna : public Fruit
{
private:
	sf::Clock clock;
	bool startFromLeft;
	double rotationTime;
	double rotationAngle;
	double rotationRadius;
public:
	Bananna();
	void setSprite();
	void move();

};

#endif


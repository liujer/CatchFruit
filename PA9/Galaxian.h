#ifndef GALAXIAN_H
#define GALAXIAN_H

#include "Fruit.h"
#include "utilityFunction.h"
class Galaxian : public Fruit
{
private:
	sf::Clock clock;
	bool startFromLeft;
	double rotationTime;
	double rotationAngle;
	double rotationRadius;
public:
	Galaxian();
	void setSprite();
	void move();

};

#endif


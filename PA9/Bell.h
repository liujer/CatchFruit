#ifndef BELL_H
#define BELL_H

#include "Fruit.h"
#include "utilityFunction.h"
class Bell : public Fruit
{
private:
	sf::Clock clock;
	bool startFromLeft;
	double rotationTime;
	double rotationAngle;
	double rotationRadius;
public:
	Bell();
	void setSprite();
	void move();

};

#endif


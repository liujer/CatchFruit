#pragma once
#include "Fruit.h"

class Apple : public Fruit
{
private:
	sf::Clock clock;
	bool curveRight;
public:
	Apple();
	void setSprite();
	void move();

};


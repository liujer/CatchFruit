#pragma once
#include "Fruit.h"

class Strawberry : public Fruit
{
private:
	sf::Clock clock;
	bool curveRight;
public:
	Strawberry();
	void setSprite();
	void move();

};

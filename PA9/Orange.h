#pragma once
#include "Fruit.h"

class Orange : public Fruit
{
private:
	sf::Clock clock;
	bool curveRight;
public:
	Orange();
	void setSprite();
	void move();

};

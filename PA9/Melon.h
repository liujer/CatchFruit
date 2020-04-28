#pragma once
#include "Fruit.h"

class Melon : public Fruit
{
private:
	sf::Clock clock;
	bool curveRight;
public:
	Melon();
	void setSprite();
	void move();

};


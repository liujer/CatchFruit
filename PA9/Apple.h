#pragma once
#include "Fruit.h"
class Apple : public Fruit
{
public:
	Apple(sf::Vector2f position);
	void setSprite();
	void move();

};


#pragma once
#include "Fruit.h"

class Apple : public Fruit
{
private:
	sf::Clock clock;
	bool curveRight;
public:
	Apple(sf::Vector2f position);
	void setSprite();
	void move();
	void restart();

};


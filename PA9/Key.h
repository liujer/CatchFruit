#ifndef KEY_H
#define KEY_H

#include "Fruit.h"

class Key : public Fruit
{
private:
	sf::Clock clock;
	bool curveRight;
public:
	Key();
	void setSprite();
	void move();

};

#endif // !KEY_H
